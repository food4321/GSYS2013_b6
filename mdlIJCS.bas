Attribute VB_Name = "KM"
'#Define MMB_INFO_MAX 16 // �����ƫ������MMB��?
'#Define DBM_INFO_MAX 4 // MMB�����Ҫ��������DBM��?
'#Define KMDB_INFO_MAX 4 // DBM�����Ҫ��������KMDB��?


'Public Declare Function DLL_Open Lib "D:\LHJ_Work\PI_Alpha_Sys\MainUI\KM_HeadIF\IJCS1_DLL.dll" () As Boolean


Const MMB_INFO_MAX As Integer = 16
Const DBM_INFO_MAX As Integer = 4
Const KMDB_INFO_MAX As Integer = 4

Type ijcs_dbminfo
    k As Integer
End Type

Type st_cmd_dummy
    Reserved As Double '// ����
End Type

Type st_cmd_reset
    Reserved As Double '// ����
End Type

Type st_cmd_save_nv
    target As Double '// �Ķ���� ���� ��� ���� (TBD)
    Index As Double  '// �� target���� �ε����� �����մϴ�. (DBM : 0-3 KMDB : 0 ~ 15)
End Type

Type st_cmd_print_start
    Reserved As Double '// ����
End Type

Type st_cmd_head_type
    dbm_id As Double            '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double           '// KMDB ���� ��ȣ (0 ~ 3)
    nozzle_num As Double        '// ���� �� 128,256,512,1024 ���ڸ� �Է��Ͻʽÿ�.
    nozzle_row As Double        '// ���� �� �� 1:1 �� 2:2 ���� ��Ÿ���ϴ�.
    drive_type As Double        '// ���� Ÿ�� 1 : ���� ����, 3 : 3 �� ������ �����ݴϴ�.
    KMDB_type As Double         '/ KMDB ���� 0 : KMDB-S01A (TBD)
                                            '1:  KMDB -L01A(TBD)
                                            '2:  KMDB -L02A(TBD)
                                            '3:  KMDB -D01A(TBD)
End Type

Type st_head_use
    dbm_id  As Double   '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    head_use As Double  '// ��� ��� 0 : �̻��, 1 ����� �����ݴϴ�.
End Type

Type st_flush_mode
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    row As Double       '// �� 0 : L �� 1 : R ��
                        '(1 �� ����� ��� L �� ���� �ݿ��ȴ�)
    enable As Double    '// Ȱ��ȭ / ��Ȱ��ȭ 0 : �÷������� 1 : �÷����Ѵ�.

End Type

Type st_cmd_Base_wave
    dbm_id As Double        '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double       '// KMDB ���� ��ȣ (0 ~ 3)
    wave_id As Double       '// ���� ��ȣ (0 : ���� A 1 : ���� B)
    swdev As Double         '// �⺻ ���� ���� ���� ���� �����մϴ�. (1-8)          ������ �� n�� ���� ���� swv (n) swt (n)������ ������ ��ȿ�ϴ�.
    swv1 As Double          '// ���� 1�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt1 As Double          '// ���� 1 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv2 As Double          '// ���� 2�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt2 As Double          '// ���� 2 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv3 As Double          '// ���� 3�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt3 As Double          '// ���� 3 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv4 As Double          '// ���� 4�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt4 As Double          '// ���� 4 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv5 As Double          '// ���� 5�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt5 As Double          '// ���� 5 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv6 As Double          '// ���� 6 ������ ����. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt6 As Double          '// ���� 6 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv7 As Double          '// ���� 7�� ������ �����մϴ�. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt7 As Double          '// ���� 7 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    swv8 As Double          '// ���� 8 ������ ����. 0x00 : 0V 0x01 : OFF ���� 0x02 : ON ����
    swt8 As Double          '// ���� 8 ���� �ð��� 1nsec ������ ����. ex) 10.0usec = 0x2710
    droplet_time As Double  '// droplet-time�� 1nsec ������ ����. ex) 10.0usec = 0x2710
End Type

