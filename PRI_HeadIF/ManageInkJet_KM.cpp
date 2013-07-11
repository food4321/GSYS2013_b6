// ManageInkJet_KM.cpp: implementation of the CManageInkJet_KM class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "pri_headif.h"
#include "ManageInkJet_KM.h"
#include "CommandStruct_KM.h"
//#include "STDIO.H"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManageInkJet_KM::CManageInkJet_KM()
{
	m_hDll=NULL;
}

CManageInkJet_KM::~CManageInkJet_KM()
{
	IJCS_Close();
}

BOOL CManageInkJet_KM::LoadFunction()
{
	m_hDll = ::LoadLibrary("IJCS1_DLL.dll");
	if( m_hDll == NULL ){
		return FALSE;
	}

	DLL_Open = (BOOL(__stdcall*)(void))::GetProcAddress(m_hDll, "IJCS1_Open");
	if(DLL_Open == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}

	DLL_Close = (BOOL(__stdcall*)(void))::GetProcAddress(m_hDll, "IJCS1_Close");
	if(DLL_Close == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}

	DLL_Reset = (BOOL(__stdcall*)(void))::GetProcAddress(m_hDll, "IJCS1_Reset");
	if(DLL_Reset == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}

	DLL_GetStatus = (BOOL(__stdcall*)(DWORD mmb, void *status, DWORD size))::GetProcAddress(m_hDll, "IJCS1_GetStatus");
	if(DLL_GetStatus == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}

	DLL_SendCommand = (BOOL(__stdcall*)(DWORD mmb, DWORD cmd, void *buffer, DWORD size))::GetProcAddress(m_hDll, "IJCS1_SendCommand");
	if(DLL_SendCommand == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}

	DLL_SendImage = (BOOL(__stdcall*)(DWORD mmb, DWORD dbm, DWORD head, DWORD rl, void *image, DWORD size))::GetProcAddress(m_hDll, "IJCS1_SendImage");
	if(DLL_SendImage == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}
	
	DLL_GetErrorCode = (BOOL(__stdcall*)(void))::GetProcAddress(m_hDll, "IJCS1_GetError");
	if(DLL_GetErrorCode == NULL){
		::FreeLibrary(m_hDll);
		m_hDll = NULL;
		return FALSE;
	}
	
	return TRUE;
}

BOOL CManageInkJet_KM::IJCS_Open()
{
	if (LoadFunction()==FALSE){
		return FALSE;
	}

	if(m_hDll==NULL){
		return FALSE;
	}
	BOOL ok;		
	ok = DLL_Open();
	return ok;
}

BOOL CManageInkJet_KM::IJCS_Close()
{
	BOOL ok;
	if(m_hDll!=NULL){
		ok = DLL_Close();
	}
	FreeLibrary(m_hDll);
	m_hDll = NULL;
	return ok;
}

BOOL CManageInkJet_KM::IJCS_Reset()
{
	if(m_hDll==NULL){
		return FALSE;
	}
	BOOL ok;
	ok = DLL_Reset();
	return ok;
}

BOOL CManageInkJet_KM::IJCS_SendCommand(DWORD mmb, DWORD cmd, void *buffer, DWORD size)
{
	if(m_hDll==NULL){
		return FALSE;
	}
	BOOL ok;
	ok = DLL_SendCommand( mmb, cmd, buffer, size);
	if(!ok)return FALSE;
	return TRUE;
}

BOOL CManageInkJet_KM::IJCS_SendImage(DWORD mmb, DWORD dbm, DWORD head, DWORD rl, void *image, DWORD size)
{
	if(m_hDll==NULL){
		return FALSE;
	}
	BOOL ok = DLL_SendImage( mmb, dbm, head, rl, image, size);
	if(!ok)return FALSE;
	return TRUE;
}

BOOL CManageInkJet_KM::IJCS_GetStatus(DWORD mmb, void *status, DWORD size)
{
	if(m_hDll==NULL){
		return FALSE;
	}
	BOOL ok = DLL_GetStatus( mmb, status, size);
	if(!ok)return FALSE;
	return TRUE;
}

