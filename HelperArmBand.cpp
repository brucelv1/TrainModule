#include "HelperArmBand.h"
#include <iostream>

/*******************************************
��̬ȫ�ֺ���: BEGIN
********************************************/
// Ĭ��ʹ�õ����ݸ����߳�
static DWORD WINAPI DataThreadEntry_EMG(PVOID arg) 
{
	((SJTArmBand *)arg)->OpenSerial();
	while(((SJTArmBand *)arg)->thread_state!=END)
	{
		if(((SJTArmBand *)arg)->mSerialSuccessful)
			((SJTArmBand *)arg)->SendData_EMG();
		else
			((SJTArmBand *)arg)->thread_state=END;
	}
	((SJTArmBand *)arg)->CloseSerial();
	return 0;
}
/*******************************************
��̬ȫ�ֺ���: END
********************************************/

/*******************************************
CFilter: BEGIN
********************************************/
CFilter::CFilter(FilterType type/*=COMB*/)
{
	filter_index=-1;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<8;j++)
		{
			data_src[i][j]=0;
			data_filter[i][j]=0;
		}
	}
	for(int i=0;i<100;i++)
	{
		filter_a[i]=0;
		filter_b[i]=0;
	}


	switch(type)
	{
	case HIGH_PASS:
		filter_n=4;
		filter_a[0]=1.000000000000000;
		filter_a[1]= -3.917907865391987;
		filter_a[2]=5.757076379118066;
		filter_a[3]=-3.760349507694526;
		filter_a[4]=0.921181929191236;

		filter_b[0]=0.959782230087239;
		filter_b[1]= -3.839128920348954;
		filter_b[2]= 5.758693380523431;
		filter_b[3]=-3.839128920348954;
		filter_b[4]=0.959782230087239;
		break;
	case NOTCH:
		//Fs = 1000;      % Sampling Frequency
		//Fnotch = 50;    % Notch Frequency
		//BW     = 2;     % Bandwidth
		//Apass  = 20;    % Bandwidth Attenuation
		//[filter_b, filter_a] = iirnotch(Fnotch/(Fs/2), BW/(Fs/2), Apass);
		filter_n=2;
		filter_a[0]=1.000000000000000;
		filter_a[1]=-1.790194162384630;
		filter_a[2]=0.882321535799305;
		filter_b[0]=0.941160767899653;
		filter_b[1]=-1.790194162384630;
		filter_b[2]=0.941160767899653;
		break;
	case COMB:
		//filt_n=20;
		//fs = 1000; fo = 50;  q = 35; bw = (fo/(fs/2))/q;
		//[filter_b, filter_a]= iircomb(fs/fo,bw,'notch');
		filter_n=20;
		filter_a[0]=1.000000000000000;
		filter_a[20]=-0.809784033195007;
		filter_b[0]=0.904892016597504;
		filter_b[20]=-0.904892016597504;
		break;
	}		
}

double CFilter::DoFilter(double temp)
{
	filter_index=(filter_index+1)%8;    // filter_index=-1; initialized in ctor
	for(int i=0;i<filter_n;i++)         // filter_n=20; initialized in ctor
	{
		data_src[filter_n-i][filter_index]=data_src[filter_n-i-1][filter_index];
		data_filter[filter_n-i][filter_index]=data_filter[filter_n-i-1][filter_index];
	}
	data_src[0][filter_index]=temp;
	data_filter[0][filter_index]=0;
	for(int i=0;i<filter_n+1;i++)
		data_filter[0][filter_index]+=filter_b[i]*data_src[i][filter_index];
	for(int i=1;i<filter_n+1;i++)
		data_filter[0][filter_index]-=filter_a[i]*data_filter[i][filter_index];
	return data_filter[0][filter_index];
}
/*******************************************
CFilter: END
********************************************/


