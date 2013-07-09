// CommandStruct_KM.h:
//
//////////////////////////////////////////////////////////////////////

#pragma once

enum command{
	IJCS1_COMMAND_DUMY	=0x10,						//0x10	//???
	IJCS1_COMMAND_RESET,							//0x11	//���Z�b�g
	IJCS1_COMMAND_SAVE_PARAM,						//0x12	//�p����??�ۑ�
	IJCS1_COMMAND_PRINT_START,						//0x13	//���J�n
	IJCS1_COMMAND_SET_HEAD_TYPE=0x20,				//0x20	//�w�b�h?�C�v�ݒ�
	IJCS1_COMMAND_ASSIGN_USE_HEAD,					//0x21	//�g�p�w�b�h�w��
	IJCS1_COMMAND_ASSIGN_FLUSH_USE_HEAD,			//0x22	//�t���b�V���O�g�p�w�b�h�w��
	IJCS1_COMMAND_SET_BASE_WAVE=0x30,				//0x30	//�x?�X�g?�ݒ�
	IJCS1_COMMAND_SET_DRIVE_WAVE,					//0x31	//�쓮�g?�ݒ�
	IJCS1_COMMAND_SET_HEAD_VOLT=0x40,				//0x40	//�w�b�h�d���ݒ�
	IJCS1_COMMAND_SET_HEAD_NOZZLE_VOLT_RATE,		//0x41	//�w�b�h�쓮�m�Y���d���ϓ����ݒ�
	IJCS1_COMMAND_ASSIGN_TEMP_VOLT=0x50,			//0x50	//�����x�d������w��
	IJCS1_COMMAND_SET_TEMP_VOLT_PARAM,				//0x51	//�����x�d���p����??�ݒ�
	IJCS1_COMMAND_SET_TEMP_VOLT_POINT,				//0x52	//�����x�d������?�C���g�ݒ�
	IJCS1_COMMAND_SET_HEAD_TEMP=0x60,				//0x60	//�w�b�h���x�ݒ�
	IJCS1_COMMAND_SELECT_FIRE=0x70,					//0x70	//�t?�C�A�I��
	IJCS1_COMMAND_SET_FTIME,						//0x71	//�������U�����ݒ�
	IJCS1_COMMAND_SET_ENCODER_ADJUST=0x80,			//0x80	//�G���R???�␳����ݒ�
	IJCS1_COMMAND_SET_ENCODER_ADJUST_LUT,			//0x81	//�G���R???�␳����k�t�s�ݒ�
	IJCS1_COMMAND_SELECT_Z_PHASE,					//0x82	//�G���R???�y���w��
	IJCS1_COMMAND_SELECT_ENCODER_PHASE_ADJUST,		//0x83	//�G���R???�␳���g���ϊ��I��
	IJCS1_COMMAND_SET_ENCODER_PHASE_ADJUST,			//0x84	//�G���R???�␳�i���g���ϊ��j�ݒ�
	IJCS1_COMMAND_SET_TRIGGER=0x90,					//0x90	//�y?�W�g���K?�ݒ�
	IJCS1_COMMAND_SET_FLUSHING_TRIGER,				//0x91	//�t���b�V���O�g���K?�ݒ�
	IJCS1_COMMAND_SET_PAGE_TRIGGER_ENABLE,			//0x92	//�y?�W�g���K?�L��?�����ݒ�
	IJCS1_COMMAND_SET_FLUSHING_TRIGGER_ENABLE,		//0x93	//�t���b�V���O�g���K?�L��?�����ݒ�
	IJCS1_COMMAND_GENERATE_TRIGGER,					//0x94	//?�t�g�E�F�A�g���K?����
	IJCS1_COMMAND_ACT_FLUSHING,						//0x95	//�t���b�V���O�g���K?����
	IJCS1_COMMAND_ABORT_PRINT,						//0x96	//��撆�f
	IJCS1_COMMAND_ABORT_FLUSHING,					//0x97	//�t���b�V���O���f
	IJCS1_COMMAND_SET_AUTO_TRIGER,					//0x98	//�I?�g�g���K?�ݒ�
	IJCS1_COMMAND_AUTO_TRIGGER_RESET,				//0x99	//�I?�g�g���K?���Z�b�g
	IJCS1_COMMAND_INIT_PHASE_FACT=0xa0,				//0xa0	//�ʑ��W���J�E��?�����l�ݒ�
	IJCS1_COMMAND_SET_PHASEFACT_TRIGGER,			//0xa1	//�ʑ��W���J�E��?�g���K�ݒ�
	IJCS1_COMMAND_SET_FLUSH_PHASE_TRIGGER_COUNTER,	//0xa2	//�t���b�V���O�p�ʑ��v���J�E��?�g���K�ݒ�
	IJCS1_COMMAND_SET_FLUSHING_PARAM=0xb0,			//0xb0	//�t���b�V���O�p����??�ݒ�
	IJCS1_COMMAND_SET_FLUSHING_MODE,				//0xb1	//�t���b�V���O��?�h�ݒ�
	IJCS1_COMMAND_SET_FLUSHING_NOZZLE,				//0xb2	//�t���b�V���O�m�Y���ݒ�
	IJCS1_COMMAND_SET_FLUSHING_PATTERN,				//0xb3	//�t���b�V���O�p??���ݒ�
	IJCS1_COMMAND_SET_FLUSHING_DATA,				//0xb4	//�t���b�V���O�f??�ݒ�
	IJCS1_COMMAND_SET_FIRE_ENCODER=0xc0,			//0xc0	//�w�b�h�t?�C�A�G���R???�����A��?��ݒ�
	IJCS1_COMMAND_SELECT_FIRE_PHASE,				//0xc1	//�w�b�h�t?�C�A�t�F?�Y�I��ݒ�
	IJCS1_COMMAND_SET_FIRE_STIME_TYPE,				//0xc2	//�w�b�h�t?�C�A �r����?�C�v�ݒ�
	IJCS1_COMMAND_SET_FIRE_STIME_FIXVALUE,			//0xc3	//�w�b�h�t?�C�A �r���ԌŒ�l�ݒ�
	IJCS1_COMMAND_SET_FIRE_STIME_CALCVALUE,			//0xc4	//�w�b�h�t?�C�A �r���ԉ��Z�l�i�����A��?�j�ݒ�
	IJCS1_COMMAND_SET_HEAD_DELAY=0xd0,				//0xd0	//�w�b�h�f�B���C�ݒ�
	IJCS1_COMMAND_SET_NOZZLE_DELAY_TIME,			//0xd1	//�m�Y���x�����Ԑݒ�
	IJCS1_COMMAND_SET_IMAGE_INFO=0xe0,				//0xe0	//?���摜���ݒ�
	IJCS1_COMMAND_SET_PRINT_INFO,					//0xe1	//���ݒ�
	IJCS1_COMMAND_SET_EXTERNAL_IO=0xf0,				//0xf0	//�O���h?�n�ݒ�
	IJCS1_COMMAND_SET_STB_ORDER,					//0xf1	//�r�s�a�����ݒ�
	IJCS1_COMMAND_NUM,
};