DWORD CManageInkJet_KM::IJCS_GetErrorCode()
{
	if(m_hDll==NULL){
		return FALSE;
	}
	DWORD errNo = DLL_GetErrorCode();
	
	return errNo;
}
BOOL CManageInkJet_KM::Initialize()
{
	BOOL ok;
	DWORD err=0;
	
	if(m_hDll!=NULL){
		ok = IJCS_Close();
		if (ok==FALSE){
			return FALSE;
		}
	}
	
	ok = IJCS_Open();
	if (ok==FALSE){
		return FALSE;
	}
	
	struct ijcs_status km_status;
	ok = IJCS_GetStatus(0,&km_status,sizeof(km_status));
	if(ok==FALSE){
		err = IJCS_GetErrorCode();
		printf("Error auto Trigger! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_AUTO_TRIGER, err);
		return FALSE;
	}

	// Auto trigger repeat
	struct st_cmd_set_auto_trigger auto_trigger;
	auto_trigger.repeat = 1;	//0 : �ܺ� Ʈ���� ��� ����, 1 : �ܺ� Ʈ���� �ϰ� ����, 2 : ���� ��� ī���� Ʈ����
	auto_trigger.interval = 1;		//0 : ����, 1 : �ڵ� Ʈ���� - TBD	
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_AUTO_TRIGER, (BYTE *)&auto_trigger, sizeof(auto_trigger));
	if(ok==FALSE){
		err = IJCS_GetErrorCode();
		printf("Error auto Trigger! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_AUTO_TRIGER, err);
		return FALSE;
	}

	struct st_cmd_set_flush_trigger flush_trigger;
	flush_trigger.trigger = 1;	

	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_FLUSHING_TRIGER, (BYTE *)&flush_trigger, sizeof(flush_trigger));
	if(ok==FALSE){
		err = IJCS_GetErrorCode();
		printf("Error auto Trigger! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_AUTO_TRIGER, err);
		return FALSE;
	}










	//Set scan trigger
	struct st_trigger_select trigger_sel;
	trigger_sel.trigger = 1;	//0 : �ܺ� Ʈ���� ��� ����, 1 : �ܺ� Ʈ���� �ϰ� ����, 2 : ���� ��� ī���� Ʈ����
	trigger_sel.mode = 0;		//0 : ����, 1 : �ڵ� Ʈ���� - TBD	
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_TRIGGER, (BYTE *)&trigger_sel, sizeof(trigger_sel));
	if(ok==FALSE){
		err = IJCS_GetErrorCode();
		printf("Error Set Trigger! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_TRIGGER, err);
		return FALSE;
	}

	//Enable scan trigger
	struct st_cmd_trigger_enable trigger_enable;
	trigger_enable.enable = 1;	//0 : Ʈ���� ��Ȱ��ȭ, 1 : Ʈ���� Ȱ��ȭ
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_PAGE_TRIGGER_ENABLE, (BYTE *)&trigger_enable, sizeof(trigger_enable));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Page Trigger Enable! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_PAGE_TRIGGER_ENABLE, err);
		return FALSE;
	}

	//Select fire
	struct st_cmd_sel_fire sel_fire;
	sel_fire.mode = 2;			//0 : A �� ���, 2 : ���� ������ �̿�, 3 : AB �� �� �����ڸ��� ���
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SELECT_FIRE, (BYTE *)&sel_fire, sizeof(sel_fire));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Select Fire! command ID=%x, error=%d\n", IJCS1_COMMAND_SELECT_FIRE, err);
		return FALSE;
	}

	//Set F Time
	struct st_cmd_set_ftime	set_ftime;
	set_ftime.time = 300000;	//���̾��ֱ⸦ nsec ������ �����Ѵ�. 25 ~ 820000nsec
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_FTIME, (BYTE *)&set_ftime, sizeof(set_ftime));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Set F Time! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_FTIME, err);
		return FALSE;
	}

	//Set Print Info
	struct st_cmd_print_info	print_info;
	print_info.mode = 1;		//0 : �ܹ��� ��ȭ 1 : ����� ��ȭ
	print_info.reserve = 0;		//  
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_PRINT_INFO, (BYTE *)&print_info, sizeof(print_info));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Set Print Infomation! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_PRINT_INFO, err);
		return FALSE;
	}

	//Set External IO
	struct st_cmd_external_io	ex_io;
	ex_io.mode = 0;				//�ܺ� I / O ���� ���, 0:Ack��ȣ�� ������� �ʴ´�, 1:Ack��ȣ�� ����Ѵ�.
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_EXTERNAL_IO, (BYTE *)&ex_io, sizeof(ex_io));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Set External IO! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_EXTERNAL_IO, err);
		return FALSE;
	}

	return TRUE;
}

