// InkJet_Base.h: interface for the CInkJet_Base class.
//
//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// �Լ��� ���� ���� ������ ��� "sRtn"�� error message�� ���ԵǾ� ���ϵ˴ϴ�.
/// �Լ��� ���� ���� �ϴ� ��쿡�� "0" �Ǵ� "0.0"�� ���� �� ��� error message�� ���ԵǾ� ���ϵ˴ϴ�.
/// �������� ���ϰ��� "0" �Ǵ� "0.0"�� ��� "Non Error"��� message�� ���Ե˴ϴ�.
/// �Ÿ��� �Է������ um ���� �̸�, �Ҽ��� ����� ��� ��ȿ ���ڴ� �Ҽ��� ���� 1�ڸ� �Դϴ�.
/// ������ �Լ� ���� ���� �������� �����Ƿ� ���� ������ ������ �ݵ�� �����ֽñ� �ٶ��ϴ�.
/// Data�� ������ HD_TYPE_SPECTRA_1,2 : 128��, HD_TYPE_TRIDENT_1 : 256���Դϴ�.
/// Trident Head ��� �� DSP ���� �Լ��� ������� ������
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INKJET_BASE_H
#define INKJET_BASE_H

#if !defined(AFX_INKJET_BASE_H__F74BE705_A71C_4B43_A406_AA93046D8567__INCLUDED_)
#define AFX_INKJET_BASE_H__F74BE705_A71C_4B43_A406_AA93046D8567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef HD_TYPE 
#define HD_TYPE
#define HD_TYPE_SPECTRA_1	1 // PTM/PPM/Spectra 128 Head controller �ִ� type : C/F ���
#define HD_TYPE_TRIDENT_1	2 // PTM/Trident 256 Head controller �ְ�, PPM ���� Type: Trident head Type (G���, Test)
#define HD_TYPE_SPECTRA_2	3 // PTM/Spectra 128 Head�� �ְ�, DSP���� Head type���� ���� : EPD ���
#define HD_TYPE_SPECTRA_3	4 // Spectra 128 Head controller�� �ְ�, PTM/PPM ���� Type : ��ӿ��Ŀ�
#define HD_TYPE_NOVA_1		10 // PTM/Nova 256 Head�� �ְ�, PPM ���� Type : nozzle 256��, ������ ���� ����-> ���е�����128��*0.125us = 16us
#define HD_TYPE_NOVA_2		11 // Nova 256 Head�� �ְ�, PTM/PPM���� Type : Nova Head Drop watcher��, ��
#define HD_TYPE_NOVA_512_1	20 // PTM/Nova nozzle 512��, PPM ���� Type : ������ ���� ����-> ���е�����128��*0.125us = 16us
#define HD_TYPE_NOVA_512_2	21 // PTM/Nova nozzle 512��, PPM ���� Type : Nova Head Drop watcher��, ��
#define HD_TYPE_Q_CLASS_512_1	30 // Q-class nozzle 512��, ������ ���� ����-> ���е�����128��*0.125us = 16us <== Nova512�� ����
#define HD_TYPE_Q_CLASS_512_2	31 // Q-class Head Drop watcher�� �߰�. nozzle 512��, ������ ���� ����-> ���е�����128��*0.125us = 16us
#endif //HD_TYPE

// image download type ���� �߰�.
#ifndef IMG_DN_TYPE
#define IMG_DN_TYPE
#define IMG_DN_TYPE_PITCHSET	0x0001
#define IMG_DN_TYPE_SLANT		0x0002
#define IMG_DN_TYPE_DIRECT		0x2000	// 100723 edited by wonho, �̹��� ó������ �ٷ� �ٿ�ε��ϱ�.

#define IMG_DN_TYPE_BYTE_IMG_PITCHSET			0x0001
#define IMG_DN_TYPE_BYTE_IMG_SLANT				0x0002
#define IMG_DN_TYPE_BYTE_IMG_PITCHSET_FILE		0x1001	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
#define IMG_DN_TYPE_BYTE_IMG_SLANT_FILE			0x1002	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.

#define IMG_DN_TYPE_BIT_IMG_PITCHSET			0x0101
#define IMG_DN_TYPE_BIT_IMG_SLANT				0x0102
#define IMG_DN_TYPE_BIT_IMG_PITCHSET_FILE		0x1101	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
#define IMG_DN_TYPE_BIT_IMG_SLANT_FILE			0x1102	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.

#define PITCHSET_IMG_DN_FLAG	0x0001
#define SLANT_IMG_DN_FLAG		0x0002
#define BIT_IMG_DN_FLAG			0x0100
#define FILE_SAVE_IMG_DN_FLAG	0x1000	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
#define	DIRECT_DN_IMG_DN_FLAG	0x2000	// 100723 edited by wonho, �̹��� ó������ �ٷ� �ٿ�ε��ϱ�.
#endif // #ifndef IMG_DN_TYPE