//?NOP ---------------------------------------------------------------------------
//	IJCS1_COMMAND_DUMY									0x10		// DUMMY
struct st_cmd_dummy {
	DWORD reserved;						//���U?�u
};

//?Reset ---------------------------------------------------------------------------
//	IJCS1_COMMAND_RESET									0x11		// Reset
struct st_cmd_reset {
	DWORD reserved;						//���U?�u
};

//?Save Parameter ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SAVE_PARAM							0x12		// Save Parameter
struct st_cmd_save_nv{
    DWORD target;		//�p����??�ۑ��Ώێw��i�s�a�c�j
    DWORD index;		//�C���f�b�N�X�i�ǉ��j
};

//?Print Start ---------------------------------------------------------------------------
//	IJCS1_COMMAND_PRINT_START							0x13		// Print Start
struct st_cmd_print_start{
	DWORD reserved;						//���U?�u
};

//?Set Head Type ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_HEAD_TYPE							0x20		// 
struct st_cmd_head_type {
	DWORD dbm_id;		//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD nozzle_num;	//�m�Y������	128,256,512,1024�̐��l���w�肵�Ă��������B
	DWORD nozzle_row;	//�m�Y����	1�F1��A2�F2��������܂��B
	DWORD drive_type;	//�쓮?�C�v	1�F�͓Ɨ��쓮�A3�F��3���쓮�������܂��B
	DWORD kmdb_type;	//KMDB���	0:KMDB-S?�iTBD)�A1:KMDB-L?�iTBD)�A2:KMDB-L01A?�iTBD)
};