/*******************************************
SJTArmBand: BEGIN
********************************************/
SJTArmBand::SJTArmBand(int nChannel/*=8*/, DeviceType dt/*=EMG*/)
	: DATA_CHANNEL(nChannel)
	, mDevice(dt)
	, data_buff(nullptr)
{
	// ���ݸ�ʽ��8ͨ����ǰ4����EMG�źţ���4����NIR�ź�
	data_buff = new double[DATA_CHANNEL]();

	// �������ݽ�����أ�����״̬
	data_cnt_state = 0;

	// ��ʼ�����ⲿ���ʵ���������
	_mDataReadyToUse.resize(DATA_CHANNEL,0);

	// ��ʼ���ٽ����ṹ��
	InitializeCriticalSection(&_mCriticalSection);
}

SJTArmBand::~SJTArmBand()
{
	delete [] data_buff;
	data_buff = nullptr;
	switch (mDevice)
	{
		case EMG_NIR:
			thread_state=END;
			Sleep(100);
			break;

		case EMG:
			thread_state=END;
			Sleep(100);
			break;
	}
}

//void SJTArmBand::OpenSerial(int nCOM/*=5*/, int Baudrate/*=57600*/)
void SJTArmBand::OpenSerial()
{
	mSerialSuccessful=true;
	char	tmpCOM[100];
	sprintf_s(tmpCOM,"\\\\.\\COM%d",nCOM); // tmpCOM="\\.\COM5"

	// ��char* ת��ΪLPWSTR
	wchar_t wtext[100];
	std::mbstowcs(wtext, tmpCOM, strlen(tmpCOM)+1);//Plus null
	LPWSTR COM_NUM = wtext;

	//��5�δ򿪴��ڵĳ���
	for(int i=0;i<5;i++)
	{
		hCom =::CreateFile(COM_NUM,
			GENERIC_READ|GENERIC_WRITE, 
			0,
			0,
			OPEN_EXISTING,
			0,//FILE_FLAG_OVERLAPPED,
			0
			);
		if(hCom ==INVALID_HANDLE_VALUE)
		{
			::CloseHandle(hCom);
			mSerialSuccessful=false;
		}
		else
		{
			mSerialSuccessful=true;
			break;
		}
	}
	if(mSerialSuccessful&&!::SetupComm(hCom, 32000, 32000))
	{
		::CloseHandle(hCom);
		mSerialSuccessful=false;
	}

	COMMTIMEOUTS CommTimeOuts;// set up for overlapped I/O
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 0;		
	if(mSerialSuccessful&&!::SetCommTimeouts(hCom, &CommTimeOuts))
	{
		::CloseHandle(hCom);
		mSerialSuccessful=false;
	}
	if(mSerialSuccessful&&!::SetCommMask(hCom, 0))
	{
		::CloseHandle(hCom);
		mSerialSuccessful=false;
	}

	DCB dcb={0};
	if(mSerialSuccessful)
	{
		dcb.DCBlength = sizeof(DCB);
		if(!::GetCommState(hCom,&dcb))
			mSerialSuccessful=false;
	}
	if(mSerialSuccessful)
	{
		dcb.BaudRate = Baudrate;
		dcb.ByteSize = 8;
		dcb.Parity = NOPARITY;
		dcb.StopBits =ONESTOPBIT;
		if(!::SetCommState(hCom,&dcb))
			mSerialSuccessful=false;
	}
	if( mSerialSuccessful&&!::PurgeComm( hCom, PURGE_TXABORT|PURGE_RXABORT| PURGE_TXCLEAR|PURGE_RXCLEAR ) )
		mSerialSuccessful=false;
}

void SJTArmBand::CloseSerial()
{
	if(mSerialSuccessful)
	{
		::PurgeComm(hCom, PURGE_TXABORT|PURGE_RXABORT| PURGE_TXCLEAR|PURGE_RXCLEAR);
		::CloseHandle(hCom);
		mSerialSuccessful=false;
	}
}

