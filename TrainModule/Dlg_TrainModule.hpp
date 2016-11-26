#ifndef _DLG_TRAIN_MODULE_H_
#define _DLG_TRAIN_MODULE_H_ 1

#include <QtGui/QDialog>
#include "GUI/ui_TrainModule.h"
#include <iostream>
#include <vector>
#include <QtGui/QAbstractItemView>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtCore/QString>
#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "SerialPort.h"
#include <boost/thread.hpp>
#include <QtCore/QTimer>

class Dlg_TrainModule : public QDialog, public Ui_TrainModule
{
	Q_OBJECT
private:
	// use int to store command
	// 0: rest
	// 1: thumb, 2: index, 4: middle, 8: ring, 16: little
	// 32: shangqie, 64: xiaqie
	// 128: neifan, 256: waifan
	// 512: neixuan, 1024: waixuan
	// 2048: shenzhou, 4096: quzhou
	class _commandInfo
	{
	public:
		std::string Name;
		int         Command;
		size_t      Duration;
		_commandInfo() : Name(""), Command(0), Duration(0) {}
	};
	
	std::vector< std::shared_ptr<_commandInfo> > _commandVec;

	// Table model
	QStandardItemModel* _tableModel;

	// Serial Port
	CSerialPort* _mSerialPort;

	// Sending thread
	boost::thread _mThread;

	// Shared memory
	unsigned char* _ucpNameSharedMem;
	size_t _stLenSharedMem;

	// Timer, for processing bar
	QTimer* qTimer;
	int processingBarVal;

public:
	Dlg_TrainModule(unsigned char* nameSharedMem, size_t lenSharedMem, QWidget* parent=NULL)
		: QDialog(parent)
		, _tableModel(new QStandardItemModel(this))
		, _mSerialPort(nullptr)
		, _ucpNameSharedMem(nameSharedMem)
		, _stLenSharedMem(lenSharedMem)
	{
		setupUi(this);
		_initTableView();
		qTimer = new QTimer(this);
		connect(qTimer, SIGNAL(timeout()), this, SLOT(qTimer_timeout()));

		/*int nCOM = atoi(charCOM);
		if(nCOM!=0)
		{
			_mSerialPort = new CSerialPort();
			if(_mSerialPort->InitPort(nCOM))
			{
				printf("TrainModule: COM%d initialization successful !\n",nCOM);

				if(_mSerialPort->OpenListenThread())
					printf("TrainModule: Open ListenThread successful !\n");
				else
					printf("TrainModule: Open ListenThread failed !\n");
			}
			else
				printf("TrainModule: COM%d initialization failed !\n",nCOM);
		}*/
	}

	~Dlg_TrainModule() 
	{
		_mThread.join();
	}

	static void ThreadSend(Dlg_TrainModule* dtm)
	{
		using namespace boost::chrono;

		// timing
		duration<double> time_span;
		steady_clock::time_point t1, t2;
		// counting
		int progress = 0;
		int total_num = dtm->_commandVec.size();
		std::vector< std::shared_ptr<_commandInfo> >::iterator it;		
		for (it=dtm->_commandVec.begin(); it!=dtm->_commandVec.end(); it++)
		{
			t1 = steady_clock::now();
			int dura = (*it)->Duration;
			int command = (*it)->Command;
			unsigned char byte0 = command % 256;
			unsigned char byte1 = (command >> 8) % 256;
			unsigned char byte2 = 0; // not used yet
			unsigned char byte3 = 0; // not used yet

			// set command
			dtm->_ucpNameSharedMem[4] = byte0;
			dtm->_ucpNameSharedMem[3] = byte1;
			dtm->_ucpNameSharedMem[2] = byte2; // not used yet
			dtm->_ucpNameSharedMem[1] = byte3; // not used yet

			// wait for duration
			do 
			{
				/*if((*it)->Name == "Rest")
					dtm->_mSerialPort->WriteData(&cmd[2],1);
				else
					dtm->_mSerialPort->WriteData(&cmd[0],1);*/

				boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
				t2 = steady_clock::now();
				time_span = duration_cast<duration<double> > (t2-t1);
			} while (time_span.count()<dura);

			progress+=1;
			dtm->processingBarVal = 100*progress/total_num;
		}
		return;
	}

private:
	void _initTableView()
	{
		_tableModel->setHorizontalHeaderItem(0,new QStandardItem("Name"));
		_tableModel->setHorizontalHeaderItem(1,new QStandardItem("Duration"));

		// bind the model with the view
		Tb_series->setModel(_tableModel);

		// set read-only
		Tb_series->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}