Type st_cmd_head_wave
    dbm_id As Double        '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double       '// KMDB ���� ��ȣ (0 ~ 3)
    level_num As Double     '// ���� �� 2-8 ���ڸ� �Է��Ͻʽÿ�.
    sw_sel1 As Double       '// ���� ���� ���� ���� ���� ������ ������ �����մϴ�. 1 : ù ��° ��� ���� ���� 2 : �� ��° ��� ���� ���� 3 : ����° ��� ���� ���� 0 : ���� ����
    sw_sel2 As Double       '// ���� ���� �� ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel3 As Double '// ���� ���� 3 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel4 As Double '// ���� ���� 4 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel5 As Double '// ���� ���� 5 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel6 As Double '// ���� ���� 6 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel7 As Double '// ���� ���� 7 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel8 As Double '// ���� ���� 8 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel9 As Double '// ���� ���� 9 ��°�� ���� ��� ������ ������ �����մϴ�.
    sw_sel10 As Double '// ���� ���� 10 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel11 As Double '// ���� ���� 11 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel12 As Double '// ���� ���� 12 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel13 As Double '// ���� ���� 13 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel14 As Double '// ���� ���� 14 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel15 As Double '// ���� ���� 15 ��° ���� ���� ������ ������ �����մϴ�.
    sw_sel16 As Double '// ���� ���� 16 ��° ���� ���� ������ ������ �����մϴ�.
    img0_num As Double '// �̹��� ������ 0���� ���� ���� ��ġ�� �����մϴ�. �� ���� ���� ���� �� ������ �������� ������� ���θ� �����մϴ�. (0 ~ 16 ����) 0 �� �� ���� ��µ��� �ʽ��ϴ�.
    img1_num As Double '// �̹��� ������ 1 �ð� ���� ���� ��ġ�� �����մϴ�.
    img2_num As Double '// �̹��� ������ 2 �ð� ���� ���� ��ġ�� �����մϴ�.
    img3_num As Double '// �̹��� ������ 3 ���� ���� ���� ��ġ�� �����մϴ�.
    img4_num As Double '// �̹��� ������ 4 �ð� ���� ���� ��ġ�� �����մϴ�.
    img5_num As Double '// �̹��� ������ 5 �ð� ���� ���� ��ġ�� �����մϴ�.
    img6_num As Double '// �̹��� ������ 6 �ð� ���� ���� ��ġ�� �����մϴ�.
    img7_num As Double '// �̹��� ������ 7�� ���� ���� ��ġ�� �����մϴ�.
End Type

Type st_cmd_head_voltage
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    on_volt_num As Double '// ON ���� ���� (1 ~ 8 �ִ� 8 ���� ����)
    off_volt_num As Double '// OFF ���� ���� (1 ~ 8 �ִ� 8 ���� ����)
    head_on(7) As Double '// On 4000 ~ 20000 [4.00 ~ 20.00V] ������ ���ڸ� �����մϴ�. 1mV �����Դϴ�. (D01A�� ��� [4.00 ~ 40.00])
    head_off(7) As Double '// Off 4000 ~ 20000 [4.00 ~ 20.00V] ������ ���ڸ� �����մϴ�. 1mV �����Դϴ�. (D01A�� ��� [4.00 ~ 40.00])
End Type

Type st_cmd_nozzle_voltage
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    l_nozzle_num As Double '// L �� ������ ������ ���� (�̻���� ��� 0���� ����)
    r_nozzle_num As Double '// R �� ������ ������ ���� (�̻���� ��� 0���� ����)
    l_volt(1023) As Double '// L �� ������ ������ (�ִ� 1024 ��)
    r_volt(1023) As Double '// R �� ������ ������ (�ִ� 1024 ��)
End Type

Type st_cmd_temp_volt_ctrl
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    ctrl As Double '// 0 : ���� ����, 1 : ���� ����
End Type

Type st_cmd_temp_volt_param
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    head_time As Double '// ���̽��� ���� �����ֱ� (���� msec) 50msec ~ 60sec
    head_change_max As Double '// �ִ� ���� ��ȭ�� (���� 0.01V) 0.05V ~ 20.00V
End Type

Type st_curve_para
    head_temp As Double '// ��� �µ� 0 ~ 60 �� ������ ���ڸ� �����մϴ�. ������ 0.01 ��. 0 ~ 6000�� ���� ����,  �� �ٸ� ���� �ڸ����� 0.1 �� �����Դϴ�.
    head_volt As Double '// ��� ���� ��� 0.50 �� ~ 1.50 �� ������ ���ڸ� �����մϴ�. ������ 0.01 ���Դϴ�. 50 ~ 150 ������ ���� ����
End Type

Type st_cmd_temp_volt_curve_param
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    set_num As Double '// �Ķ���� ���� ���� 2 ~ 25, ������ �� n�� ���� para �������� ������ ��ȿ�ϴ�.
    st_curve_para(25) As Double '// �Ű� ����
End Type

Type st_cmd_head_temperature
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    head_act As Double '// ��� ���� 1 : �µ� �����մϴ�. 1 �̿� : �µ� �������� �ʽ��ϴ�.
    head_temp As Double '// ��� �µ� 15.0 ~ 55.0 ������ ���ڸ� �����մϴ�. ������ 0.1 ���Դϴ�.
End Type

Type st_cmd_firesel
    mode As Double '// 0 : A �� ���, 2 : ���� ������ �̿� 3 : AB �� �� �����ڸ��� ���
End Type

Type st_cmd_ftime
    time As Double '// ���̾��ֱ⸦ nsec ������ �����Ѵ�. 25 ~ 820000nsec
End Type