BOOL CManageInkJet_KM::SetHeadParameters()
{
	BOOL ok;
	DWORD err=0;

	for ( int du = 0; du < DU_MAX; du++ ) {
		for ( int kmdb = 0; kmdb < KMDB_MAX; kmdb++ ) {
			//Set head type
			struct st_cmd_head_type head_type;
			head_type.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			head_type.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			head_type.nozzle_num = 512;		//���� �� 128,256,512,1024 ���ڸ� �Է��Ͻʽÿ�.
			head_type.nozzle_row = 2;		//���� �� �� 1:1 �� 2:2 ���� ��Ÿ���ϴ�.
			head_type.drive_type = 3;		//���� Ÿ�� 1 : ���� ����, 3 : 3 �� ������ �����ݴϴ�.
			head_type.kmdb_type = 0;		//1:KMDB-S

			/*					  KMDB ���� 0 :  KMDB -S01A(TBD)
                                            '1:  KMDB -L01A(TBD)
                                            '2:  KMDB -L02A(TBD)
                                            '3:  KMDB -D01A(TBD)
			*/

			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_HEAD_TYPE, (BYTE *)&head_type, sizeof(head_type));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Head Type! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_HEAD_TYPE, err);
				return FALSE;
			}

			//Set use head
			struct st_cmd_head_use head_use;
			head_use.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			head_use.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			head_use.head_use = 1;			//��� ��� 0 : �̻��, 1 ����� �����ݴϴ�.
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_ASSIGN_USE_HEAD, (BYTE *)&head_use, sizeof(head_use));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Assign Use Head! command ID=%x, error=%d\n", IJCS1_COMMAND_ASSIGN_USE_HEAD, err);
				return FALSE;
			}

			// Set STB
			struct st_cmd_stb_order stb;
			stb.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			stb.kmdb_id = kmdb;			//KMDB ���� ��ȣ (0 ~ 3)

			stb.l_for[0] = 0;			// L �� �ⱹ 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
			stb.l_for[1] = 1;
			stb.l_for[2] = 2;
			stb.l_rev[0] = 2;			// L �� ���� ���� 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
			stb.l_rev[1] = 1;
			stb.l_rev[2] = 0;
			stb.r_for[0] = 2;			// R �� �ⱹ 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
			stb.r_for[1] = 1;
			stb.r_for[2] = 0;
			stb.r_rev[0] = 0;			// R �� �Ա� 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
			stb.r_rev[1] = 1;
			stb.r_rev[2] = 2;

			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_STB_ORDER, (BYTE *)&stb, sizeof(stb));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Assign Use Head! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_STB_ORDER, err);
				return FALSE;
			}

		}
	}

	return TRUE;
}

BOOL CManageInkJet_KM::SetWaveParameters()
{
	BOOL ok;
	DWORD err=0;

	for ( int du = 0; du < DU_MAX; du++ ) {
		for ( int kmdb = 0; kmdb < KMDB_MAX; kmdb++ ) {
			//Set base wave
			struct st_cmd_base_wave base_wave;
			base_wave.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			base_wave.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			base_wave.wave_id = 0;			//���� ��ȣ (0 : ���� A 1 : ���� B)
			base_wave.swdev = 2;			//�⺻ ���� ���� ���� ���� �����մϴ�. (1-8)          
											//������ �� n�� ���� ���� swv (n) swt (n)������ ������ ��ȿ�ϴ�.
			base_wave.swv1 = 2;				//���� 1�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt1 = 2400;			//���� 1 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv2 = 1;				//���� 2�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt2 = 4800;			// ���� 2 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv3 = 0;				// ���� 3�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt3 = 0;				// ���� 3 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv4 = 0;				// ���� 4�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt4 = 0;				// ���� 4 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv5 = 0;				// ���� 5�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt5 = 0;				// ���� 5 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv6 = 0;				// ���� 6 ������ ����. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt6 = 0;				// ���� 6 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv7 = 0;				// ���� 7�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt7 = 0;				// ���� 7 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.swv8 = 0;				// ���� 8 ������ ����. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
			base_wave.swt8 = 0;				// ���� 8 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
			base_wave.droplet_time = 12000;	// droplet-time�� 1nsec ������ ����. ex) 10.0usec = 0x2710
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_BASE_WAVE, (BYTE *)&base_wave, sizeof(base_wave));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Base Wave! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_BASE_WAVE, err);
				return FALSE;
			}

			//Set drive wave
			struct st_cmd_drive_wave drive_wave;
			drive_wave.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			drive_wave.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			drive_wave.level_num = LEVEL;	//���� �� 2-8 ���ڸ� �Է��Ͻʽÿ�.
			drive_wave.sw_sel1 = 1;			//���� ���� ���� ���� ���� ������ ������ �����մϴ�. 1 : ù ��° ��� ���� ���� 2 : �� ��° ��� ���� ���� 3 : ����° ��� ���� ���� 0 : ���� ����
			drive_wave.sw_sel2 = 1;			//���� ���� �� ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel3 = 1;			//���� ���� 3 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel4 = 0;			//���� ���� 4 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel5 = 0;			//���� ���� 5 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel6 = 0;			//���� ���� 6 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel7 = 0;			//���� ���� 7 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel8 = 0;			//���� ���� 8 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel9 = 0;			//���� ���� 9 ��°�� ���� ��� ������ ������ �����մϴ�.
			drive_wave.sw_sel10 = 0;		//���� ���� 10 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel11 = 0;		//���� ���� 11 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel12 = 0;		//���� ���� 12 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel13 = 0;		//���� ���� 13 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel14 = 0;		//���� ���� 14 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel15 = 0;		//���� ���� 15 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.sw_sel16 = 0;		//���� ���� 16 ��° ���� ���� ������ ������ �����մϴ�.
			drive_wave.img0_num = 0;		//�̹��� ������ 0���� ���� ���� ��ġ�� �����մϴ�. �� ���� ���� ���� �� ������ �������� ������� ���θ� �����մϴ�. (0 ~ 16 ����) 0 �� �� ���� ��µ��� �ʽ��ϴ�.
			drive_wave.img1_num = 1;		//�̹��� ������ 1 �ð� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img2_num = 2;		//�̹��� ������ 2 �ð� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img3_num = 3;		//�̹��� ������ 3 ���� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img4_num = 0;		//�̹��� ������ 4 �ð� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img5_num = 0;		//�̹��� ������ 5 �ð� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img6_num = 0;		//�̹��� ������ 6 �ð� ���� ���� ��ġ�� �����մϴ�.
			drive_wave.img7_num = 0;		//�̹��� ������ 7�� ���� ���� ��ġ�� �����մϴ�.
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_DRIVE_WAVE, (BYTE *)&drive_wave, sizeof(drive_wave));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Drive Wave! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_DRIVE_WAVE, err);
				return FALSE;
			}

			//Set head volt
			struct st_cmd_head_voltage head_voltage;
			head_voltage.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			head_voltage.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			head_voltage.on_volt_num = 2;		//ON ���� ���� (1 ~ 8 �ִ� 8 ���� ����)
			head_voltage.off_volt_num = 2;		//OFF ���� ���� (1 ~ 8 �ִ� 8 ���� ����)
			head_voltage.head_on[0] = 20000;	//On 4000 ~ 20000 [4.00 ~ 20.00V] ������ ���ڸ� �����մϴ�. 1mV �����Դϴ�. (D01A�� ��� [4.00 ~ 40.00])
			head_voltage.head_on[1] = 20000;	//
			head_voltage.head_on[2] = 0;		//
			head_voltage.head_on[3] = 0;		//
			head_voltage.head_on[4] = 0;		//
			head_voltage.head_on[5] = 0;		//
			head_voltage.head_on[6] = 0;		//
			head_voltage.head_on[7] = 0;		//
			head_voltage.head_off[0] = 10000;	//Off 4000 ~ 20000 [4.00 ~ 20.00V] ������ ���ڸ� �����մϴ�. 1mV �����Դϴ�. (D01A�� ��� [4.00 ~ 40.00])
			head_voltage.head_off[1] = 10000;	//
			head_voltage.head_off[2] = 0;		//
			head_voltage.head_off[3] = 0;		//
			head_voltage.head_off[4] = 0;		//
			head_voltage.head_off[5] = 0;		//
			head_voltage.head_off[6] = 0;		//
			head_voltage.head_off[7] = 0;		//
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_HEAD_VOLT, (BYTE *)&head_voltage, sizeof(head_voltage));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Head Volt! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_HEAD_VOLT, err);
				return FALSE;
			}

		}
	}

	return TRUE;
}