// image jet type ����.
#ifndef HD_JET_TYPE
#define HD_JET_TYPE
#define HD_JET_TYPE_STOP								0xf000

#define HD_JET_TYPE_IMAGE_FORWARD						0x0000
#define HD_JET_TYPE_IMAGE_BACKWARD						0x0001
#define HD_JET_TYPE_IMAGE_FORWARD_NOT_VARIATION			0x0010
#define HD_JET_TYPE_IMAGE_BACKWARD_NOT_VARIATION		0x0011

#define HD_JET_TYPE_TIMER_IMAGE_FORWARD					0x0004
#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD				0x0005
#define HD_JET_TYPE_TIMER_IMAGE_FORWARD_NOT_VARIATION	0x0014
#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD_NOT_VARIATION	0x0015

#define HD_JET_TYPE_NOZZLE_TEST							0x0046
#define HD_JET_TYPE_NOZZLE_TEST_SET_DROP_CNT			0x0066

#define HD_JET_TYPE_DROPWATCHER							0x000a

#define DIRECTION_JET_TYPE_FLAG			0x0001	// 0:��, 1:��
#define IMAGE_USE_JET_TYPE_FLAG			0x0002	// 0:�̹��� ���, 1:�̹��� ������� ����.
#define ENC_TIMER_JET_TYPE_FLAG			0x0004	// 0:���ڴ� ���, 1:Ÿ�̸� ���.
#define EX_TRG_EN_JET_TYPE_FLAG			0x0008	// 0:�ܺ�Ʈ���� ������� ����. 1: �ܺ� Ʈ���� ���

#define VARIATION_EN_JET_TYPE_FLAG		0x0010	// 0:��Ӻ����к��� ���, 1: ������� ����.
#define DROP_CNT_CTRL_EN_TYPE_FLAG		0x0020	// 0:��Ӱ��� ���� ������� ����, 1: ���
#define HD_TIMER_EN_TYPE_FLAG			0x0040	// 0:��� Ÿ�̸� ������� ����, 1: ���

#define JET_STOP_EN_JET_TYPE_FLAG		0xf000	// 0:�л�, 1:����
#endif //HD_JET_TYPE


#ifndef MAX_HEAD_CNT
#define MAX_HEAD_CNT 40
#endif //MAX_HEAD_CNT

#ifndef MAX_DSP_HEAD_CNT
#define MAX_DSP_HEAD_CNT 32 // 4�� ������ �����ؾ���.
#endif


#ifndef RUN_MODE_
#define RUN_MODE_
#define RUN_MODE_NORMAL			0x0000 // �Ϲ� ����
#define RUN_MODE_DEBUG_EN		0x0001 // controller ���� debug ��
#define RUN_MODE_LOG_LEVEL_1_EN	0x0010 // Log ���� 1�ܰ� Ȯ��
#define RUN_MODE_LOG_LEVEL_2_EN	0x0020 // Log ���� 2�ܰ� Ȯ��
#define RUN_MODE_LOG_LEVEL_3_EN	0x0040 // Log ���� 3�ܰ� Ȯ��
#define RUN_MODE_DATA_SAVE_EN	0x0100 // Debug �� ó�� ������ ����
#define RUN_MODE_BOARD_ECHO_EN	0x1000 // controller�� �� Ȯ�� ����
#define RUN_MODE_DEBUG_BOOT_EN	0x8000 // debug������ ���, ��� ����
#endif //RUN_MODE_


#ifndef SRIO_READ_SOURCE
#define SRIO_READ_SOURCE
#define SRIO_READ_SOURCE_PTM	0
#define SRIO_READ_SOURCE_DSP0	1
#define SRIO_READ_SOURCE_DSP1	2
#define SRIO_READ_SOURCE_DSP2	3
#define SRIO_READ_SOURCE_DSP3	4
#define SRIO_READ_SOURCE_HC		5
#endif //#ifndef SRIO_READ_SOURCE