Type st_cmd_outfire_select
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    lr  As Double       '// �� ���� 0 : L �� 1 : R ��
End Type

Type st_cmd_encoder_LUT_adjust
    enable As Double '// ���ڴ� ���� Ȱ��ȭ / ��Ȱ��ȭ 0 : ��ȿ 1 : ��ȿ
End Type

''''''Type st_cmd_encoder_LUT
''''''End Type

Type st_cmd_encoder_zphase
    mode  As Double
End Type

Type st_cmd_encoder_phase_adjust
    enable As Double '// ���ڴ� ���� Ȱ��ȭ / ��Ȱ��ȭ 0 : ��ȿ 1 : ��ȿ
End Type

Type st_cmd_encoder_phase_param
    adjust_value As Double '// ���ڴ� ���� (���ļ� ��ȯ) ���� ��
End Type

Type st_trigger_select
    trigger As Double   '// Ʈ���� ���� 0 : �ܺ� Ʈ���� ��� ����, 1 : �ܺ� Ʈ���� �ϰ� ����, 2 : ���� ��� ī���� Ʈ����
    mode As Double      '// Ʈ���� ��� 0 : ����, 1 : �ڵ� Ʈ���� - TBD
End Type

Type st_flush_trigger_select
    trigger As Double '// Ʈ���� ���� 0 : �ܺ� Ʈ���� ��� ����, 1 : �ܺ� Ʈ���� �ϰ� ����, 2 : ���� ��� ī���� Ʈ����
End Type

Type st_cmd_trigger_enable
    enable As Double '// Ʈ���� Ȱ��ȭ / ��Ȱ��ȭ ���� 0 : Ʈ���� ��Ȱ��ȭ 1 : Ʈ���� Ȱ��ȭ
End Type

Type st_cmd_flush_trigger_enable
    enable As Double '// Ʈ���� Ȱ��ȭ / ��Ȱ��ȭ ���� 0 : Ʈ���� ��Ȱ��ȭ 1 : Ʈ���� Ȱ��ȭ
End Type

Type st_cmd_manual_trigger
    Reserved As Double '// ����
End Type

Type st_cmd_manual_flush_trigger
    Reserved As Double '// ����
End Type

Type st_cmd_abort_print
    Reserved As Double '// ����
End Type

Type st_cmd_abort_flush
    Reserved As Double '// ����
End Type

Type st_autotrigger_param
    repeat As Double '// �ݺ� �� 1 ~ 65536
    Interval As Double '// Ʈ���� ���� 1 ~ 1048576
End Type

Type st_cmd_autotorigger_reset
    cntl As Double '// ���� ���� ����
End Type

Type st_phase_counter_initialize
initial_count As Double '// ���� ��� ī���� �ʱ� �� (0 ~ 16777215)
End Type

Type st_printtrigger_phase_counter
    trigger_id As Double '// Ʈ���� ���� Ʈ���� ��ȣ�� �����մϴ�. (0-1)
    trigger_mode As Double '// Ʈ���� ���� ��� 0 : OFF, 1 : UP 2 : DOWN�� �����ݴϴ�.
    trigger_count As Double '// Ʈ���� ���� ī���� �� (0 ~ 16777215)
End Type

Type st_flushrigger_phase_counter
    trigger_id As Double '// Ʈ���� ���� Ʈ���� ��ȣ�� �����մϴ�. (0-1)
    trigger_mode As Double '// Ʈ���� ���� ��� 0 : OFF, 1 : UP 2 : DOWN�� �����ݴϴ�.
    trigger_count As Double '// Ʈ���� ���� ī���� �� (0 ~ 16777215)
End Type

Type st_flush_param
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    count As Double '// ���� Ƚ�� (ȸ) 1 ~ 65535
End Type

''''''''''''''Type st_flush_mode
''''''''''''''    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
''''''''''''''    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
''''''''''''''    mode As Double '// ��� 0 : ���ǵ��� ����, 1 : ��� ����, 2 : � 1 ���� (�Ʒ� ���� ���� ���� ��ȿ), 3 : ���� (�Ʒ� ������ ���)
''''''''''''''End Type

Type st_flush_nozzle
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    nozzle As Double '// ��ȣ ���� 1 ~ 1024
End Type

Type st_flush_pattern
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    pattern As Double '// ���� (���� 16 ��Ʈ ���)
    repeat_bit As Double '// �ݺ� ��Ʈ 1 ~ 16
End Type

Type st_flush_pattern_data
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    Data As Double '// �÷��� ������ (0 ~ 7)
End Type

Type st_fire_select
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    multiply As Double  '// ü n = 1 to 127 multiply
    divider As Double '// ���� n = 1 to 1023 divide
End Type