//?Assing Use Head ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ASSIGN_USE_HEAD						0x21		// Assing Use Head
struct st_cmd_head_use {
	DWORD dbm_id;		//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD head_use;		//�w�b�h�g�p	0�F�s�g�p�A1�g�p�������܂��B
};

//?Assing Flushing Use Head ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ASSIGN_FLUSH_USE_HEAD					0x22		// Assing Flushing Use Head
struct st_cmd_flush_head_use {
	DWORD dbm_id;		//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD row;			//��	?�O�FL��?�P�FR��
	DWORD head_use;		//�w�b�h�g�p	0�F�s�g�p�A1�g�p�������܂��B
};

//?Set Base Wave ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_BASE_WAVE							0x30		// 
struct st_cmd_base_wave {
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	wave_id;		//�g?�ԍ��i�O�F�g?A?�P�F�g?B)
	DWORD	swdev;			//�x?�X�g?������Ԑ����w�肵�܂��B(1-8)?�w�肵���l���ɂ��ȉ���swv(n)�Aswt(n)�܂ł̐ݒ肪�L���ƂȂ�B
	DWORD	swv1;			//��ԂP�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt1;			//��ԂP�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv2;			//��ԂQ�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt2;			//��ԂQ�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv3;			//��ԂR�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt3;			//��ԂR�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv4;			//��ԂS�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt4;			//��ԂS�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv5;			//��ԂT�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt5;			//��ԂT�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv6;			//��ԂU�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt6;			//��ԂU�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv7;			//��ԂV�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt7;			//��ԂV�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	swv8;			//��ԂW�̓d���� 0x00:0V?0x01:OFF�d��?0x02 : ON�d���Ŏw�肵�܂��B
	DWORD	swt8;			//��ԂW�̋�Ԏ��Ԃ�1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
	DWORD	droplet_time;	//Droplet-Time��1nsec�P�ʂŐݒ肵�܂��Bex)10.0usec=0x2710
};

//?Set Drive Wave ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_DRIVE_WAVE						0x31		// 
struct st_cmd_drive_wave {
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	level_num;		//�K����	2?8�̐��l���w�肵�Ă��������B
	DWORD	sw_sel1;		//�g?�I��	�ŏ��ɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
							//1:���̃x?�X�g?�I��?2:���̃x?�X�g?�I��
							//3:��O�̃x?�X�g?�I��?0:�I�𖳂�
	DWORD	sw_sel2;		//�g?�I��	�Q�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel3;		//�g?�I��	�R�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel4;		//�g?�I��	�S�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel5;		//�g?�I��	�T�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel6;		//�g?�I��	�U�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel7;		//�g?�I��	�V�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel8;		//�g?�I��	�W�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel9;		//�g?�I��	�X�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel10;		//�g?�I��	�P�O�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel11;		//�g?�I��	�P�P�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel12;		//�g?�I��	�P�Q�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel13;		//�g?�I��	�P�R�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel14;		//�g?�I��	�P�S�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel15;		//�g?�I��	�P�T�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	sw_sel16;		//�g?�I��	�P�U�ԖڂɑI�ԃx?�X�g?�̎�ނ�ݒ肵�܂��B
	DWORD	img0_num;		//�摜�f??�O�̎��̔g?�I���ʒu���w�肵�܂��B
							//��L�g?�I���Őݒ肳�ꂽ�g?�̂ǂ��܂ł𗘗p���邩���w�肵�܂��B�i�O?�P�U���w��j
							//�O�̂Ƃ��g?�o�͍͂s���܂���B
	DWORD	img1_num;		//�摜�f??�P�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img2_num;		//�摜�f??�Q�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img3_num;		//�摜�f??�R�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img4_num;		//�摜�f??�S�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img5_num;		//�摜�f??�T�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img6_num;		//�摜�f??�U�̎��̔g?�I���ʒu���w�肵�܂��B?
	DWORD	img7_num;		//�摜�f??�V�̎��̔g?�I���ʒu���w�肵�܂��B?
};