BOOL CManageInkJet_KM::SetFireSTime()
{
	BOOL ok;
	DWORD err=0;

	for ( int du = 0; du < DU_MAX; du++ ) {
		for ( int kmdb = 0; kmdb < KMDB_MAX; kmdb++ ) {

			//Set fire divide&multiply 
			struct st_fire_encoder fire_encoder;
			fire_encoder.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			fire_encoder.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			fire_encoder.multiply = 1;			//ü n = 1 to 127 multiply
			fire_encoder.divider = 1;			//���� n = 1 to 1023 divide
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_FIRE_ENCODER, (BYTE *)&fire_encoder, sizeof(fire_encoder));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Fire Divide & Multiply! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_FIRE_ENCODER, err);
				return FALSE;
			}

			//Set S time type
			struct st_cmd_fire_stime_type stime_type;
			stime_type.dbm_id = du;				//DBM ���� ��ȣ (0 ~ 3)
			stime_type.kmdb_id = kmdb;			//KMDB ���� ��ȣ (0 ~ 3)
			stime_type.type = 0;				//s �ð� ���� ����
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_FIRE_STIME_TYPE, (BYTE *)&stime_type, sizeof(stime_type));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Stime Type! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_FIRE_STIME_TYPE, err);
				return FALSE;
			}

			//Set S time fix value
			struct st_cmd_fire_stime_fixvalue stime_fixvalue;
			stime_fixvalue.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			stime_fixvalue.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			stime_fixvalue.time = 100000;		//s �ð� ���� ��
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_FIRE_STIME_FIXVALUE, (BYTE *)&stime_fixvalue, sizeof(stime_fixvalue));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set S Time Fix Value! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_FIRE_STIME_FIXVALUE, err);
				return FALSE;
			}

		}
	}

	return TRUE;
}