bool SJTArmBand::Connect(int _nCOM/*=5*/, int _BaudRate/*=57600*/)
{
	this->nCOM = _nCOM;
	this->Baudrate = _BaudRate;

	switch (mDevice)
	{
	case EMG_NIR:
		thread_state=REST;
		//m_hThread=CreateThread(NULL,0,DataThreadEntry,(PVOID)this,0,NULL);
		break;

	case EMG:
		thread_state=REST;
		m_hThread=CreateThread(NULL,0,DataThreadEntry_EMG,(PVOID)this,0,NULL);
		break;

	default:
		std::cout << "Unknown DeviceType!" << std::endl;
		return false;
	}

	if (m_hThread == INVALID_HANDLE_VALUE)
	{
		std::cout << "Device Connect Failed!" << std::endl;
		return false;
	}
	else
		return true;
}

bool SJTArmBand::SendData_EMG()
{
	DWORD BytesRead;                               // the number of bytes that have been read
	::ReadFile(hCom,buff,3000,&BytesRead,NULL);    //LB//���ļ�ָ��ָ���λ�ÿ�ʼ�����ݶ�����һ���ļ���,buffΪ����������ݵĻ�������3000Ҫ������ֽ�����
	for(DWORD index=0; index<BytesRead; index++)       
	{
		switch(data_cnt_state)              //LB//����״̬
		{
		case 0:
			if(buff[index]==0x55)           //LB//��മ��ͨѶ�в��Ի������ź�ʹ��AA��55�����������ʮ��������
				data_cnt_state++;           
			break;
		case 1:
			if(buff[index]==0xAA)           //LB//AAչ��Ϊ10101010,55չ��Ϊ01010101,��ɴ��е�ƽ�Ļ�����һ��ռ�ձ�Ϊ50%�ķ���
			{                               //LB//���ַ����ڵ�·�������ױ��ֱ��Ƿ��ܸ��Ż��߻��䣬��ʵ�ʲ��εĹ۲���Ҳ�����׿���ë������
				data_cnt_state++;
				data_cnt_count=0;           //LB//���ݼ���
				data_cnt_max=16;
				data_cnt_check=0;           //LB//����У��
			}
			else
				data_cnt_state=0;
			break;
		case 2:
			data_cnt_check+=buff[index];
			if(data_cnt_count%2==0)//ÿ�������ݴ洢һ�Σ�һ�����ݷָߵ����ֽڴ��䣩
				data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]=double(buff[index]*256);//LB//�߰�λ�洢,��256��ԭ    %��/ͬ������������
			else
			{
				data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]+=double(buff[index]); //LB//�Ͱ�λ�洢����߰�λ���������
				if(data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]>=65534/2)   //LB//2^16=65536  
					data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]-=65535;
				data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]=mFilter.DoFilter(data_buff[data_cnt_count%(DATA_CHANNEL*2)/2]);
			}
			data_cnt_count++;
			if(data_cnt_count==data_cnt_max)
				data_cnt_state++;
			break;
		case 3:
			if(data_cnt_check%256==buff[index])    //У����ȷ����ִ�мȶ��߼����������ݶ���
			{
				EnterCriticalSection(&_mCriticalSection);
				for (int i=0; i<DATA_CHANNEL; i++)
				{
					_mDataReadyToUse[i] = data_buff[i];
				}
				LeaveCriticalSection(&_mCriticalSection);
			}
			data_cnt_state=0;
			break;
		}
	}
	Sleep(1);//LB//"Ŀ�Ĳ���Ҫ�ﵽ1�����룬ֻ����������CPU��ʱ��ȥ���������̽��е��ȶ��ѣ�����Ҫ��CPU�����ʱ�����ռ�õ�100%"
	return false;
}

std::vector<double> SJTArmBand::GetDataVector()
{
	return _mDataReadyToUse;
}

/*******************************************
SJTArmBand: END
********************************************/
