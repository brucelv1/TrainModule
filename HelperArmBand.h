/*************************************************
Copyright:
Author:
Date:2013-08-17
Description:������CFilter��SJTArmBand�࣬��ɴӴ��ڶ����ݡ��˲�����
**************************************************/
#pragma once
#include <Windows.h>
#include <vector>

// EMG�۴����������̣߳��򿪴��ڡ��������ݡ��رմ��ڵĶ�����
static DWORD WINAPI DataThreadEntry_EMG(PVOID arg);

enum STATE {REST=1,START,END};

/*******************************************
�����ƣ�CFilter
��    �ܣ������������˲�������ͨ���ݲ�����״�˲�����������ʹ������״�˲��������������˲�����
********************************************/
class  CFilter
{
public:
	enum FilterType {HIGH_PASS=1,NOTCH,COMB};
	int					filter_n;
	double				data_src[100][8];
	double				data_filter[100][8];
	double				filter_a[100];
	double				filter_b[100];
	int					filter_index;

	CFilter(FilterType type=COMB);
	
/*******************************************
�������ƣ�DoFilter
��    �ܣ��˲��������˲������㷨��y(n) = b(1)*x(n) + b(2)*x(n-1) + ... + b(nb+1)*x(n-nb)- a(2)*y(n-1) - ... - a(na+1)*y(n-na)//LB//һά�����˲�����ͬMatlab filter
��    ������       
����ֵ  ����
********************************************/
	double DoFilter(double temp);
	
};

/*******************************************
�����ƣ�SJTArmBand
��    �ܣ��򿪴��ڣ���ȡ���ڴ�����������ݡ��˲�
********************************************/
class  SJTArmBand
{
public:
	enum DeviceType {EMG_NIR=1,EMG};
	int					thread_state;
	bool				mSerialSuccessful;

private:
	DeviceType          mDevice;
	HANDLE				hCom;
	HANDLE				m_hThread;
	
	unsigned char		buff[8192];         //LB//8192=2^13    unsigned char 0~255 2^8
	const int           DATA_CHANNEL;      
	double*				data_buff;          //ͨ�����ݻ�����,�ڹ��캯���г�ʼ��
	int					data_cnt_state;		//����״̬
	int					data_cnt_count;		//���ݼ���
	int					data_cnt_max;		//���ݼ���
	int					data_cnt_check;		//����У��
	std::vector<double> _mDataReadyToUse;

	CFilter				mFilter;

	CRITICAL_SECTION    _mCriticalSection;

	// Serial port
	int nCOM;
	int Baudrate;

public:
	SJTArmBand(int nChannel=8, DeviceType dt=EMG);	
	~SJTArmBand();

	// ���ڲ���
	//void OpenSerial(int nCOM=5, int Baudrate=57600);
	void OpenSerial();
	void CloseSerial();
	
	bool Connect(int _nCOM=5, int _BaudRate=57600);
	bool IsConnected()
	{
		return mSerialSuccessful;
	}
	
	/*******************************************
	�������ƣ�SendData_EMG
	��    �ܣ���ȡEMG�۴��������ݣ��˲���У�顢�洢����
	��    ������       
	����ֵ  ����
	********************************************/	
	bool SendData_EMG();

	std::vector<double> GetDataVector(); 
};