//?Set Head Voltage ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_HEAD_VOLT							0x40		// 
struct st_cmd_head_voltage{
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	on_volt_num;	//�n�m�d�����i�P?�W?�ő�W���z��j
	DWORD	off_volt_num;	//�n�e�e�d�����i�P?�W?�ő�W���z��j
	DWORD	head_on[8];		//ͯ��On?4000~20000[4.0?20.0V]�܂ł̐��l���w�肵�܂��B1mV�P�ʂł��B
	DWORD	head_off[8];	//ͯ��Off 4000~20000[4.0?20.0V]�܂ł̐��l���w�肵�܂��B1mV�P�ʂł��B
};

//?Set Head Nozzle Volt Rate ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_HEAD_NOZZLE_VOLT_RATE				0x41		// 
struct st_cmd_nozzle_voltage {
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	l_nozzle_num;	//�k��ϓ����f??���i�s�g�p�̏ꍇ�O��ݒ�j
	DWORD	r_nozzle_num;	//�q��ϓ����f??���i�s�g�p�̏ꍇ�O��ݒ�j
	DWORD	l_volt[1024];	//�k��ϓ����f??�i�ő�P�O�Q�S�j
	DWORD	r_volt[1024];	//�q��ϓ����f??�i�ő�P�O�Q�S�j
};

//?Assign Temp Voltage ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ASSIGN_TEMP_VOLT						0x50		// 
struct st_cmd_temp_volt_ctrl {
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	ctrl;			// 0:�����?, 1:����J�n
};

//?Set Temp Voltage Parameter ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_TEMP_VOLT_PARAM					0x51		// 
struct st_cmd_temp_volt_param {
	DWORD	dbm_id;				//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;			//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	head_time;			// �T??�X?�d���擾����?�i�P��msec�j?50msec?60sec
	DWORD	head_change_max;	// �ő�d���ω���?�i�P��0.01V�j?0.05V?20.00V
};

//?Set Temp Voltage Point ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_TEMP_VOLT_POINT					0x52		// 
struct st_curve_para {
	DWORD	head_temp;		// �w�b�h���x	0��~60���܂ł̐��l���w�肵�܂��B�P�ʂ�0.01���ł��B
							//		0?6000�̒l��ݒ�
							// �����������݂̗L��������0.1���P�ʂƂȂ�܂��B
	DWORD	head_volt; 		// �w�b�h�d���W��	0.50??1.50?�܂ł̐��l���w�肵�܂��B
							// �P�ʂ�0.01?�ł��B  50?150�܂ł̒l��ݒ�
};
struct st_cmd_temp_volt_curve_param {
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	set_num;		//�p����??�ݒ萔?2?25
							// �w�肵���l���ɂ��A�ȉ���para�f??�̌����L���ƂȂ�B
	st_curve_para para[25];	//?�p����??
};