BOOL CManageInkJet_KM::SetDelay()
{
	BOOL ok;
	DWORD err=0;

	for ( int du = 0; du < DU_MAX; du++ ) {
		for ( int kmdb = 0; kmdb < KMDB_MAX; kmdb++ ) {

			//Set delay
			struct st_cmd_head_delay head_delay;
			head_delay.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			head_delay.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			head_delay.dir = 0;				//���� ���� ������ �����մϴ�. (0-1)
			switch( kmdb ) {
				case 0:
					head_delay.headl_delay		= 42;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 1;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				case 1:
					head_delay.headl_delay		= 986;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 945;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				case 2:
					head_delay.headl_delay		= 1918;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 1877;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				default:		// case 3:
					head_delay.headl_delay		= 2857;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 2816;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
			}
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_HEAD_DELAY, (BYTE *)&head_delay, sizeof(head_delay));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Head Delay! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_HEAD_DELAY, err);
				return FALSE;
			}

			//Set delay(for homeward)
			head_delay.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			head_delay.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
			head_delay.dir = 1;				//���� ���� ������ �����մϴ�. (0-1)
			switch( kmdb ) {
				case 0:
					head_delay.headl_delay		= 2816;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 2857;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				case 1:
					head_delay.headl_delay		= 1877;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 1918;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				case 2:
					head_delay.headl_delay		= 945;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 986;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
				default:		// case 3:
					head_delay.headl_delay		= 1;		//��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headl_subpixel	= 0;		//��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					head_delay.headr_delay		= 42;		//��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
					head_delay.headr_subpixel	= 0;		//��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
					break;
			}
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_HEAD_DELAY, (BYTE *)&head_delay, sizeof(head_delay));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Head Delay(homewoard)! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_HEAD_DELAY, err);
				return FALSE;
			}

		}
	}
	return TRUE;
}

BOOL CManageInkJet_KM::SetImageInfo()
{
	BOOL ok;
	DWORD err=0;

	// print start (page memory clear  print environment initialize
	struct st_cmd_print_start print_start;

	print_start.reserved = 0;
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_PRINT_START, (BYTE *)&print_start, sizeof(print_start));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Print Abort! command ID=%x, error=%d\n", IJCS1_COMMAND_PRINT_START, err);
		return FALSE;
	}

	for ( int du = 0; du < DU_MAX; du++ ) {
		for ( int kmdb = 0; kmdb < KMDB_MAX; kmdb++ ) {

			//Set image information
			struct st_cmd_image_info image_info;
			image_info.dbm_id = du;			//DBM ���� ��ȣ (0 ~ 3)
			image_info.kmdb_id = kmdb;		//KMDB ���� ��ȣ (0 ~ 3)
#if (LEVEL==4)
			image_info.depth = 2;			//�޸� ���� �̹����� �޸� ���� ���̸� �����մϴ�. �̹����� Bit ���� �����մϴ�. 1,2,4�� �����Ͻʽÿ�.
#else
			image_info.depth = 1;			//�޸� ���� �̹����� �޸� ���� ���̸� �����մϴ�. �̹����� Bit ���� �����մϴ�. 1,2,4�� �����Ͻʽÿ�.
#endif
			image_info.length = 2106;		//�̹��� ���� �̹����� ���̸� �����մϴ�.	
			ok = IJCS_SendCommand(0, IJCS1_COMMAND_SET_IMAGE_INFO, (BYTE *)&image_info, sizeof(image_info));
			if(ok==FALSE){
				//err = IJCS_GetErrorCode();
				printf("Error Set Image Information! command ID=%x, error=%d\n", IJCS1_COMMAND_SET_IMAGE_INFO, err);
				return FALSE;
			}

		}
	}

	return TRUE;
}

BOOL CManageInkJet_KM::SendImageData()
{
	BOOL ok=TRUE;
	DWORD err=0;

	//Check image file 
	FILE *fp;
	int width;
	int height;
	int offset;
	int bits;
	int byte_per_line;

	fp = fopen(FILE_NAME_1_K,"rb");
	if(fp==NULL) {
		AfxMessageBox("File open Error");
		//printf("Error Open image file\n");
		return( FALSE );
	}
	ok = GetImageProperty(fp,width,height,offset,bits,byte_per_line);//Get image information
	if(!ok){
		return( FALSE );
	}
	fclose(fp);

	//Check the parameter image bits & IMAGE_DEPTH.
	if((bits==1)&&(IMAGE_DEPTH!=1)){
		printf("Bits missmatch\n");//1bit
		return( FALSE );
	}
	else if( (bits==4)&&(IMAGE_DEPTH!=2) ){
		printf("Bits missmatch\n");//1bit
		return( FALSE );
	}

	int memory_size=(NOZZLES*height*IMAGE_DEPTH)/8;

	//Send Image 
	ok = ImageReadAndSend(memory_size, (NOZZLES*IMAGE_DEPTH)/8, height );
	if(!ok){
		printf("Error Image Send\n");
		return( FALSE );
	}
	else{
		printf("OK! image send\n");
	}

	return( TRUE );
}

BOOL CManageInkJet_KM::StarPrint()
{
	BOOL ok;
	DWORD err=0;

	//Generate soft trigger
	struct st_cmd_manual_trigger manual_trigger;
	manual_trigger.reserved = 0;			//reserve
	ok = IJCS_SendCommand(0, IJCS1_COMMAND_GENERATE_TRIGGER, (BYTE *)&manual_trigger, sizeof(manual_trigger));
	if(ok==FALSE){
		//err = IJCS_GetErrorCode();
		printf("Error Genarate Soft Trigger! command ID=%x, error=%d\n", IJCS1_COMMAND_GENERATE_TRIGGER, err);
		return FALSE;
	}

	return TRUE;
}