	void _updateTableView()
	{
		// then fill the table
		for (size_t i=0; i<_commandVec.size(); i++)
		{		
			QString name = _commandVec[i]->Name.c_str();
			_tableModel->setItem(i,0,new QStandardItem(name));

			char tmp[10];
			sprintf_s(tmp,"%d",_commandVec[i]->Duration);
			QString dura = QString(tmp);
			dura += " seconds";
			_tableModel->setItem(i,1,new QStandardItem(dura));
		}
	}

	void _clearTableView()
	{
		int nRow = _tableModel->rowCount();
		for (int i=nRow-1;i>=0;i--)
		{
			_tableModel->removeRow(i);
		}
	}

	void _addAction(std::string& name, int command)
	{
		std::shared_ptr<_commandInfo> action(new _commandInfo());
		action->Name=name;
		action->Command=command;
		action->Duration=spinBox_Do_Duration->value();
		_commandVec.push_back(action);

		if(cbUseRest->isChecked())
		{
			std::shared_ptr<_commandInfo> rest(new _commandInfo());
			rest->Name="Rest";
			rest->Command=0;
			rest->Duration=spinBox_Rest_Duration->value();
			_commandVec.push_back(rest);
		}
	}

public slots:
	void on_Btn_Add_Finger_clicked()
	{
		std::string name = LEFinger->text().toStdString();
		if (name == "Rest")
		{
			QMessageBox::information(NULL, "Information", "You cannot use the name 'Rest'.", QMessageBox::Ok);
			return;
		}

		// int command
		// 1: thumb, 2: index, 4: middle, 8: ring, 16: little
		int command = 0;
		if(cbThumb->isChecked())
			command+=(1<<0);
		if(cbIndex->isChecked())
			command+=(1<<1);
		if(cbMiddle->isChecked())
			command+=(1<<2);
		if(cbRing->isChecked())
			command+=(1<<3);
		if(cbLittle->isChecked())
			command+=(1<<4);

		_addAction(name,command);

		_updateTableView();
	}

	void on_Btn_Add_Wrist_clicked()
	{
		// int command
		// 32: shangqie, 64: xiaqie
		// 128: neifan, 256: waifan
		// 512: neixuan, 1024: waixuan
		std::string name = "";
		int command = 0;

		if(rBtn_Shangqie->isChecked())
		{
			name = "Shang Qie";
			command = (1<<5);
		}
		else if (rBtn_Xiaqie->isChecked())
		{
			name = "Xia Qie";
			command = (1<<6);
		}
		else if (rBtn_Neifan->isChecked())
		{
			name = "Nei Fan";
			command = (1<<7);
		}
		else if (rBtn_Waifan->isChecked())
		{
			name = "Wai Fan";
			command = (1<<8);
		}
		else if (rBtn_Neixuan->isChecked())
		{
			name = "Nei Xuan";
			command = (1<<9);
		}
		else if (rBtn_Waixuan->isChecked())
		{
			name = "Wai Xuan";
			command = (1<<10);
		}
		else
			return;

		_addAction(name,command);
		_updateTableView();
	}