//?Set Head Temperature ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_HEAD_TEMP							0x60		// 
struct st_cmd_head_temperature{
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	head_act;		//�w�b�h����	1�F���x���䂵�܂��B1�ȊO�F���x���䂵�܂���B
	DWORD	head_temp;		//�w�b�h���x	11~55�܂ł̐��l���w�肵�܂��B�P�ʂ�1���ł��B
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SELECT_FIRE							0x70		// �t?�C�A�I��
struct st_cmd_sel_fire {
	DWORD mode;							//0�FA�������オ��A1�FB�������オ��A2�F�������U�𗘗p
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FTIME								0x71		// �������U�����ݒ�
struct st_cmd_set_ftime {
	DWORD time;							//�t?�C�A������nsec�P�ʂŐݒ肷��B?25?820000nsec
};

//?Set Encoder Adjust ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_ENCODER_ADJUST					0x80		// 
struct st_cmd_encoder_adjust{
	DWORD enabler;			//�G���R???�␳�L��?����?�O�F����?�P�F�L��
};

//?Set Encoder Adjust LUT ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_ENCODER_ADJUST_LUT				0x81		// 
struct  st_cmd_encoder_lut {
	DWORD adjust_lut;		//�G���R???�␳�k�t�s
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SELECT_Z_PHASE						0x82		// 1-17. �G���R???�y���w��
struct st_cmd_select_zphase {
	DWORD mode;							//��?�h
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SELECT_ENCODER_PHASE_ADJUST			0x83		//�G���R???�␳���g���ϊ��I�� 
struct st_cmd_select_encoder_phase_adjust {
	DWORD enable;						//�G���R???�␳�L��?����?�O�F����?�P�F�L��
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_ENCODER_PHASE_ADJUST				0x84		// �G���R???�␳���g���ϊ��ݒ�
struct st_cmd_set_encoder_phase_adjust {
	DWORD adjust_value;					//�G���R???�␳�i���g���ϊ��j�␳�l
};

//?Set Trigger ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_TRIGGER							0x90		// �y?�W�g���K?�ݒ�
struct st_trigger_select{
	DWORD trigger;			//�g���K?�w��	0�F�O���g���K?�����オ��G�b�W�A
							//				�P�F�O���g���K?����������G�b�W�A
							//				�Q�F�ʑ��v���g���K?�������܂��B
	DWORD mode;				//�g���K?��?�h?�O�F�����V���b�g
							//				?�P�F�I?�g�g���K?
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_TRIGER					0x91		// �t���b�V���O�g���K?�ݒ�
struct st_cmd_set_flush_trigger {
	DWORD trigger;						//�g���K?�w��?�O�F�O���g���K?�����オ��G�b�W
										//		�P�F�O���g���K?����������G�b�W
										//		�Q�F�ʑ��v���J�E��?�g���K?
};

//?Set Page Trigger Enable ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_PAGE_TRIGGER_ENABLE				0x92		// �y?�W�g���K?�L��?�����ݒ�
struct st_cmd_trigger_enable{
	DWORD enable;		//�g���K?�L��?�����ݒ�?�O�F�g���K?����?�P�F�g���K?�L��
};

//?Set Flushing Trigger Enable ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_TRIGGER_ENABLE			0x93		// �t���b�V���O�g���K?�L��?�����ݒ�
struct st_cmd_flush_trigger_enable{
	DWORD enable;		//�g���K?�L��?�����ݒ�?�O�F�g���K?����?�P�F�g���K?�L��
};

//?Generate Trigger ---------------------------------------------------------------------------
//	IJCS1_COMMAND_GENERATE_TRIGGER						0x94		// ?�t�g�E�F�A�g���K?����
struct st_cmd_manual_trigger{
	DWORD reserved;			//���U?�u
};

//?Action Flushing ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ACT_FLUSHING							0x95		// �t���b�V���O�g���K?����
struct st_cmd_manual_flush{
	DWORD cntl;			//�J�n�A��?�w��?�O�F��??�P�F�J�n
};

//?Abort Print ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ABORT_PRINT							0x96		// ��撆�f
struct st_cmd_abort_print{
	DWORD reserved;						//���U?�u
};

//?Abort Print ---------------------------------------------------------------------------
//	IJCS1_COMMAND_ABORT_FLUSHING						0x97		//�t���b�V���O���f
struct st_cmd_abort_flush{
	DWORD reserved;						//���U?�u
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_AUTO_TRIGER						0x98		// �I?�g�g���K?�ݒ�
struct st_cmd_set_auto_trigger {
	DWORD repeat;						//�J��Ԃ���???�P?�U�T�T�R�U
	DWORD interval;						//�g���K?�Ԋu??�P?�P�O�S�W�T�V�U
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_AUTO_TRIGGER_RESET					0x99		// �I?�g�g���K?���Z�b�g
struct st_cmd_reset_auto_trigger {
	DWORD cntl;			//���Z�b�g�w�����i���g�p�j
};

//?Initial Phase Fact ---------------------------------------------------------------------------
//	IJCS1_COMMAND_INIT_PHASE_FACT						0xa0		// 
struct st_phase_counter_initialize{
	DWORD initial_count;	//�ʑ��W���J�E��??�����l		0~16777215�܂ł̐��l���w�肵�܂��B
};

//?Set Pasefact Trigger ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_PHASEFACT_TRIGGER					0xa1		// 
struct st_trigger_encoder{ 
	DWORD trigger_id;		//�g���K?�w��		�g���K?�ԍ����w�肵�܂��B�Oor�P�łQ��ނ̃g���K��ݒ�ł��܂��B
	DWORD trigger_mode;		//�g���K?�w�胂?�h		0�FOFF�A1�FUP�A2�FDOWN�������܂��B
	DWORD trigger_count;	//�g���K?�w��J�E��??�l	0~16777215�܂ł̐��l���w�肵�܂��B
};

//?Set Flushing Phase Trigger Counter ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSH_PHASE_TRIGGER_COUNTER		0xa2		// �t���b�V���O�p�ʑ��v���J�E��?�g���K�ݒ�
struct st_flushtrigger_phase_counter{
	DWORD trigger_id;		//�g���K?�w��		�g���K?�ԍ����w�肵�܂��B�Oor�P�łQ��ނ̃g���K��ݒ�ł��܂��B
	DWORD trigger_mode;		//�g���K?�w�胂?�h		0�FOFF�A1�FUP�A2�FDOWN�������܂��B
	DWORD trigger_count;	//�g���K?�w��J�E��??�l	0~16777215�܂ł̐��l���w�肵�܂��B
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_PARAM				0xb0		// �t���b�V���O�p����??�ݒ�
struct st_cmd_set_flush_param {
	DWORD dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;						//�j�l�c�a��ԍ��i�O?�R�j
	DWORD count;						//�f�o�񐔁i��j�P?�U�T�T�R�T
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_MODE					0xb1		// �t���b�V���O��?�h�ݒ�
struct st_cmd_flush_mode {
	DWORD dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;						//�j�l�c�a��ԍ��i�O?�R�j
	DWORD mode;							//��?�h?�O�F�t���b�V���O���Ȃ�
										//	?�P�F�S�m�Y��
										//	?�Q�F�C�ӂ̂P�m�Y���i��q�̃m�Y���ݒ�̒l���L���j
										//	?�R�F�p??���i��q�̃p??�����L���j
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_NOZZLE				0xb2		// �t���b�V���O�m�Y���ݒ�
struct st_cmd_flush_nozzle {
	DWORD dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;						//�j�l�c�a��ԍ��i�O?�R�j
	DWORD nozzle;						//�m�Y���ԍ�?�P?�P�O�Q�S
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_PATTERN				0xb3		// �t���b�V���O�p??���ݒ�
struct st_cmd_flush_pattern {
	DWORD dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;						//�j�l�c�a��ԍ��i�O?�R�j
	DWORD pattern;						//�p??��?�i���ʂP�U�r�b�g�L���j
	DWORD repeat_bit;					//�J��Ԃ��r�b�g��?�P?�P�U
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FLUSHING_DATA				0xb4		// �t���b�V���O�f??�ݒ�
struct st_cmd_flush_data {
	DWORD dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;						//�j�l�c�a��ԍ��i�O?�R�j
	DWORD data;							//�t���b�V���O�f???�i�O?�V�j};
};

//?Set Fire Encoder ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FIRE_ENCODER						0xc0		// �w�b�h�t?�C�A�G���R???�����A��?��ݒ�
struct st_fire_encoder{
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD multiply;			// ��??n = 0 to 1023  multiply(n+1)
	DWORD divider;			// ����?n = 0 to 1023  divide (n+1)
};

//?Select Fire Phase ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SELECT_FIRE_PHASE						0xc1		// 
struct st_phase_select{
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	use;			//�t�F?�Y�I��??�L��
	DWORD	phase_max;		//�ő�t�F?�Y�l�i�P?�P�U�j
	DWORD	phase_num;		//�I���t�F?�Y���i�P?�P�U�j?���L�t�F?�Y�I���̗L����
	DWORD	phase_sel1;		//�P�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel2;		//�Q�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel3;		//�R�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel4;		//�S�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel5;		//�T�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel6;		//�U�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel7;		//�V�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel8;		//�W�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel9;		//�X�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel10;	//�P�O�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel11;	//�P�P�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel12;	//�P�Q�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel13;	//�P�R�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel14;	//�P�S�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel15;	//�P�T�X�L�����ڂ̃t�F?�Y�I��
	DWORD	phase_sel16;	//�P�U�X�L�����ڂ̃t�F?�Y�I��
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FIRE_STIME_TYPE				0xc2		// �w�b�h�t?�C�A �r����?�C�v�ݒ�
struct st_cmd_fire_stime_type {
	DWORD	dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;					//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	type;						//�r����?�C�v�w��
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FIRE_STIME_FIXVALUE			0xc3		// �w�b�h�t?�C�A �r���ԌŒ�l�ݒ�
struct st_cmd_fire_stime_fixvalue {
	DWORD	dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;					//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	time;						//�r���ԌŒ�l
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_FIRE_STIME_CALCVALUE			0xc4		// �w�b�h�t?�C�A �r���ԉ��Z�l�i�����A��?�j�ݒ�
struct st_cmd_fire_stime_calcvalue {
	DWORD	dbm_id;						//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;					//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	multiply;					// ��??n = 0 to 1023  multiply(n+1)?��?1 to 31
	DWORD	divider;					// ����?n = 0 to 1023  divide (n+1) ?��?1 to 255
};

//?Set Head Deley ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_HEAD_DELAY						0xd0		// �w�b�h�f�B���C�ݒ�
struct st_cmd_head_delay{ 
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	dir;			//�����w��	�������w�肵�܂��B
							//�Oor�P�łQ��ނ̕�����ݒ�ł��܂��B
	DWORD	headl_delay;	//�w�b�hL��	�f�B���C?0~65535�܂ł̐��l���w�肵�܂��B
	DWORD	headl_subpixel;	//�w�b�hL��	�T�u�s�N�Z��1/16�P�ʂŎw��0-15
	DWORD	headr_delay;	//�w�b�hR��	�f�B���C?0~65535�܂ł̐��l���w�肵�܂��B
	DWORD	headr_subpixel;	//�w�b�hR��	�T�u�s�N�Z��1/16�P�ʂŎw��0-15
};

//?Set Nozzle Deley Time ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_NOZZLE_DELAY_TIME						0xd1		// �m�Y���x�����Ԑݒ�
struct st_cmd_nozzle_delay{ 
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	l_nozzle_num;	//�k��x�����ԃf??���i�s�g�p�̏ꍇ�O��ݒ�j
	DWORD	r_nozzle_num;	//�q��x�����ԃf??���i�s�g�p�̏ꍇ�O��ݒ�j
	DWORD	l_delay[1024];	//�k��x�����ԃf??�i�ő�P�O�Q�S�j
	DWORD	r_delay[1024];	//�q��x�����ԃf??�i�ő�P�O�Q�S�j
};

//?Set Image Information ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_IMAGE_INFO						0xe0		// ?���摜���ݒ�
struct st_cmd_image_info{
	DWORD	dbm_id;			//�c�a�l��ԍ��i�O?�R�j
	DWORD	kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	depth;			//������?��	�摜�̃�����?��?�����w�肵�܂��B
							//		�摜��bit�����w�肵�܂��B
							//		1,2,4���w�肵�Ă��������B
	// Delete Y.Musha 2011.10.19
//	DWORD	width;			//�摜��	�摜�̕��i�P�񂠂���̃m�Y�����j���w�肵�܂��B
	DWORD	length;			//�摜����	�摜�̒������w�肵�܂��B
};

//?Set Print Information ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_PRINT_INFO						0xe1		// ���ݒ�
struct st_cmd_print_info{
//	DWORD	dbm_id;		//�c�a�l��ԍ��i�O?�R�j
//	DWORD	kmdb_id;	//�j�l�c�a��ԍ��i�O?�R�j
	DWORD	mode;		//�o����?�Е������w��?�O�F�Е������?�P�F�o�������
	DWORD	reserve;	//reserve
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_EXTERNAL_IO					0xf0		// �O���h?�n�ݒ�
struct st_cmd_external_io {
	DWORD mode;							//�O���h?�n�ݒ胂?�h
};

//? ---------------------------------------------------------------------------
//	IJCS1_COMMAND_SET_STB_ORDER					0xf1		// �r�s�a�����ݒ�
struct st_cmd_stb_order {
	DWORD dbm_id;		//�c�a�l��ԍ��i�O?�R�j
	DWORD kmdb_id;		//�j�l�c�a��ԍ��i�O?�R�j
	DWORD l_for[3];		//L�񉝘H�P?�R���I��??�O�FA��?�P�FB��?�Q�FC��
	DWORD l_rev[3];		//L�񕜘H�P?�R���I��??�O�FA��?�P�FB��?�Q�FC��
	DWORD r_for[3];		//R�񉝘H�P?�R���I��??�O�FA��?�P�FB��?�Q�FC��
	DWORD r_rev[3];		//R�񕜘H�P?�R���I��??�O�FA��?�P�FB��?�Q�FC��
};