Type st_phase_select
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    use As Double '// ���� ���� ��� Ȱ��ȭ
    phase_max As Double '// �ִ� ���� �� (1-16)
    phase_num As Double '// ���� �ܰ� �� (1-16) �Ʒ� �ܰ� ���� ��� ����
    phase_sel1 As Double '// 1 ��ĵ ��° �ܰ� ����
    phase_sel2 As Double '// 2 �˻� ��° �ܰ� ����
    phase_sel3 As Double '// 3 ��ĵ ��° �ܰ� ����
    phase_sel4 As Double '// 4 ��ĵ ��° �ܰ� ����
    phase_sel5 As Double '// 5 ��ĵ ��° �ܰ� ����
    phase_sel6 As Double '// 6 ��ĵ ��° �ܰ� ����
    phase_sel7 As Double '// 7 ��ĵ ��° �ܰ� ����
    phase_sel8 As Double '// 8 ��ĵ ��° �ܰ� ����
    phase_sel9 As Double '// 9 ��ĵ ��° �ܰ� ����
    phase_sel10 As Double '// 10 �˻� ��° �ܰ� ����
    phase_sel11 As Double '// 11 �˻� ��° �ܰ� ����
    phase_sel12 As Double '// 12 �˻� ��° �ܰ� ����
    phase_sel13 As Double '// 13 �˻� ��° �ܰ� ����
    phase_sel14 As Double '// 14 �˻� ��° �ܰ� ����
    phase_sel15 As Double '// 15 �˻� ��° �ܰ� ����
    phase_sel16 As Double '// 16 �˻� ��° �ܰ� ����
End Type

Type st_fire_stime_type
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    type As Double      '// s �ð� ���� ����
End Type

Type st_fire_stime_fixvalue
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    time As Double      '// s �ð� ���� ��
End Type

Type st_fire_stime_calcvalue
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    multiply As Double '// ü�� n= 1 to 31 multiply
    divider As Double '// ���� n = 1 to 255 divide
End Type

Type st_cmd_head_delay
    dbm_id As Double            '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double           '// KMDB ���� ��ȣ (0 ~ 3)
    dir As Double               '// ���� ���� ������ �����մϴ�. (0-1)
    headl_delay As Double       '// ��� L �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
    headl_subpixel As Double    '// ��� L �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
    headr_delay As Double       '// ��� R �� ������ 0 ~ 65535 ������ ���ڸ� �����մϴ�.
    headr_subpixel As Double    '// ��� R �� ���� �ȼ� 1 / 16 ������ ���� (0 ~ 15)
End Type

Type st_cmd_nozzle_delay
    dbm_id As Double '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double '// KMDB ���� ��ȣ (0 ~ 3)
    l_nozzle_num As Double '// L �� ���� �ð� ������ ���� (�̻���� ��� 0���� ����)
    r_nozzle_num As Double '// R �� ���� �ð� ������ ���� (�̻���� ��� 0���� ����)
    l_delay(1023) As Double '// L �� ���� �ð� ������ (�ִ� 1024 ��)
    r_delay(1023) As Double '// R �� ���� �ð� ������ (�ִ� 1024 ��)
End Type

Type st_cmd_image_info
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    depth As Double     '// �޸� ���� �̹����� �޸� ���� ���̸� �����մϴ�. �̹����� Bit ���� �����մϴ�. 1,2,4�� �����Ͻʽÿ�.
    length As Double    '// �̹��� ���� �̹����� ���̸� �����մϴ�.
End Type

Type st_cmd_image_info2
    mode As Double      '// ����� / �ܹ��� ��ȭ ���� 0 : �ܹ��� ��ȭ 1 : ����� ��ȭ
    Reserved As Double  '// ����
End Type

Type st_external_io
    mode As Double '// �ܺ� I / O ���� ���
End Type

Type st_STB
    dbm_id As Double    '// DBM ���� ��ȣ (0 ~ 3)
    kmdb_id As Double   '// KMDB ���� ��ȣ (0 ~ 3)
    l_for(3) As Double  '// L �� �ⱹ 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
    l_rev(3) As Double  '// L �� ���� ���� 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
    r_for(3) As Double  '// R �� �ⱹ 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
    r_rev(3) As Double  '// R �� �Ա� 1 ~ 3 �ܰ� ���� 0 : A �� 1 : B �� 2 : C ��
End Type






































































Function IJCS1_GetError() As Double
On Error GoTo syserr:
IJCS1_GetError = 0
Exit Function
syserr:
End Function

Function IJCS1_Open() As Boolean
On Error GoTo syserr:

'    If DLL_Open() = True Then
'
'    Else
'
'    End If
    
    'IJCS1_Open = IJCS1_GetError()
Exit Function
syserr:
End Function

Function JCS1_Close() As Boolean
On Error GoTo syserr:
Exit Function
syserr:
End Function

Function JCS1_GetSysInfo() As Boolean
On Error GoTo syserr:
Exit Function
syserr:
End Function