BOOL CManageInkJet_KM::ImageReadAndSend(int memory_size, int line_bytes, int height )
{
	BOOL ok;
	FILE *fp;
	char filenname[256];
	BYTE	*pimg_r_data;
	BYTE	*pimg_l_data;
	BYTE *data;
	BYTE *pbmp_line_data;


	data =(BYTE*)malloc(memory_size);		//Image Data
	if(data == NULL){
		printf("Error malloc\n");
		return FALSE;
	}
	pimg_l_data = (BYTE *)malloc( memory_size / 2 );
	if(pimg_l_data == NULL){
		free( data );
		printf("Error malloc\n");
		return FALSE;
	}
	pimg_r_data = (BYTE *)malloc( memory_size / 2 );
	if(pimg_r_data == NULL){
		free( data );
		free( pimg_l_data );
		printf("Error malloc\n");
		return FALSE;
	}


	DWORD mmb;
	DWORD du;
	DWORD head;
	DWORD back;
	for(int i=0;i<IMAGE_COUNT;i++){
		switch(i){
		case 0:
			strcpy(filenname,FILE_NAME_1_K);
			mmb  = 0;
			du   = 0;
			head = 0;
			back = 1;
			break;
		case 1:
			strcpy(filenname,FILE_NAME_1_Y);
			mmb  = 0;
			du   = 0;
			head = 1;
			back = 1;
			break;
		case 2:
			strcpy(filenname,FILE_NAME_1_M);
			mmb  = 0;
			du   = 0;
			head = 2;
			back = 1;
			break;
		case 3:
			strcpy(filenname,FILE_NAME_1_C);
			mmb  = 0;
			du   = 0;
			head = 3;
			back = 1;
			break;
		case 4:
			strcpy(filenname,FILE_NAME_2_K);
			mmb  = 0;
			du   = 0;
			head = 0;
			back = 0;
			break;
		case 5:
			strcpy(filenname,FILE_NAME_2_Y);
			mmb  = 0;
			du   = 0;
			head = 1;
			back = 0;
			break;
		case 6:
			strcpy(filenname,FILE_NAME_2_M);
			mmb  = 0;
			du   = 0;
			head = 2;
			back = 0;
			break;
		case 7:
			strcpy(filenname,FILE_NAME_2_C);
			mmb  = 0;
			du   = 0;
			head = 3;
			back = 0;
			break;
		}

		fp = fopen(filenname,"rb");
		if(fp==NULL){
			printf("Error Open image file\n");
			free(pimg_l_data);
			free(pimg_r_data);
			free(data);
			return FALSE;
		}
		ok = GetImageData(fp,data,memory_size,back);
		fclose(fp);
		if(ok==FALSE){
			free(pimg_l_data);
			free(pimg_r_data);
			free(data);
			printf("Error BMP file read!");
			return FALSE;
		}

		// �f??�̕������� ------------------------------------
		WORD wdata;
		BYTE r_data, l_data;
		for ( int i = 0; i < height; i++ ) {
			pbmp_line_data = data + ( line_bytes * i );

			if ( IMAGE_DEPTH == 1 ) {
				// �Q�K���i�P��f�P�r�b�g�j�f??����
				// �P���C���̉摜�f??���k�q��ɕ�������B
				for ( int j = 0; j < line_bytes/2; j++ ) {
					// �Q�o�C�g�P�ʂłk��A�q�񂻂ꂼ��P�o�C�g�f??���쐬����B
					wdata = ( *(pbmp_line_data+(j*2)) << 8 ) + *(pbmp_line_data+(j*2+1));

					r_data =
						( ( ( wdata >> 14 ) & 0x0001 ) << 0 ) + 
						( ( ( wdata >> 12 ) & 0x0001 ) << 1 ) + 
						( ( ( wdata >> 10 ) & 0x0001 ) << 2 ) +		
						( ( ( wdata >>  8 ) & 0x0001 ) << 3 ) +	 
						( ( ( wdata >>  6 ) & 0x0001 ) << 4 ) + 
						( ( ( wdata >>  4 ) & 0x0001 ) << 5 ) + 
						( ( ( wdata >>  2 ) & 0x0001 ) << 6 ) + 
						( ( ( wdata >>  0 ) & 0x0001 ) << 7 )  ;

					l_data =
						( ( ( wdata >>  1 ) & 0x0001 ) << 0 ) + 
						( ( ( wdata >>  3 ) & 0x0001 ) << 1 ) + 
						( ( ( wdata >>  5 ) & 0x0001 ) << 2 ) + 
						( ( ( wdata >>  7 ) & 0x0001 ) << 3 ) + 
						( ( ( wdata >>  9 ) & 0x0001 ) << 4 ) + 
						( ( ( wdata >> 11 ) & 0x0001 ) << 5 ) + 
						( ( ( wdata >> 13 ) & 0x0001 ) << 6 ) + 
						( ( ( wdata >> 15 ) & 0x0001 ) << 7 )  ;

					*(pimg_l_data+(i*line_bytes/2 +j)) = l_data;
					*(pimg_r_data+( (i*line_bytes/2) +  (line_bytes/2-j-1)  )) = r_data; 
#if 0
					r_data =
						( ( ( wdata >> 14 ) & 0x0001 ) << 7 ) + 
						( ( ( wdata >> 12 ) & 0x0001 ) << 6 ) + 
						( ( ( wdata >> 10 ) & 0x0001 ) << 5 ) +		
						( ( ( wdata >>  8 ) & 0x0001 ) << 4 ) +	 
						( ( ( wdata >>  6 ) & 0x0001 ) << 3 ) + 
						( ( ( wdata >>  4 ) & 0x0001 ) << 2 ) + 
						( ( ( wdata >>  2 ) & 0x0001 ) << 1 ) + 
						( ( ( wdata >>  0 ) & 0x0001 ) << 0 )  ;

					l_data =
						( ( ( wdata >>  1 ) & 0x0001 ) << 7 ) + 
						( ( ( wdata >>  3 ) & 0x0001 ) << 6 ) + 
						( ( ( wdata >>  5 ) & 0x0001 ) << 5 ) + 
						( ( ( wdata >>  7 ) & 0x0001 ) << 4 ) + 
						( ( ( wdata >>  9 ) & 0x0001 ) << 3 ) + 
						( ( ( wdata >> 11 ) & 0x0001 ) << 2 ) + 
						( ( ( wdata >> 13 ) & 0x0001 ) << 1 ) + 
						( ( ( wdata >> 15 ) & 0x0001 ) << 0 )  ;

					*(pimg_r_data+(i*line_bytes/2 +j)) = r_data;
					*(pimg_l_data+( (i*line_bytes/2) +  (line_bytes/2-j-1)  )) = l_data; 
#endif
				}
			}
			else {
				// �S�K���i�P��f�Q�r�b�g�j�f??����
				// �P���C���̉摜�f??���k�q��ɕ�������B
				for ( int j = 0; j < line_bytes/2; j++ ) {
					// �Q�o�C�g�P�ʂłk��A�q�񂻂ꂼ��P�o�C�g�f??���쐬����B
					wdata = ( *(pbmp_line_data+(j*2)) << 8 ) + *(pbmp_line_data+(j*2+1));
					r_data =
						( ( ( wdata >> 12 ) & 0x0003 ) << 0 ) + 
						( ( ( wdata >>  8 ) & 0x0003 ) << 2 ) + 
						( ( ( wdata >>  4 ) & 0x0003 ) << 4 ) + 
						( ( ( wdata >>  0 ) & 0x0003 ) << 6 )  ;
	
					l_data =
						( ( ( wdata >>  2 ) & 0x0003 ) << 0 ) + 
						( ( ( wdata >>  6 ) & 0x0003 ) << 2 ) + 
						( ( ( wdata >> 10 ) & 0x0003 ) << 4 ) + 
						( ( ( wdata >> 14 ) & 0x0003 ) << 6 )  ;

					*(pimg_l_data+(i*line_bytes/2 +j)) = l_data;
					*(pimg_r_data+( (i*line_bytes/2) +  (line_bytes/2-j-1)  )) = r_data; 
#if 0
					r_data =
						( ( ( wdata >> 12 ) & 0x0003 ) << 6 ) + 
						( ( ( wdata >>  8 ) & 0x0003 ) << 4 ) + 
						( ( ( wdata >>  4 ) & 0x0003 ) << 2 ) + 
						( ( ( wdata >>  0 ) & 0x0003 ) << 0 )  ;
	
					l_data =
						( ( ( wdata >>  2 ) & 0x0003 ) << 6 ) + 
						( ( ( wdata >>  6 ) & 0x0003 ) << 4 ) + 
						( ( ( wdata >> 10 ) & 0x0003 ) << 2 ) + 
						( ( ( wdata >> 14 ) & 0x0003 ) << 0 )  ;

					*(pimg_r_data+(i*line_bytes/2 +j)) = r_data;
					*(pimg_l_data+( (i*line_bytes/2) +  (line_bytes/2-j-1)  )) = l_data; 
#endif
				}
			}
		}
		// -----------------------------------------------------

		ok = IJCS_SendImage( mmb, du, head, 0, pimg_l_data, memory_size/2);
		if(ok==FALSE){
			//err = IJCS_GetErrorCode();
			free(pimg_l_data);
			free(pimg_r_data);
			free(data);
			printf("Error Send Image Data! \n");
			return FALSE;
		}
		ok = IJCS_SendImage( mmb, du, head, 1, pimg_r_data, memory_size/2);
		if(ok==FALSE){
			//err = IJCS_GetErrorCode();
			free(pimg_l_data);
			free(pimg_r_data);
			free(data);
			printf("Error Send Image Data! \n");
			return FALSE;
		}

	}
	free(pimg_l_data);
	free(pimg_r_data);
	free(data);
	return TRUE;
}

