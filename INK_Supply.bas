Attribute VB_Name = "INK_Supply"
Public fl_Meniscus As Boolean
Sub INKS_PUGRE_OnOff(ipOnOff As Integer)
'''''''''''
'''''''''''    If ipOnOff = 1 Then
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_TankVacuumOnOffSol_03, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_ByPass_OnOffSol_04, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_PurgeSol_05, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_TankVacuumOnOffSol_03, 1
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Vacuum_Ejector2Sol_26, 1
'''''''''''
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_PurgeSol_05, 1
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Purge_����Sol_24, 1
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_����Step3Sol_06, 1
'''''''''''    Else
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_PurgeSol_05, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Purge_����Sol_24, 0
'''''''''''
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_TankVacuumOnOffSol_03, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_ByPass_OnOffSol_04, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_PurgeSol_05, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Ink_TankVacuumOnOffSol_03, 0
'''''''''''        PCI7230_OutSignal_Card2QTY AD7230_DO_Vacuum_Ejector2Sol_26, 1
'''''''''''
'''''''''''
'''''''''''        'Maniscus--------------------------------------------------------
'''''''''''            PCI7230_OutSignal_Card2QTY 3, 0 '1
'''''''''''            PCI7230_OutSignal_Card2QTY 4, 0
'''''''''''            PCI7230_OutSignal_Card2QTY 5, 0
'''''''''''                        PCI7230_OutSignal_Card2QTY 6, 0
'''''''''''            PCI7230_OutSignal_Card2QTY 26, 1
'''''''''''
'''''''''''            PCI7230_OutSignal_Card2QTY 6, 1 '1�̸� ����
'''''''''''            PCI7230_OutSignal_Card2QTY 15, 0 '1�̴���.
'''''''''''
'''''''''''            PCI7230_OutSignal_Card2QTY 7, 1
'''''''''''
'''''''''''    End If
''''''''''''            PCI7230_OutSignal_Card2QTY 3, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 4, 0
''''''''''''            'PCI7230_OutSignal_Card2QTY 5, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 26, 1 '<<<bada
''''''''''''            'Maniscus���¿���...
''''''''''''            PCI7230_OutSignal_Card2QTY 5, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 24, 1
''''''''''''            PCI7230_OutSignal_Card2QTY 6, 1
''''''''''''        Case 2 'Purge OFF
''''''''''''            PCI7230_OutSignal_Card2QTY 5, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 24, 0
''''''''''''            'Maniscus���·�...
''''''''''''            PCI7230_OutSignal_Card2QTY 3, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 4, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 5, 0
''''''''''''            PCI7230_OutSignal_Card2QTY 26, 1 '<<<bada


    If ipOnOff = 1 Then 'Start
    
        PCI7230_OutSignal_Card2QTY 4, 0 '����
        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 1 '����
        PCI7230_OutSignal_Card2QTY 6, 1 '����
        PCI7230_OutSignal_Card2QTY 7, 1 '����
        PCI7230_OutSignal_Card2QTY 16, 1 '����
        PCI7230_OutSignal_Card2QTY 18, 1 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 1 '����
        fl_Meniscus = False
        
    Else
    
''        PCI7230_OutSignal_Card2QTY 3, 0 '����
''        PCI7230_OutSignal_Card2QTY 4, 0 '����
''        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
''        PCI7230_OutSignal_Card2QTY 6, 1 '����
''        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
''        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
''        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        
        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 4, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 6, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        
''        Call INKS_Basic_Meniscus
        
    End If

End Sub
Sub INKS_TwoPart_Purge(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then 'Start
    
        PCI7230_OutSignal_Card2QTY 3, 0 '����
        PCI7230_OutSignal_Card2QTY 4, 0 '����
        PCI7230_OutSignal_Card2QTY 5, 1 '����
        PCI7230_OutSignal_Card2QTY 6, 1 '����
        PCI7230_OutSignal_Card2QTY 7, 1 '����
        PCI7230_OutSignal_Card2QTY 16, 1 '����
        PCI7230_OutSignal_Card2QTY 18, 1 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 1 '����
        fl_Meniscus = False
        
    Else

        PCI7230_OutSignal_Card2QTY 3, 0 '����
        PCI7230_OutSignal_Card2QTY 4, 0 '����
        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 6, 1 '����
        PCI7230_OutSignal_Card2QTY 18, 1 '<<bada 110110
        
        'Call INKS_Basic_Meniscus
        
    End If

End Sub
Sub INKS_Basic_Meniscus()

    '�⺻ �ŴϽ�Ŀ�� - ��� �ʱⱸ����, �л���..
    PCI7230_OutSignal_Card2QTY 3, 0 '����
    PCI7230_OutSignal_Card2QTY 4, 0 '����
    PCI7230_OutSignal_Card2QTY 5, 0 '�޴Ͻ�Ŀ�� ����(�����ʼ���)
    PCI7230_OutSignal_Card2QTY 15, 0 '�ݱ�
    PCI7230_OutSignal_Card2QTY 19, 0 '<<bada 110110
    
    PCI7230_OutSignal_Card2QTY 6, 1 '����
    PCI7230_OutSignal_Card2QTY 18, 1 '<<bada 110110
    '�⺻ �ŴϽ�Ŀ�� - ��� �ʱⱸ����, �л���..
    fl_Meniscus = True
    
End Sub
Sub INKS_InitCharge(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then 'Start
    
        PCI7230_OutSignal_Card2QTY 4, 0
        PCI7230_OutSignal_Card2QTY 6, 0
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 0, 1
        PCI7230_OutSignal_Card2QTY 1, 1
        PCI7230_OutSignal_Card2QTY 3, 1
        PCI7230_OutSignal_Card2QTY 15, 1
        'PCI7230_OutSignal_Card2QTY 27, 1 '����CDA ������ ������޽ÿ� ���........���CDA(DO_28)�ߵǾʼ��� �ϴ�...�̰ɷ� ����. Order By �ֿ��ؤ����� --> ������ �ۿ�!!!
        PCI7230_OutSignal_Card2QTY 28, 1
        
        fl_Meniscus = False
        
    Else
    
        PCI7230_OutSignal_Card2QTY 0, 0
        PCI7230_OutSignal_Card2QTY 1, 0
        PCI7230_OutSignal_Card2QTY 5, 0
        PCI7230_OutSignal_Card2QTY 6, 0
        PCI7230_OutSignal_Card2QTY 15, 0
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        'PCI7230_OutSignal_Card2QTY 27, 0 '����CDA ������ ������޽ÿ� ���........���CDA(DO_28)�߾ʵǼ��� �ϴ�...�̰ɷ� ����. Order By �ֿ��ؤ����� --> ������ �ۿ�!!!
        PCI7230_OutSignal_Card2QTY 28, 0
        PCI7230_OutSignal_Card2QTY 3, 1
        PCI7230_OutSignal_Card2QTY 4, 1

        'Call INKS_Basic_Meniscus

    End If

End Sub
Sub INKS_OnePort_Purge(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then 'Start
    
        PCI7230_OutSignal_Card2QTY 4, 0 '����
        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 1 '����
        PCI7230_OutSignal_Card2QTY 6, 1 '����
        PCI7230_OutSignal_Card2QTY 7, 1 '����
        PCI7230_OutSignal_Card2QTY 16, 1 '����
        PCI7230_OutSignal_Card2QTY 18, 1 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 1 '����
        fl_Meniscus = False
        
    Else

        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 4, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 6, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        'Stop
'        Call INKS_Basic_Meniscus
        
    End If

End Sub
Sub INKS_BubleRemove_Purge(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then 'Start
    
        PCI7230_OutSignal_Card2QTY 4, 0 '����
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 1 '����
        PCI7230_OutSignal_Card2QTY 6, 1 '����
        PCI7230_OutSignal_Card2QTY 7, 1 '����
        PCI7230_OutSignal_Card2QTY 16, 1 '����
        PCI7230_OutSignal_Card2QTY 19, 1 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 1 '����
        fl_Meniscus = False
        
    Else
    
'        PCI7230_OutSignal_Card2QTY 3, 0 '����
'        PCI7230_OutSignal_Card2QTY 4, 0 '����
'        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
'        PCI7230_OutSignal_Card2QTY 6, 1 '����
'        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
'        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
'        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        
        PCI7230_OutSignal_Card2QTY 3, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 4, 1 '�ݱ�
        PCI7230_OutSignal_Card2QTY 5, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 6, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 7, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 16, 0 '�ݱ�
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 19, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 24, 0 '�ݱ�
        'Stop
'        Call INKS_Basic_Meniscus
        
    End If

End Sub
Sub INKS_CappingUnit_Drain(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then

        PCI7230_OutSignal_Card2QTY 10, 1
        'PCI7230_OutSignal_Card2QTY 9, 1
        PCI7230_OutSignal_Card2QTY 25, 1
        fl_Meniscus = False
        
    Else
    
        PCI7230_OutSignal_Card2QTY 10, 0
        'PCI7230_OutSignal_Card2QTY 9, 0
        PCI7230_OutSignal_Card2QTY 25, 0
    
        ''Call INKS_Basic_Meniscus
    
    End If
            
End Sub
Sub INKS_CappingUnit_SolventSupply(fl_Start_Stop As Boolean)

    'Call INKS_Basic_Meniscus

    If fl_Start_Stop = True Then

        PCI7230_OutSignal_Card2QTY 30, 1
        PCI7230_OutSignal_Card2QTY 11, 1
    
    Else
    
        PCI7230_OutSignal_Card2QTY 30, 0
        PCI7230_OutSignal_Card2QTY 11, 0
        
    End If
    
End Sub
Sub INKS_Charge(fl_Start_Stop As Boolean)

    'Call INKS_Basic_Meniscus

    If fl_Start_Stop = True Then 'Start

'        PCI7230_OutSignal_Card2QTY 6, 0
'        PCI7230_OutSignal_Card2QTY 0, 1
'        PCI7230_OutSignal_Card2QTY 1, 1
'        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
'        PCI7230_OutSignal_Card2QTY 27, 1

        Call INKS_Basic_Meniscus
        
        PCI7230_OutSignal_Card2QTY 0, 1
        PCI7230_OutSignal_Card2QTY 1, 1
        PCI7230_OutSignal_Card2QTY 27, 1

    Else
    
'        PCI7230_OutSignal_Card2QTY 0, 0
'        PCI7230_OutSignal_Card2QTY 1, 0
'        PCI7230_OutSignal_Card2QTY 5, 0
'        PCI7230_OutSignal_Card2QTY 6, 0
'        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
'        PCI7230_OutSignal_Card2QTY 27, 0

        Call INKS_Basic_Meniscus
        
        PCI7230_OutSignal_Card2QTY 0, 0
        PCI7230_OutSignal_Card2QTY 1, 0
        PCI7230_OutSignal_Card2QTY 27, 0

    End If

End Sub
Sub INKS_CleaningCharge(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then 'Start
    
        'Call INKS_Basic_Meniscus
        PCI7230_OutSignal_Card2QTY 4, 0
        PCI7230_OutSignal_Card2QTY 6, 0
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        
        PCI7230_OutSignal_Card2QTY 1, 1
        PCI7230_OutSignal_Card2QTY 2, 1
        PCI7230_OutSignal_Card2QTY 3, 1
        PCI7230_OutSignal_Card2QTY 15, 1
        PCI7230_OutSignal_Card2QTY 30, 1
        fl_Meniscus = False
        
    Else
    
        'PCI7230_OutSignal_Card2QTY 6, 1 '1

        PCI7230_OutSignal_Card2QTY 1, 0
        PCI7230_OutSignal_Card2QTY 2, 0
        PCI7230_OutSignal_Card2QTY 5, 0
        PCI7230_OutSignal_Card2QTY 6, 0
        PCI7230_OutSignal_Card2QTY 15, 0
        PCI7230_OutSignal_Card2QTY 18, 0 '<<bada 110110
        PCI7230_OutSignal_Card2QTY 30, 0
        PCI7230_OutSignal_Card2QTY 3, 1
        PCI7230_OutSignal_Card2QTY 4, 1
        'Call INKS_Basic_Meniscus
        
    End If

End Sub
Sub INKS_InkBottleSolventSupply(fl_Start_Stop As Boolean)

    If fl_Start_Stop = True Then
        PCI7230_OutSignal_Card2QTY 0, 1
        PCI7230_OutSignal_Card2QTY 1, 0
        PCI7230_OutSignal_Card2QTY 2, 1
        PCI7230_OutSignal_Card2QTY 11, 0
        
        PCI7230_OutSignal_Card2QTY 8, 1
        PCI7230_OutSignal_Card2QTY 25, 1
    Else
        PCI7230_OutSignal_Card2QTY 0, 0
        PCI7230_OutSignal_Card2QTY 1, 0
        PCI7230_OutSignal_Card2QTY 2, 0
        PCI7230_OutSignal_Card2QTY 11, 0
        
        PCI7230_OutSignal_Card2QTY 8, 0
        PCI7230_OutSignal_Card2QTY 25, 0
    End If

End Sub

'// 2013.03.21 - KHY: ������ �������ж��� �����ؼ� �����ϰ� ���.
Sub Purge()
    
    PCI7230_OutSignal_Card2QTY 5, 1
    PCI7230_OutSignal_Card2QTY 3, 1
    
    MDI_Main.CWB_Stat(0).Value = True
    
'    if (bOn)
'    {
'        m_pci7230[0].SetDOValue(5, 1);  // purge
'        m_pci7230[0].SetDOValue(3, 1);  // meniscus
'    }
'    Else
'    {
'        m_pci7230[0].SetDOValue(5, 0);  // purge
'        m_pci7230[0].SetDOValue(3, 0);  // meniscus
'    }
    
    
    
End Sub

'// 2013.03.21 - KHY: ������ �������ж��� �����ؼ� �����ϰ� ���.
Sub Meniscus()

    PCI7230_OutSignal_Card2QTY 5, 0
    PCI7230_OutSignal_Card2QTY 3, 0
    PCI7230_OutSignal_Card2QTY 6, 0
    
    MDI_Main.CWB_Stat(0).Value = False
'    if (bOn)
'    {
'        m_pci7230[0].SetDOValue(5, 0);  // purge
'        m_pci7230[0].SetDOValue(3, 0);  // meniscus
'        m_pci7230[0].SetDOValue(6, 0);  // normal air
'    }
'    Else
'    {
'        m_pci7230[0].SetDOValue(3, 1);  // meniscus
'    }
End Sub
