	void on_Btn_Add_Elbow_clicked()
	{
		// int command
		// 2048: shenzhou, 4096: quzhou
		std::string name = "";
		int command = 0;

		if (rBtn_Shenzhou->isChecked())
		{
			name = "Shen Zhou";
			command = (1<<11);
		}
		else if (rBtn_Quzhou->isChecked())
		{
			name = "Qu Zhou";
			command = (1<<12);
		}
		else
			return;

		_addAction(name, command);
		_updateTableView();
	}

	void on_Btn_Save_clicked()
	{
		QString fileName = QFileDialog::getSaveFileName(this,
			tr("Save Config"),
			"",
			tr("Config Files (*.json)")
			);

		if (!fileName.isNull())
		{
			//fileName是文件名
			using namespace boost::property_tree;
			ptree root;

			root.put<std::string>("type", "Training Series");

			ptree Actions;
			for (size_t i=0; i<_commandVec.size(); i++)
			{
				std::string name = _commandVec[i]->Name;
				int command = _commandVec[i]->Command;
				size_t dura = _commandVec[i]->Duration;

				ptree _action;
				_action.put<int>("num", i+1);
				_action.push_back(std::make_pair("name",name));
				_action.put<int>("command",command);
				_action.put<int>("duration",dura);

				Actions.push_back(std::make_pair("",_action));
			}
			root.add_child("actions",Actions);

			write_json(fileName.toStdString(), root);
		}
		else
		{
			return;
		}
	}

	void on_Btn_Import_clicked()
	{
		QString filename = QFileDialog::getOpenFileName(this,
			tr("Open File"), 
			"",
			"", 
			0);
		if (!filename.isNull())
		{
			//fileName是文件名
			using namespace boost::property_tree;
			ptree root;

			try
			{
				// load the json file in this ptree
				read_json(filename.toStdString(),root);
			}
			catch (json_parser::json_parser_error& e)
			{
				std::cout << "Error: Invalid JSON file!" << std::endl;
				std::cout << "[Info] " << e.what() << std::endl;
				system("pause");
				return;
			}

			std::string _type = root.get<std::string>("type","");
			if(_type != "Training Series")
			{
				QMessageBox::warning(NULL, "warning", "Invalid configuration file.", QMessageBox::Ok);
				return;
			}

			ptree Actions = root.get_child("actions");
			std::vector< std::shared_ptr<_commandInfo> > InfoVec;
			for (ptree::iterator it=Actions.begin(); it!=Actions.end(); it++)
			{
				std::string name = it->second.get<std::string>("name");
				int command = it->second.get<int>("command");
				size_t dura = it->second.get<size_t>("duration");
				std::shared_ptr<_commandInfo> cinfo(new _commandInfo());
				cinfo->Name = name;
				cinfo->Command = command;
				cinfo->Duration = dura;
				InfoVec.push_back(cinfo);
			}

			_commandVec.clear();
			_commandVec = InfoVec;
		}
		else{
			//点的是取消
			return;
		}
		_updateTableView();
	}

	void on_Btn_Start_clicked()
	{
		processingBarVal = 0;
		if(qTimer->isActive())
			qTimer->stop();
		qTimer->start(200);
		_mThread = boost::thread(boost::bind(&(Dlg_TrainModule::ThreadSend),this));
	}

	void on_Btn_Delete_Latest_clicked()
	{
		int len = _commandVec.size();
		if(len==0)
			return;

		if(_commandVec[len-1]->Name=="Rest")
		{
			// Pop the "Rest" one
			_commandVec.pop_back();
			// Pop the latest action
			_commandVec.pop_back();
		}
		else
			_commandVec.pop_back();

		_clearTableView();
		_updateTableView();
	}

	void on_Btn_Clear_clicked()
	{
		_commandVec.clear();
		_clearTableView();
	}

	void qTimer_timeout()
	{
		progressBar->setValue(processingBarVal);
	}
};

#endif // _DLG_TRAIN_MODULE_H_