// BMP file access /////////////////////////////////////////////////////////////////////////
BOOL CManageInkJet_KM::GetImageProperty(FILE *fp,int &width,int &height,int &offset,int &bits,int &byte_per_line)
{
	fseek(fp,0,SEEK_SET);

	BITMAPFILEHEADER	p_bmp_file_header;
	BITMAPINFOHEADER	p_bmp_info_header;
	RGBQUAD				p_bmp_index[256];
	WORD				num;
	int					byte=0;
	int					i,j;
	BYTE				table[16];
	DWORD				index;

	//Read information
	fread(&p_bmp_file_header, sizeof(p_bmp_file_header), 1, fp);
	fread(&p_bmp_info_header, sizeof(p_bmp_info_header), 1, fp);


	//Type check
	if (p_bmp_file_header.bfType != 0x4D42){
		printf("Not bmp file\n");
		return FALSE;
	}

	// Compression check
	if (p_bmp_info_header.biCompression!=0){
		printf("Not support compression.\n");
		return FALSE;
	}

	//Load color palette
	bits = p_bmp_info_header.biBitCount;
	index = p_bmp_info_header.biClrUsed;
	if(p_bmp_info_header.biClrUsed==0){
		index = 1<<bits;
	}

	//Load color palette
	if(bits<=8){
		num = 1;
		for(i=0;i<bits;i++){
			num = num*2; 
		}
		for(i=0; i<num; i++){
			fread(&p_bmp_index[i], sizeof(RGBQUAD), 1, fp);
		}
	}
	else{
		return FALSE;
	}
	
	for(i=0; i<num;i++){
		if((p_bmp_index[i].rgbBlue==p_bmp_index[i].rgbGreen)&&(p_bmp_index[i].rgbBlue==p_bmp_index[i].rgbRed)){
			table[i] = ~p_bmp_index[i].rgbBlue;//gray
		}
		else{
			table[i] = 0;
		}
	}

	if(num==16){
		for(i=0; i<num; i++){
			table[i] = table[i]>>6;
			switch(LEVEL){
			case 2:
				table[i] = table[i]>>1;
				break;
			case 3:
				if(table[i]==3){
					table[i]--;
				}
				break;
			}
		}
		for(i=0; i<num; i++){
			for(j=0; j<num; j++){
				m_index[(i<<4)+j]=table[i]<<4|table[j];
			}
		}
	}
	else if(num==2){
		for(i=0; i<256; i++){
			if(table[0]==0){
				m_index[i]=i;
			}
			else{
				m_index[i]=(BYTE)(~i);
			}
		}
	}
	else{
		printf("The supported colors is 16bit index color or binary\n");
		return FALSE;
	}

	//Headder size
	offset  = p_bmp_file_header.bfOffBits;
	width	= p_bmp_info_header.biWidth;
	height	= p_bmp_info_header.biHeight;
	switch(bits){
		case 1:		byte = (width+7)/8;		break;
		case 2:		byte = (width*2+7)/8;	break;
		case 4:		byte = (width*4+7)/8;	break;
		case 8:		byte = width;			break;
		case 24:	byte = width*3;			break;
		case 32:	byte = width*4;			break;
	}
	byte_per_line = (byte+3)/4;
	byte_per_line *=4;

	if(width<NOZZLES){
		printf("Width is less than nozzles \n");
		return FALSE;
	}
	return TRUE;
}