//+2006.03.07 Mod BY USY
//Extension Dll���� �ܺο��� �׼����� Ŭ������ �����Ҷ� "AFX_EXT_CLASS"Ű���带 �ٿ�����
class AFX_EXT_CLASS CInkJet_Base 
//class CInkJet_Base  
//-
{ 
public:
	CInkJet_Base();
	virtual ~CInkJet_Base();

	void InitValue(void);
	void InitValue_PTM2(void);

	
	//////////////////////////////////////////////////////////////////////////
	unsigned int Bs_GetHeadMap(void);

	//Base Board ���� �Լ���
	bool	Bs_Pci_Boot(CString strNliPath, int TrgComPort, HWND hWnd, CString& sRtn);	//PCI Card Boot, ù��°�� ȣ��
	bool	Bs_Pci_Boot(CString strNliPath, int TrgComPort, HWND hWnd, unsigned int RunMode, CString &sRtn);

	bool	Bs_Pci_Close(CString& sRtn); //PCI Card Close, ����� ȣ��

	// Head ��ü ����
	bool	Bs_Head_Create(int nHeadCnt, int nHeadType, CString& sRtn);	// Bs_Pci_Boot()�� ���������� �Ϸ� ����
			//#define HD_TYPE_SPECTRA_1	1 // PTM/PPM/Spectra 128 Head controller �ִ� type : C/F ���
			//#define HD_TYPE_TRIDENT_1	2 // PTM/Trident 256 Head controller �ְ�, PPM ���� Type: Trident head Type (G���, Test)
			//#define HD_TYPE_SPECTRA_2	3 // PTM/Spectra 128 Head�� �ְ�, DSP���� Head type���� ���� : EPD ���
			//#define HD_TYPE_SPECTRA_3	4 // Spectra 128 Head controller�� �ְ�, PTM/PPM ���� Type : ��ӿ��Ŀ�
			//#define HD_TYPE_NOVA_1		10 // PTM/Nova 256 Head�� �ְ�, PPM ���� Type : nozzle 256��, ������ ���� ����-> ���е�����128��*0.125us = 16us
			//#define HD_TYPE_NOVA_2		11 // Nova 256 Head�� �ְ�, PTM/PPM���� Type : Nova Head Drop watcher��, ��
			//#define HD_TYPE_NOVA_512_1	20 // PTM/Nova nozzle 512��, PPM ���� Type : ������ ���� ����-> ���е�����128��*0.125us = 16us
			//#define HD_TYPE_NOVA_512_2	21 // PTM/Nova nozzle 512��, PPM ���� Type : Nova Head Drop watcher��, ��
			//#define HD_TYPE_Q_CLASS_512_1	30 // Q-class nozzle 512��, ������ ���� ����-> ���е�����128��*0.125us = 16us <== Nova512�� ����
			//#define HD_TYPE_Q_CLASS_512_2	31 // Q-class Head Drop watcher�� �߰�. nozzle 512��, ������ ���� ����-> ���е�����128��*0.125us = 16us

private:
	void	Bs_Head_Delete();	// Bs_Pci_Close() �Լ� ȣ��� �ڵ� ȣ���

public:
	//�̹����� Pixel Pitch ����
	bool	Bs_Set_ImgPitch(float ImgPitch, CString& sRtn);			//um ������ �Է�, Bs_Head_Create()�� ����
	float	Bs_Get_ImgPitch(void);									//um ������ ���

	//Encoder Resolution ����
	bool	Bs_Set_EncResolution(float EncResol, CString& sRtn);	//um ������ �Է�, Bs_Set_ImgPitch()�� ����
	float	Bs_Get_EncResolution(void);								//um ������ ���


	// Base �л� ���� �Լ�
	//////////////////////////////////////////////////////////////////////////
	/////////////////// BS_JetStart �Լ� ����ȭ ���� ���� ���� ////////
//private:
		bool	BS_NozzleTestStart(CString &sRtn);		// Nozzle Test ����
		bool	BS_PC_ImageJetStart(CString &sRtn);		// PC���� download�� �̹��� �л� ����
		bool	BS_DSP_ImageJetStart(CString &sRtn);	// DSP���� ������ �̹��� �л� ����
		bool	BS_DropWatcherStart(CString &sRtn);		// 081105 edit by wonho, Drop watcher�� �л� ���� �Լ� �߰�.
		bool	BS_TimerJetStart(float Frequency, CString &sRtn);	// 090716 edit by wonho, Timer �л� ���� �Լ� �߰�.
	/////////////////// BS_JetStart �Լ� ����ȭ ���� ���� ���� ////////
	//////////////////////////////////////////////////////////////////////////
		
public:
	// ��庰 �л� ���� ���� �� ����ϴ� �Լ�.
	bool	BS_JetStart(int nJetType, CString &sRtn);

	// JetStartHeadList�� �л� ������ Head�� ������.
	// Head �� �л� ���� ���ʿ� ����.
	// Head list�� �迭�� ���� �ϸ�, ��� ������ ���ƾ� ��.
	// ��� ��ȣ�� �ش��ϴ� ������ ���� TRUE �̸� �ش� ��尡 �л� ��.
	bool	BS_JetStart(const bool *JetStartHeadList, int JetType, CString &sRtn); // JetType�� ���� ���� �л� mode ���� 
	//#define HD_JET_TYPE_STOP									0x8000
	//
	//#define HD_JET_TYPE_IMAGE_FORWARD							0x0000
	//#define HD_JET_TYPE_IMAGE_BACKWARD						0x0001
	//#define HD_JET_TYPE_IMAGE_FORWARD_NOT_VARIATION			0x0010
	//#define HD_JET_TYPE_IMAGE_BACKWARD_NOT_VARIATION			0x0011
	//
	//#define HD_JET_TYPE_TIMER_IMAGE_FORWARD					0x0004
	//#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD					0x0005
	//#define HD_JET_TYPE_TIMER_IMAGE_FORWARD_NOT_VARIATION		0x0014
	//#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD_NOT_VARIATION	0x0015
	//
	//#define HD_JET_TYPE_NOZZLE_TEST							0x0046
	//#define HD_JET_TYPE_NOZZLE_TEST_SET_DROP_CNT				0x0066
	//
	//#define HD_JET_TYPE_DROPWATCHER							0x000a

	bool	Bs_JetStop(CString &sRtn);				// �л� ����
	bool	Bs_Get_JetState(void);					// �л� ���� ���� Ȯ��

	bool	BS_SetTimerFrequecy(float Frequency, CString &sRtn); // Trigger Board�� Timer mode frequency ����

	// Head �л� ���� �Լ�
	//////////////////////////////////////////////////////////////////////////
	/////////////////// Hd_Img_SetJetStart �Լ� ����ȭ ���� ���� ���� ////////
//private:
		// ������ �л� ���� ����
		bool	Hd_Img_SetForwardJetStart(unsigned int nHeadNum,CString& sRtn);
		// ������ �л� ���� ����
		bool	Hd_Img_SetBackwardJetStart(unsigned int nHeadNum,CString& sRtn);

		// ��Ӻ� ���� ���� ���� ������ �л� ���� ����
		bool	Hd_Img_SetForwardJetStart_NotVariation(unsigned int nHeadNum,CString& sRtn);
		// ��Ӻ� ���� ���� ���� ������ �л� ���� ����
		bool	Hd_Img_SetBackwardJetStart_NotVariation(unsigned int nHeadNum,CString& sRtn);

		// Nozzle test �л� ���� ����
		bool	Hd_Img_SetNozTestJetStart(unsigned int nHeadNum,CString& sRtn);
		// 091104 edit by wonho ���� �׽�Ʈ�� ��Ӱ��� ���ϱ⸦ �ϱ� ���� �߰�.
		bool	Hd_Img_Set_NDropNozTestJetStart(unsigned int nHeadNum, long DropCount, CString& sRtn);

		// 081105 edit by wonho, Drop watcher�� �л� ���� �Լ� �߰�.
		bool	Hd_Img_DropWatcherJetStart(unsigned int nHeadNum, CString& sRtn);
	/////////////////// Hd_Img_SetJetStart �Լ� ����ȭ ���� ���� ���� ////////
	//////////////////////////////////////////////////////////////////////////

public:
	// 091230 edit by wonho �л� ������ �Լ��� �ϳ��� ����
	bool	Hd_Img_SetJetStart(unsigned int nHeadNum, int nJetType, CString& sRtn);
	//#define HD_JET_TYPE_STOP									0x8000
	//
	//#define HD_JET_TYPE_IMAGE_FORWARD							0x0000
	//#define HD_JET_TYPE_IMAGE_BACKWARD						0x0001
	//#define HD_JET_TYPE_IMAGE_FORWARD_NOT_VARIATION			0x0010
	//#define HD_JET_TYPE_IMAGE_BACKWARD_NOT_VARIATION			0x0011
	//
	//#define HD_JET_TYPE_TIMER_IMAGE_FORWARD					0x0004
	//#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD					0x0005
	//#define HD_JET_TYPE_TIMER_IMAGE_FORWARD_NOT_VARIATION		0x0014
	//#define HD_JET_TYPE_TIMER_IMAGE_BACKWARD_NOT_VARIATION	0x0015
	//
	//#define HD_JET_TYPE_NOZZLE_TEST							0x0046
	//#define HD_JET_TYPE_NOZZLE_TEST_SET_DROP_CNT				0x0066
	//
	//#define HD_JET_TYPE_DROPWATCHER							0x000a
	
	// Head �� �л� ���� ���� (�л��߿��� �������� ������)
	bool	Hd_Img_SetJetStop(unsigned int nHeadNum,CString& sRtn);

	// �л� ����/���� ���� Ȯ��
	int		Hd_Img_GetJetState(unsigned int nHeadNum, CString& sRtn);
	// �л� ����/���� ���� Ȯ��
	int		Hd_Img_GetJetType(unsigned int nHeadNum, CString& sRtn);

private:
	bool	Hd_JetStop(int *Jetstate, CString &sRtn);					// ��� ����� �л� ���� ����
// 	bool	BS_ImageJetStart(int TimerEnable, CString &sRtn);


//////////////////////////////////////////////////////////////////////////
//Head ���� �Լ���
//////////////////////////////////////////////////////////////////////////

public:
	//////////////////////////////////////////////////////////////////////////
	// Head parameter ����
	/// ��� �������� �����ϴ� ������ ���� �ϱ�����
	unsigned int Hd_Get_HeadType(unsigned int nHeadNum, CString &sRtn);

	// Head �� delay ����
	//////////////////////////////////////////////////////////////////////////
	// ���⺰ ���� ���� �Լ�
	//�Ʒ� ���⺰ ���� �Լ��� ����ȭ ���� ���� ����
//private:
	bool	Hd_Set_HeadDelay(unsigned int nHeadNum, const float nHeadDelayDist, CString& sRtn);	//um������
	float	Hd_Get_HeadDelay(unsigned int nHeadNum,CString& sRtn);								//
	//�Ʒ� ���⺰ ���� �Լ��� ����ȭ ���� ���� ����
	//////////////////////////////////////////////////////////////////////////

public:
	bool	Hd_Set_HeadDelay(unsigned int nHeadNum, int nDirection, float nHeadDelayDist, CString& sRtn);	//um������
	float	Hd_Get_HeadDelay(unsigned int nHeadNum, int nDirection, CString& sRtn);
	//#define HD_JET_TYPE_IMAGE_FORWARD							0x0000
	//#define HD_JET_TYPE_IMAGE_BACKWARD						0x0001

	// Nozzle �� ���� ����
	bool	Hd_Set_Voltage(unsigned int nHeadNum, const float* nVoltage, CString &sRtn);		//Voltage ����(Data ���� : 128/256)
	bool	Hd_Set_Voltage(unsigned int nHeadNum, CString sFolder, CString &sRtn);				//Voltage ����(Data ���� : 128/256), ��� ����
	//bool	Hd_Set_Voltage(unsigned int nHeadNum, CString &sRtn);								//Voltage ����, ��� ����
	bool	Hd_Get_Voltage(unsigned int nHeadNum, float* nVoltage, CString &sRtn);				//Voltage Ȯ��

	// Head �� �������� ����
	bool	Hd_Set_SupplyVoltage(unsigned int nHeadNum, float nSupplyVoltage, CString &sRtn);	//Power supply max Voltage ����
	float	Hd_Get_SupplyVoltage(unsigned int nHeadNum, CString &sRtn);

	// Head �� ���������� Offset ����
	bool	Hd_Set_VoltageOffset(unsigned int nHeadNum, float nVoltageOffset, CString &sRtn);	//���� offset ����
	float	Hd_Get_VoltageOffsetf(unsigned int nHeadNum, CString &sRtn);						//���� offset �б�

	// Nozzle �� firing form ����
	bool	Hd_Set_WaveForm(unsigned int nHeadNum, const int* nWaveForm, CString& sRtn);		//Wave Form ����(Data ���� : 128/256)
	bool	Hd_Set_WaveForm(unsigned int nHeadNum, CString sFolder, CString& sRtn);				// ��� ����
	bool	Hd_Get_WaveForm(unsigned int nHeadNum, int* nWaveForm,CString& sRtn);
	
	// Nozzle �� ��� ���� ���� ("0"���� ���� �� �л����� ����)
	bool	Hd_Set_LiveNozzle(unsigned int nHeadNum, const int* UseList, CString & sRtn);		//����� nozzle ���� (data ���� 128/256��)
	bool	Hd_Set_LiveNozzle(unsigned int nHeadNum, CString sFolder, CString & sRtn);			//����� nozzle ���� (data ���� 128/256��), ��� ����
	bool	Hd_Get_LiveNozzle(unsigned int nHeadNum, int* UseList,CString& sRtn);				//

	// Head �� slant angle ����
	bool	Hd_Set_SlantAngle(unsigned int nHeadNum, const float nSlantData, CString& sRtn);	//Slant angle �� ����
	float	Hd_Get_SlantAngle(unsigned int nHeadNum,CString& sRtn);								//Slant angle �� ����

	// Nozzle �� slant angle offset ����
	//////////////////////////////////////////////////////////////////////////
	// ���⺰ ���� ���� �Լ�
	//�Ʒ� ���⺰ ���� �Լ��� ����ȭ ���� ���� ����
//private:
	bool	Hd_Set_SlantOffset(unsigned int nHeadNum, const float* nSlantData, CString& sRtn);	//Slant angle �� ����(Data ���� : 128/256)
	bool	Hd_Set_SlantOffset(unsigned int nHeadNum, CString sFolder, CString& sRtn);			//Slant angle �� ����(Data ���� : 128/256), ��� ����
	bool	Hd_Get_SlantOffset(unsigned int nHeadNum, float* nSlantData,CString& sRtn);
	//�Ʒ� ���⺰ ���� �Լ��� ����ȭ ���� ���� ����
	//////////////////////////////////////////////////////////////////////////

	// Nozzle �� slant angle offset ���⺰ ����
	// HD_JET_TYPE_IMAGE_FORWARD : ������
	// HD_JET_TYPE_IMAGE_BACKWARD : ������
public:
	bool	Hd_Set_SlantOffset(unsigned int nHeadNum, int nDirection, const float* nSlantData, CString& sRtn);	//Slant angle �� ����(Data ���� : 128/256)
	bool	Hd_Set_SlantOffset(unsigned int nHeadNum, int nDirection, CString sFolder, CString& sRtn);			//Slant angle �� ����(Data ���� : 128/256), ��� ����
	bool	Hd_Get_SlantOffset(unsigned int nHeadNum, int nDirection, float* nSlantData,CString& sRtn);
	//#define HD_JET_TYPE_IMAGE_FORWARD							0x0000
	//#define HD_JET_TYPE_IMAGE_BACKWARD						0x0001
	
	// ��Ӱ��� ���� ���� �׽�Ʈ �� ��� ���� ����
	bool	Hd_Set_NozTestDropCnt(unsigned int nHeadNum, long DropCount, CString& sRtn);
	bool	Hd_Set_NozzleTestFrequency(unsigned int nHeadNum, float nFrequency, CString& sRtn);
	float	Hd_Get_NozzleTestFrequency(unsigned int nHeadNum, CString& sRtn);

	// 091231 edit by wonho Nova 512 Head type�� ���� ��尣 �Ÿ� ���� �Լ� �߰�.
	bool	Hd_Set_Head_1_2_Offset(unsigned int nHeadNum, float nDistOfHead1_2, CString& sRtn);
	float	Hd_Get_Head_1_2_Offset(unsigned int nHeadNum, CString& sRtn);

	//////////////////////////////////////////////////////////////////////////
	// �̹��� �ٿ�ε� ����
public:

	//////////////////////////////////////////////////////////////////////////
	/////////////////// Hd_Img_Dn �Լ� ����ȭ ���� ���� ���� ////////
//private:
		// Head�� ������ ������ �����Ͽ� �л��ϱ� ���� image download
		unsigned long	Hd_Bin_Img_Dn_Slant(unsigned int nHeadNum, const unsigned char* ImgBuf,
											const int BufSize, int JetDirection, CString& sRtn);//Binary Image Download

		// system�� image pitch�� �ٸ� image pitch�� image�� �л��ϱ� ���� image download
		unsigned long	Hd_Bin_Img_Dn_PitchSet(unsigned int nHeadNum, const float OrgnImagePitch,
											   const unsigned char* ImgBuf, const int BufSize,
											   int JetDirection,CString& sRtn);	//Binary Image Download

		//091119 edit by wonho bit image download�� �ϱ� ���� �߰�.
		unsigned long	Hd_Bit_Img_Dn_Slant(unsigned int nHeadNum, const unsigned char* ImgBuf,
											int PixelCnt, int JetDirection, CString& sRtn);//Binary Image Download

		// system�� image pitch�� �ٸ� image pitch�� image�� �л��ϱ� ���� image download
		unsigned long	Hd_Bit_Img_Dn_PitchSet(unsigned int nHeadNum, float OrgnImagePitch,
											   const unsigned char* ImgBuf, int PixelCnt,
											   int JetDirection,CString& sRtn);	//Binary Image Download
	/////////////////// Hd_Img_Dn �Լ� ����ȭ ���� ���� ���� ////////
	//////////////////////////////////////////////////////////////////////////

public:
	// Image download ����.
	unsigned long Hd_Img_Dn(unsigned int nHeadNum, int ImgDnType, const unsigned char* ImgBuf,
							int PixelCnt, int JetDirection, CString& sRtn);
		//#define IMG_DN_TYPE_DIRECT					0x2000	// 100723 edited by wonho, �̹��� ó������ �ٷ� �ٿ�ε��ϱ�.
		//
		//#define IMG_DN_TYPE_BYTE_IMG_PITCHSET			0x0001
		//#define IMG_DN_TYPE_BYTE_IMG_SLANT			0x0002
		//#define IMG_DN_TYPE_BYTE_IMG_PITCHSET_FILE	0x1001	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
		//#define IMG_DN_TYPE_BYTE_IMG_SLANT_FILE		0x1002	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
		//
		//#define IMG_DN_TYPE_BIT_IMG_PITCHSET			0x0101
		//#define IMG_DN_TYPE_BIT_IMG_SLANT				0x0102
		//#define IMG_DN_TYPE_BIT_IMG_PITCHSET_FILE		0x1101	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.
		//#define IMG_DN_TYPE_BIT_IMG_SLANT_FILE		0x1102	// 100723 edited by wonho, ó���� �̹����� ���Ϸ� �����ϱ�.


	// image buffer ����
	bool	Hd_Img_Buf_Clr(unsigned int nHeadNum, int nDirection, CString& sRtn);

	bool	Hd_Set_OrgnImagePitch(unsigned int nHeadNum, const float nOrngImagePitch, CString& sRtn);		//Original image�� pitch�� um������ (�ʱⰪ 10um)
	float	Hd_Get_OrgnImagePitch(unsigned int nHeadNum, CString sRtn);
	// ��� ����
	unsigned long Hd_Bin_Img_Dn(unsigned int nHeadNum, CString sFolder, 
								int ImgDnType, int JetDirection,CString& sRtn);	//Binary Image Download

	//////////////////////////////////////////////////////////////////////////
	// �̹��� ���� ����
public:
	//////////////////////////////////////////////////////////////////////////
	//////////////////////// Glass ���� ���� /////////////////////////////////
	// Nozzle �� ��� Pixel ��ȣ ���� ("0"���� ���� �� �л����� ����)
	bool	Hd_Set_DSP_UseNozzleNum(unsigned int nHeadNum, const int* UseList, CString & sRtn);		//����� nozzle ���� (data ���� 128��)
	bool	Hd_Set_DSP_UseNozzleNum(unsigned int nHeadNum, CString sFolder, CString & sRtn);		//����� nozzle ���� (data ���� 128��), ��� ����
	bool	Hd_Set_DSP_UseNozzleNum(unsigned int nHeadNum, CString & sRtn);							//����� nozzle ����, ��� ����
	bool	Hd_Get_DSP_UseNozzleNum(unsigned int nHeadNum, int* UseList,CString& sRtn);				// (data ���� 128��)

	//////////////////////////////////////////////////////////////////////////
	// 081125 edit by wonho : DSP Image ������ Glass parameter�� �Ѳ����� ���� �� �� �ֵ��� ��.
	// ������ �а� ������帮��Ʈ�� �Ѳ����� ������.
	// ���� ��帮��Ʈ�� undigned int�� 32bit ������ �ش��ϴ� ��Ʈ�� 1�� ������.
	bool BS_SetGlassConfigFile( unsigned int nSetHeadList, CString fn, CString &sRtn );
	// ��庰 DSP Image ������ Glass parameter���� ���� ������.
	bool Hd_GetGlassConfigFile( unsigned int nHeadNum, CString &sRtn );

	//////////////////////////////////////////////////////////////////////////
	// 081022 edit by wonho : DSP Image ������ parameter�� �Ѳ����� ���� �� �� �ֵ��� ��.
	// ������ �а� ������帮��Ʈ�� �Ѳ����� ������.
	// ���� ��帮��Ʈ�� undigned int�� 32bit ������ �ش��ϴ� ��Ʈ�� 1�� ������.
	bool BS_SetRandomConfigFile( unsigned int nSetHeadList, CString fn, CString &sRtn );
	// ��庰 DSP Image ������ parameter���� ���� ������.
	bool Hd_GetRandomConfigFile( unsigned int nHeadNum, CString &sRtn );

	// Head �� DSP image make flag ����
	bool Hd_Set_DSP_IMG_MakeFlag(unsigned int nHeadNum, int nImgMakeFlag, int nMixFlag, int nJetDirection, CString &sRtn);
	bool Hd_Get_DSP_IMG_MakeFlag(unsigned int nHeadNum, int *ImgMakeFlag, int *MixFlag, int *JetDirection, CString &sRtn);

	// DSP image ���� ����
	bool Bs_Set_DSP_IMG_MakeStart(CString &sRtn);

	// DSP image ���� ���� Ȯ��
	long Bs_Get_DSP_IMG_MakeState(CString &sRtn); // �̹��� ������ �Ϸ� �Ǿ����� Ȯ������ �ִ� ���� �̹����� ��ȯ

private:
	// ������ ����
	bool Bs_Set_DSP_UseHead(CString &sRtn);
	bool Get_DSP_UseHead(unsigned char *UseHeadlist, CString &sRtn); // log ���°�.

//////////////////////////////////////////////////////////////////////////
//PTM ���� �Լ���
//////////////////////////////////////////////////////////////////////////
private:
	bool	PTM_SW_Reset(CString& sRtn);
	//bool	PTM_Jet_Start(CString& sRtn);
	bool	PTM_Jet_Start(const int *HeadJetTypeList, CString& sRtn);
	bool	PTM_Jet_Stop(CString& sRtn);
	bool	PTM_Led_control(int *WrData, CString& sRtn);
	bool	PTM_REG_SRIO_Write(int *Register_Add, int WrDataCnt, int *WrData, CString& sRtn);


//////////////////////////////////////////////////////////////////////////
// Trigger board ���� �Լ���
//////////////////////////////////////////////////////////////////////////
public:	
	// Stage�� ���� ����
	bool	Trg_PositionReset(CString &sRtn); // stage Home �Ŀ� 1ȸ ȣ��

	// stage�� ���� ��ġ�� encoder pulse �Է� ���� Ȯ�� (�Ÿ��� ȯ�� �� Encoder resolution �� ���ؾ� ��)
	int		Trg_GetCurrEncoderInCounter(CString& sRtn);
	// stage�� ���� ��ġ�� um ������ ��ȯ
	float	Trg_GetCurrPosition(CString& sRtn);
	// �л� ���� ��ġ ����
	bool	Trg_SetStartPosition(float StartPosition, CString& sRtn);	// �л� ������ ���� (um����)
	float	Trg_GetStartPosition(CString& sRtn);
	// �л� �� ��ġ ����
	bool	Trg_SetEndPosition(float EndPosition, CString& sRtn);		// �л� ���� ���� (um����)
	float	Trg_GetEndPosition(CString& sRtn);
	
	// Stage Error mapping data ����
	bool	Trg_SetErrorMapData(float ErrorMapPeriod, int ErrorDataCnt, int *ErrorData, CString& sRtn);	// Map data ����.
	bool	Trg_GetErrorMapData(float *ErrorMapPeriod, int ErrorDataCnt, int *ErrorData, CString& sRtn);


	// 2011,6,23
	long	Trg_GetSyncOutCnt(CString& sRtn);		// sync ��ȣ ��� ����

private:
	bool	Trg_PortOpen(int Port, HWND hWnd, CString &sRtn);
	bool	Trg_PortClose(CString &sRtn);

	bool	Trg_Receive(CString &sRtn);
	float	Trg_ReceiveStrToFloat(CString &sRtn);
	int		Trg_ReceiveStrToInt(CString &sRtn);

	bool	Trg_SetTriggerPeriod(float nPeriod, CString& sRtn);
	float	Trg_GetTriggerPeriod(CString& sRtn);

	bool	Trg_JetStart(CString& sRtn);			// sync ��ȣ ��� ����
	bool	Trg_TimerJetStart(float Frequency, CString& sRtn); // Timer mode sync ��� ����
	bool	Trg_JetStop(CString& sRtn);				// sync ��ȣ ��� ����


//////////////////////////////////////////////////////////////////////////
//��Ÿ �Լ���
//////////////////////////////////////////////////////////////////////////
public:	
	void GetVersion(CString &sRtn);
	// ��� ����
	bool Hd_Get_BufferData(unsigned int nHeadNum, int SourceSelect, int *RdAddress, int *pRtnBuffer, int ReadDataCnt, CString &sRtn); // debug��

	// 101012 edited by wonho Log folder ���� �Լ� �߰�.
	void SetLogFolder(CString nFolderName);

private:

	//////////////////////////////////////////////////////////////////////////
	// ������ ����, (�����/����, �ηη�������, ������ ���� ����, ��Ʈ�ѷ� ���� ���� ���� ��..)
	unsigned int m_RunMode;

	// �ý��� ���� ����, (��� ��Ʈ�ѷ�, PTM, DSP ���� ���� ����, ������ ���� ���� ����)
	unsigned int m_ConfigFlag;

	bool	m_bBootFlag;				//Pci Card Boot 0 : Fail, 1: Pass
	bool	m_HeadCreateFlag;			//Head�� ����� ������..
	// 100121 edit by wonho : ��� ������ �°� ���� ���� ���� �ϴ°����� ����
	//bool	m_pHeadMakeFlag[MAX_HEAD_CNT];
	bool	*m_pHeadMakeFlag;
	bool	m_HeadDSPImgMakeFlag;		// 090220 edit by wonho, DSP�� �̹����� ����� �ִ��� Ȯ�ο�.

	int	m_PTM_LED_Ctrl_REG_ADD[2];
	int	m_PTM_Mode_Ctrl_REG_ADD[2];
	int	m_PTM_HEADSET_REG_ADD[2];
	int	m_PTM_Scan_Ctrl_REG_ADD[2];
	int	m_PTM_SW_Rst_Ctrl_REG_ADD[2];
	int	m_PTM_TLine_REG_ADD[2];

	int m_PTM_PTS_IN_CNT_ADD[2];		//

	unsigned int m_HeadType;			// Head type�� ����. 

	int		m_JetType;
	int		m_LastHeadJetType;			// ���������� ������ Head�� ������ jet type ����.

	float	m_TimerModeFrequency;		//Timer Mode Jetting Frequency
	float	m_EncoderResolution;		//Encoder Resolution
	float	m_ImagePitch;				//image pitch

	int		m_ErrorMapDataCnt;
	float	m_ErrorMapPeriod;
	unsigned char	m_TrgCtr;
	
	unsigned int	m_HeadEndNum;		//Head ����
	
	CString m_strNliPath;				//Nli File Path

	int	m_TrgComPort;
	HWND m_hWnd;

	//////////////////////////////////////////////////////////////////////////
	// 090625 edit by wonho image ����� �ð� Ȯ�ο� �߰�
	CTime m_Time_DSP_IMG_MakeStart;
};

#endif // !defined(AFX_INKJET_BASE_H__F74BE705_A71C_4B43_A406_AA93046D8567__INCLUDED_)

#endif //#ifndef INKJET_BASE_H
