/********************************************************************************
** Form generated from reading UI file 'TrainModule.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINMODULE_H
#define UI_TRAINMODULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainModule
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpinBox *spinBox_SampleRate;
    QLabel *label_8;
    QLabel *label;
    QSpinBox *spinBox_Do_Duration;
    QLabel *label_2;
    QCheckBox *cbUseRest;
    QSpinBox *spinBox_Rest_Duration;
    QLabel *label_3;
    QGroupBox *groupBox;
    QCheckBox *cbThumb;
    QCheckBox *cbIndex;
    QCheckBox *cbMiddle;
    QCheckBox *cbRing;
    QCheckBox *cbLittle;
    QLineEdit *LEFinger;
    QPushButton *Btn_Add_Finger;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QPushButton *Btn_Add_Wrist;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QRadioButton *rBtn_Shangqie;
    QRadioButton *rBtn_Neifan;
    QRadioButton *rBtn_Neixuan;
    QRadioButton *rBtn_Xiaqie;
    QRadioButton *rBtn_Waifan;
    QRadioButton *rBtn_Waixuan;
    QGroupBox *groupBox_3;
    QPushButton *Btn_Add_Elbow;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QRadioButton *rBtn_Shenzhou;
    QRadioButton *rBtn_Quzhou;
    QTableView *Tb_series;
    QGroupBox *groupBox_4;
    QPushButton *Btn_Save;
    QPushButton *Btn_Import;
    QProgressBar *progressBar;
    QPushButton *Btn_Start;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Btn_Delete_Latest;
    QPushButton *Btn_Clear;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *cbBox_Armband;
    QPushButton *Btn_Armband;
    QLabel *label_6;
    QLineEdit *LE_Armband;
    QPushButton *Btn_DataSave;

    void setupUi(QDialog *TrainModule)
    {
        if (TrainModule->objectName().isEmpty())
            TrainModule->setObjectName(QString::fromUtf8("TrainModule"));
        TrainModule->resize(550, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(TrainModule->sizePolicy().hasHeightForWidth());
        TrainModule->setSizePolicy(sizePolicy);
        TrainModule->setMinimumSize(QSize(550, 600));
        TrainModule->setMaximumSize(QSize(550, 600));
        layoutWidget = new QWidget(TrainModule);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 511, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        spinBox_SampleRate = new QSpinBox(layoutWidget);
        spinBox_SampleRate->setObjectName(QString::fromUtf8("spinBox_SampleRate"));
        spinBox_SampleRate->setMaximum(1000);
        spinBox_SampleRate->setValue(20);

        horizontalLayout->addWidget(spinBox_SampleRate);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox_Do_Duration = new QSpinBox(layoutWidget);
        spinBox_Do_Duration->setObjectName(QString::fromUtf8("spinBox_Do_Duration"));

        horizontalLayout->addWidget(spinBox_Do_Duration);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cbUseRest = new QCheckBox(layoutWidget);
        cbUseRest->setObjectName(QString::fromUtf8("cbUseRest"));

        horizontalLayout->addWidget(cbUseRest);

        spinBox_Rest_Duration = new QSpinBox(layoutWidget);
        spinBox_Rest_Duration->setObjectName(QString::fromUtf8("spinBox_Rest_Duration"));

        horizontalLayout->addWidget(spinBox_Rest_Duration);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        groupBox = new QGroupBox(TrainModule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 281, 101));
        cbThumb = new QCheckBox(groupBox);
        cbThumb->setObjectName(QString::fromUtf8("cbThumb"));
        cbThumb->setGeometry(QRect(20, 20, 71, 16));
        cbIndex = new QCheckBox(groupBox);
        cbIndex->setObjectName(QString::fromUtf8("cbIndex"));
        cbIndex->setGeometry(QRect(110, 20, 71, 16));
        cbMiddle = new QCheckBox(groupBox);
        cbMiddle->setObjectName(QString::fromUtf8("cbMiddle"));
        cbMiddle->setGeometry(QRect(200, 20, 71, 16));
        cbRing = new QCheckBox(groupBox);
        cbRing->setObjectName(QString::fromUtf8("cbRing"));
        cbRing->setGeometry(QRect(20, 40, 91, 16));
        cbLittle = new QCheckBox(groupBox);
        cbLittle->setObjectName(QString::fromUtf8("cbLittle"));
        cbLittle->setGeometry(QRect(110, 40, 71, 16));
        LEFinger = new QLineEdit(groupBox);
        LEFinger->setObjectName(QString::fromUtf8("LEFinger"));
        LEFinger->setGeometry(QRect(80, 70, 113, 20));
        Btn_Add_Finger = new QPushButton(groupBox);
        Btn_Add_Finger->setObjectName(QString::fromUtf8("Btn_Add_Finger"));
        Btn_Add_Finger->setGeometry(QRect(210, 70, 61, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 70, 61, 16));
        groupBox_2 = new QGroupBox(TrainModule);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 180, 281, 71));
        Btn_Add_Wrist = new QPushButton(groupBox_2);
        Btn_Add_Wrist->setObjectName(QString::fromUtf8("Btn_Add_Wrist"));
        Btn_Add_Wrist->setGeometry(QRect(210, 40, 61, 21));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 181, 41));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rBtn_Shangqie = new QRadioButton(layoutWidget1);
        rBtn_Shangqie->setObjectName(QString::fromUtf8("rBtn_Shangqie"));

        gridLayout->addWidget(rBtn_Shangqie, 0, 0, 1, 1);

        rBtn_Neifan = new QRadioButton(layoutWidget1);
        rBtn_Neifan->setObjectName(QString::fromUtf8("rBtn_Neifan"));

        gridLayout->addWidget(rBtn_Neifan, 0, 1, 1, 1);

        rBtn_Neixuan = new QRadioButton(layoutWidget1);
        rBtn_Neixuan->setObjectName(QString::fromUtf8("rBtn_Neixuan"));

        gridLayout->addWidget(rBtn_Neixuan, 0, 2, 1, 1);

        rBtn_Xiaqie = new QRadioButton(layoutWidget1);
        rBtn_Xiaqie->setObjectName(QString::fromUtf8("rBtn_Xiaqie"));

        gridLayout->addWidget(rBtn_Xiaqie, 1, 0, 1, 1);

        rBtn_Waifan = new QRadioButton(layoutWidget1);
        rBtn_Waifan->setObjectName(QString::fromUtf8("rBtn_Waifan"));

        gridLayout->addWidget(rBtn_Waifan, 1, 1, 1, 1);

        rBtn_Waixuan = new QRadioButton(layoutWidget1);
        rBtn_Waixuan->setObjectName(QString::fromUtf8("rBtn_Waixuan"));

        gridLayout->addWidget(rBtn_Waixuan, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(TrainModule);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 260, 281, 51));
        Btn_Add_Elbow = new QPushButton(groupBox_3);
        Btn_Add_Elbow->setObjectName(QString::fromUtf8("Btn_Add_Elbow"));
        Btn_Add_Elbow->setGeometry(QRect(210, 20, 61, 21));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 181, 21));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        rBtn_Shenzhou = new QRadioButton(layoutWidget2);
        rBtn_Shenzhou->setObjectName(QString::fromUtf8("rBtn_Shenzhou"));

        gridLayout_2->addWidget(rBtn_Shenzhou, 0, 0, 1, 1);

        rBtn_Quzhou = new QRadioButton(layoutWidget2);
        rBtn_Quzhou->setObjectName(QString::fromUtf8("rBtn_Quzhou"));

        gridLayout_2->addWidget(rBtn_Quzhou, 0, 1, 1, 1);

        Tb_series = new QTableView(TrainModule);
        Tb_series->setObjectName(QString::fromUtf8("Tb_series"));
        Tb_series->setGeometry(QRect(320, 80, 211, 261));
        groupBox_4 = new QGroupBox(TrainModule);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 330, 281, 61));
        Btn_Save = new QPushButton(groupBox_4);
        Btn_Save->setObjectName(QString::fromUtf8("Btn_Save"));
        Btn_Save->setGeometry(QRect(10, 20, 111, 31));
        Btn_Import = new QPushButton(groupBox_4);
        Btn_Import->setObjectName(QString::fromUtf8("Btn_Import"));
        Btn_Import->setGeometry(QRect(160, 20, 111, 31));
        progressBar = new QProgressBar(TrainModule);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(140, 510, 391, 31));
        progressBar->setValue(0);
        Btn_Start = new QPushButton(TrainModule);
        Btn_Start->setObjectName(QString::fromUtf8("Btn_Start"));
        Btn_Start->setGeometry(QRect(20, 510, 81, 31));
        layoutWidget3 = new QWidget(TrainModule);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(320, 350, 211, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Btn_Delete_Latest = new QPushButton(layoutWidget3);
        Btn_Delete_Latest->setObjectName(QString::fromUtf8("Btn_Delete_Latest"));

        horizontalLayout_2->addWidget(Btn_Delete_Latest);

        Btn_Clear = new QPushButton(layoutWidget3);
        Btn_Clear->setObjectName(QString::fromUtf8("Btn_Clear"));

        horizontalLayout_2->addWidget(Btn_Clear);

        groupBox_5 = new QGroupBox(TrainModule);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 410, 511, 81));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        cbBox_Armband = new QComboBox(groupBox_5);
        cbBox_Armband->setObjectName(QString::fromUtf8("cbBox_Armband"));

        horizontalLayout_3->addWidget(cbBox_Armband);

        Btn_Armband = new QPushButton(groupBox_5);
        Btn_Armband->setObjectName(QString::fromUtf8("Btn_Armband"));

        horizontalLayout_3->addWidget(Btn_Armband);

        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        LE_Armband = new QLineEdit(groupBox_5);
        LE_Armband->setObjectName(QString::fromUtf8("LE_Armband"));
        LE_Armband->setReadOnly(true);

        horizontalLayout_3->addWidget(LE_Armband);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        Btn_DataSave = new QPushButton(TrainModule);
        Btn_DataSave->setObjectName(QString::fromUtf8("Btn_DataSave"));
        Btn_DataSave->setGeometry(QRect(20, 560, 81, 31));

        retranslateUi(TrainModule);

        QMetaObject::connectSlotsByName(TrainModule);
    } // setupUi

    void retranslateUi(QDialog *TrainModule)
    {
        TrainModule->setWindowTitle(QApplication::translate("TrainModule", "TrainModule", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TrainModule", "\351\207\207\346\240\267\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TrainModule", "Hz", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TrainModule", "\345\212\250\344\275\234\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TrainModule", "\347\247\222", 0, QApplication::UnicodeUTF8));
        cbUseRest->setText(QApplication::translate("TrainModule", "\344\275\277\347\224\250\344\274\221\346\201\257\346\200\201\344\275\234\344\270\272\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TrainModule", "\347\247\222", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TrainModule", "\346\211\213\345\212\277\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8));
        cbThumb->setText(QApplication::translate("TrainModule", "\345\274\257\346\233\262\346\213\207\346\214\207", 0, QApplication::UnicodeUTF8));
        cbIndex->setText(QApplication::translate("TrainModule", "\345\274\257\346\233\262\351\243\237\346\214\207", 0, QApplication::UnicodeUTF8));
        cbMiddle->setText(QApplication::translate("TrainModule", "\345\274\257\346\233\262\344\270\255\346\214\207", 0, QApplication::UnicodeUTF8));
        cbRing->setText(QApplication::translate("TrainModule", "\345\274\257\346\233\262\346\227\240\345\220\215\346\214\207", 0, QApplication::UnicodeUTF8));
        cbLittle->setText(QApplication::translate("TrainModule", "\345\274\257\346\233\262\345\260\217\346\214\207", 0, QApplication::UnicodeUTF8));
        Btn_Add_Finger->setText(QApplication::translate("TrainModule", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TrainModule", "\345\212\250\344\275\234\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("TrainModule", "\346\211\213\350\205\225\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8));
        Btn_Add_Wrist->setText(QApplication::translate("TrainModule", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        rBtn_Shangqie->setText(QApplication::translate("TrainModule", "\344\270\212\345\210\207", 0, QApplication::UnicodeUTF8));
        rBtn_Neifan->setText(QApplication::translate("TrainModule", "\345\206\205\347\277\273", 0, QApplication::UnicodeUTF8));
        rBtn_Neixuan->setText(QApplication::translate("TrainModule", "\345\206\205\346\227\213", 0, QApplication::UnicodeUTF8));
        rBtn_Xiaqie->setText(QApplication::translate("TrainModule", "\344\270\213\345\210\207", 0, QApplication::UnicodeUTF8));
        rBtn_Waifan->setText(QApplication::translate("TrainModule", "\345\244\226\347\277\273", 0, QApplication::UnicodeUTF8));
        rBtn_Waixuan->setText(QApplication::translate("TrainModule", "\345\244\226\346\227\213", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("TrainModule", "\346\211\213\350\202\230\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8));
        Btn_Add_Elbow->setText(QApplication::translate("TrainModule", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        rBtn_Shenzhou->setText(QApplication::translate("TrainModule", "\344\274\270\350\202\230", 0, QApplication::UnicodeUTF8));
        rBtn_Quzhou->setText(QApplication::translate("TrainModule", "\345\261\210\350\202\230", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("TrainModule", "\350\256\255\347\273\203\345\272\217\345\210\227\346\226\207\344\273\266\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        Btn_Save->setText(QApplication::translate("TrainModule", "\344\277\235\345\255\230\345\275\223\345\211\215\345\272\217\345\210\227...", 0, QApplication::UnicodeUTF8));
        Btn_Import->setText(QApplication::translate("TrainModule", "\345\257\274\345\205\245\345\216\237\346\234\211\345\272\217\345\210\227...", 0, QApplication::UnicodeUTF8));
        Btn_Start->setText(QApplication::translate("TrainModule", "\345\274\200\345\247\213\350\256\255\347\273\203", 0, QApplication::UnicodeUTF8));
        Btn_Delete_Latest->setText(QApplication::translate("TrainModule", "\345\210\240\351\231\244\346\234\200\346\226\260", 0, QApplication::UnicodeUTF8));
        Btn_Clear->setText(QApplication::translate("TrainModule", "\346\270\205\351\231\244\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("TrainModule", "\350\202\214\347\224\265\350\207\202\345\270\246\350\277\236\346\216\245\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TrainModule", "\344\270\262\345\217\243\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        cbBox_Armband->clear();
        cbBox_Armband->insertItems(0, QStringList()
         << QApplication::translate("TrainModule", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TrainModule", "COM10", 0, QApplication::UnicodeUTF8)
        );
        Btn_Armband->setText(QApplication::translate("TrainModule", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TrainModule", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        Btn_DataSave->setText(QApplication::translate("TrainModule", "\346\225\260\346\215\256\344\277\235\345\255\230...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrainModule: public Ui_TrainModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINMODULE_H