BOOL CManageInkJet_KM::GetImageData(FILE *fp,BYTE* buf,int size,BOOL back)
{
	BOOL ok;
	fseek(fp,0,SEEK_SET);

	int width;
	int height;
	int offset;
	int bits;
	int byte_per_line;
	ok = GetImageProperty(fp,width,height,offset,bits,byte_per_line);
	if(!ok){
		return FALSE;
	}

	BYTE *image;
	image =(BYTE*)malloc(byte_per_line);		//Image Data
	if(image == NULL){
		printf("Error malloc\n");
		return FALSE;
	}

	int pos;
	if(back){
		//Read image from bottom
		pos = offset;
	}
	else{
		//Read image from top
		pos = (height-1) * byte_per_line + offset;
	}
	fseek(fp,pos,SEEK_SET);

	int count=height-1;

	BYTE temp;
	BYTE *img_temp;
	int i;
	while(size>0){
		//Read
		fread( image,  sizeof(BYTE),byte_per_line, fp);
		if(!back){
			fseek(fp,-byte_per_line*2,SEEK_CUR);
		}
		count--;
		if(count<0){
			size = 0;
		}
		//Convert
		if(bits==4){
			if ( LEVEL == 8 ) {
				memcpy( buf, image, byte_per_line );
				buf+=NOZZLES/2;
			}
			else {
				img_temp = image;
				for(i=0;i<NOZZLES;i++){
					*buf = *buf<<2;
					temp = (*img_temp&0x30) >> 4;
					*img_temp = *img_temp<<4;
					*buf |= temp;
					if((i%2)==1){
						img_temp++;
					}
					if((i%4)==3){
						buf++;
						size--;
					}
				}
			}
		}
		if(bits==1){
			img_temp = image;
			for(i=0;i<byte_per_line;i++){
				*img_temp = m_index[*img_temp];
				img_temp++;
			}
			memcpy(buf,image,NOZZLES/8);
			buf+=NOZZLES/8;
		}
	}
	free(image);
	return TRUE;
}