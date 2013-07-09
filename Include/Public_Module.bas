Attribute VB_Name = "Public_Module"
Public Declare Function GetTickCount Lib "kernel32" () As Long
Public Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
Public Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" _
            (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, _
             ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Public Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" _
            (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, _
             ByVal lpFileName As String) As Long
Public Declare Function GetComputerName Lib "kernel32" Alias "GetComputerNameA" (ByVal lpBuffer As String, nSize As Long) As Long
Public Declare Function GetFileSize Lib "kernel32" (ByVal hFile As Long, lpFileSizeHigh As Long) As Long
Public Declare Function LineTo Lib "gdi32" (ByVal hDC As Long, ByVal X As Long, ByVal Y As Long) As Long

Public Declare Sub OutputDebugString Lib "kernel32" Alias "OutputDebugStringA" (ByVal lpOutputString As String)


Public Const HWND_TOPMOST = -1
Public Const HWND_NOTOPMOST = -2
Public Const SWP_NOSIZE = &H1
Public Const SWP_NOMOVE = &H2
Public Const SWP_NOACTIVATE = &H10
Public Const SWP_SHOWWINDOW = &H40
Public Declare Sub SetWindowPos Lib "user32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long)
Sub FileName_Parser(ipFileNamePath As String, rtnFileName As String, rtnFilePath As String)

    For j% = Len(ipFileNamePath) To 1 Step -1
        tmp_str$ = Mid(ipFileNamePath, j%, 1)
        If tmp_str$ = "\" Then
            rem_position% = j%
            Exit For
        End If
    Next j%
    rtnFilePath = Left(ipFileNamePath, rem_position%)
    rtnFileName = Right(ipFileNamePath, Len(ipFileNamePath) - rem_position%)
    
End Sub

Sub GRID_Clear(ipGridControl As Control, flag_RemoveItem As Boolean)

    latched_format_str$ = ipGridControl.FormatString
    ipGridControl.Clear
    If flag_RemoveItem = True Then
        For i% = ipGridControl.Rows - 1 To 2 Step -1
            ipGridControl.RemoveItem i%
        Next i%
    End If
    ipGridControl.FormatString = latched_format_str$

End Sub
Function FormExistance(Form_Name As String) As Boolean

    Dim SearchForm As Object
    
    For Each SearchForm In Forms
        If SearchForm.Name = Form_Name Then
            FormExistance = True
            Exit Function
        End If
    Next SearchForm
    FormExistance = False
    
End Function
Sub AllFormUnload(ipLiveForm_Name As String)

    Dim SearchForm As Object
    
    For Each SearchForm In Forms
        If SearchForm.Name <> ipLiveForm_Name Then
            Unload SearchForm
        End If
    Next SearchForm

End Sub
Sub ctrlEnable(ByVal ipfl_Enable As Boolean, frm As Form)

    Dim ctrl As Object
    On Error Resume Next
    
    For Each ctrl In frm.Controls
        
        'Debug.Print ctrl.Name
    
'        If ((ctrl.Name <> "Frame_NoOP_Motion") Or (ctrl.Name <> "Frame_NoOP_Power") Or (ctrl.Name <> "Frame_NoOP_Slit") _
'                            Or (ctrl.Name <> "Frame_NoOP_Laser") Or (ctrl.Name <> "CWN_RecipeID")) Then
'            If ipfl_Enable Then
'                ctrl.Enabled = True
'            Else
'                ctrl.Enabled = False
'            End If
'        End If

        If (ctrl.Name <> "Frame_NoOP_Motion") Then
            If ipfl_Enable Then
                ctrl.Enabled = True
            Else
                ctrl.Enabled = False
            End If
        Else
            'MsgBox "GG"
        End If
    Next
    If ipfl_Enable Then
        frm.MousePointer = vbDefault
    Else
        frm.MousePointer = vbHourglass
    End If
    
End Sub
Function PubAINKTimeCheck(ClearAll As Boolean) As Double

    Static fl_Start As Boolean
    Static DuStart As Double
    Static DurationTime As Double

    If ClearAll = False Then
        If fl_Start = False Then
            DuStart = GetTickCount / (10 ^ 3)
            fl_Start = True
        Else
            DurationTime = Abs((GetTickCount / (10 ^ 3)) - DuStart)
            PubAINKTimeCheck = DurationTime
        End If
    Else
        fl_Start = False
        DuStart = 0
        DurationTime = 0
        PubAINKTimeCheck = 0
    End If

End Function

Function PubTimeCheck(ClearAll As Boolean) As Double

    Static fl_Start As Boolean
    Static DuStart As Double
    Static DurationTime As Double

    If ClearAll = False Then
        If fl_Start = False Then
            DuStart = GetTickCount / (10 ^ 3)
            fl_Start = True
        Else
            DurationTime = Abs((GetTickCount / (10 ^ 3)) - DuStart)
            PubTimeCheck = DurationTime
        End If
    Else
        fl_Start = False
        DuStart = 0
        DurationTime = 0
        PubTimeCheck = 0
    End If

End Function
Sub LogDis(ipTxtControl As Control, Indata As String)
    
    Static aa As Integer
    
    If aa > 255 Then
        aa = 0
        ipTxtControl.Text = ""
    End If
    
    ipTxtControl.SelLength = Len(ipTxtControl.Text)
    If InStr(1, Indata, vbCrLf) <> 0 Then
        ipTxtControl.SelText = Indata
    Else
        ipTxtControl.SelText = Indata & vbCrLf
    End If
    aa = aa + 1
    
End Sub
Sub PubLogDis(ipTxtControl As Control, Indata As String, ipClear As Boolean)
    
    If ipClear = True Then
        ipTxtControl.Text = ""
    End If
    
    If Len(ipTxtControl.Text) >= 1024 Then
        ipTxtControl.Text = ""
    End If
    
    ipTxtControl.SelLength = Len(ipTxtControl.Text)
    If InStr(1, Indata, vbCrLf) <> 0 Then
        ipTxtControl.SelText = Indata
    Else
        ipTxtControl.SelText = Indata & vbCrLf
    End If
    aa = aa + 1
    
End Sub
Function Bit_Bool_Convert(ipBitData As Integer) As Boolean

    'ipBitData �� �ݵ�� 1 , 0 �� �Է� �Ǿ�� �Ѵ�.
    Bit_Bool_Convert = ipBitData * -1

End Function
Function Convert32BitHex_To_Decimal(ipHex32Bit As String) As Double

    'ipHex �� �ݵ�� 8�ڸ� Hex�̾�� ��!!
    '-2147483647(h80000001) ~ 2147483647(7FFFFFFF) ���� ������ ����
    tmp_hex$ = Hex_FormatString(ipHex32Bit, 8)
'    For i% = 1 To (8 - Len(ipHex)) 'Step -1
'        tmp_hex$ = "0" & tmp_hex$
'    Next i%
    
    msb# = Val("&H" & Left(tmp_hex$, 1))
    If msb# > 7 Then '����
        hex_0$ = Right(tmp_hex$, 2): hex_1$ = Mid(tmp_hex$, 5, 2): hex_2$ = Mid(tmp_hex$, 3, 2): hex_3$ = Left(tmp_hex$, 2)
        sum_0& = Val("&H" & hex_0$): sum_1& = Val("&H" & hex_1$): sum_2& = Val("&H" & hex_2$): sum_3& = Val("&H" & hex_3$)
        '����
        For i% = 0 To 7
            sum_0& = (sum_0& Xor (2 ^ i%))
            sum_1& = (sum_1& Xor (2 ^ i%))
            sum_2& = (sum_2& Xor (2 ^ i%))
            sum_3& = (sum_3& Xor (2 ^ i%))
        Next i%
        hex_0$ = "": hex_1$ = "": hex_2$ = "": hex_3$ = ""
        hex_0$ = Hex_FormatString(Hex(sum_0&), 2): hex_1$ = Hex_FormatString(Hex(sum_1&), 2)
        hex_2$ = Hex_FormatString(Hex(sum_2&), 2): hex_3$ = Hex_FormatString(Hex(sum_3&), 2)
        full_hex$ = hex_3$ & hex_2$ & hex_1$ & hex_0$: Convert32BitHex_To_Decimal = (Val("&H" & full_hex$) + 1) * -1
    Else            '���
        Convert32BitHex_To_Decimal = Val("&H" & tmp_hex$)
    End If

End Function
Function Hex_FormatString(ipHex As String, StrQuantity As Integer) As String

    tmp_hex$ = ipHex
    For i% = 1 To (StrQuantity - Len(ipHex)) 'Step -1
        tmp_hex$ = "0" & tmp_hex$
    Next i%
    Hex_FormatString = tmp_hex$
    
End Function
Function ConvertDecimal_To_32BitHex(ipDecimal As Double) As String

    '-2147483648(h80000001) ~ 2147483646(7FFFFFFF) ���� ������ ����
    If ipDecimal > 2147483646 Then ipDecimal = 2147483646
    If ipDecimal < -2147483648# Then ipDecimal = -2147483648#
    ConvertDecimal_To_32BitHex = Hex(ipDecimal)

End Function
Sub DelayWait(ipWaitTime As Double, ipFlagDoeventsEnabled As Boolean)

    rtn_dbl# = DelayWait_TimeCheck(True)
    Do
        If ipFlagDoeventsEnabled = True Then
            DoEvents
        End If
    Loop Until DelayWait_TimeCheck(False) >= ipWaitTime
    rtn_dbl# = DelayWait_TimeCheck(True)
    
End Sub
Function DelayWait_TimeCheck(ClearAll As Boolean) As Double

    Static fl_Start As Boolean
    Static DuStart As Double
    Static DurationTime As Double

    If ClearAll = False Then
        If fl_Start = False Then
            DuStart = GetTickCount / (10 ^ 3)
            fl_Start = True
        Else
            DurationTime = Abs((GetTickCount / (10 ^ 3)) - DuStart)
            DelayWait_TimeCheck = DurationTime
        End If
    Else
        fl_Start = False
        DuStart = 0
        DurationTime = 0
        DelayWait_TimeCheck = 0
    End If

End Function
Function Pub_WinSocket_Status(ipWinSocketCtrl As Control, rtnStatCode As Integer) As String

    rtnStatCode = ipWinSocketCtrl.State
    
    Select Case rtnStatCode
        Case sckClosed
            Pub_WinSocket_Status = "���� ����"
        Case sckOpen
            Pub_WinSocket_Status = "���� ����"
        Case sckListening
            Pub_WinSocket_Status = "���� ��� ��"
        Case sckConnectionPending
            Pub_WinSocket_Status = "���� ���� ��"
        Case sckResolvingHost
            Pub_WinSocket_Status = "ȣ��Ʈ ���� ��"
        Case sckHostResolved
            Pub_WinSocket_Status = "ȣ��Ʈ ���� �Ϸ�"
        Case sckConnecting
            Pub_WinSocket_Status = "���� ��"
        Case sckConnected
            Pub_WinSocket_Status = "���� �Ϸ�"
        Case sckClosing
            Pub_WinSocket_Status = "�Ǿ ������ �ݰ� ����"
        Case sckError
            Pub_WinSocket_Status = "����"
    End Select

End Function
Sub GRID_DataSaveToCSV(ipGRIDctrl As MSFlexGrid, ipFilePath As String, Optional ByVal fl_NewFile As Boolean)

    '������ �׸����� ������ CSV Format���� ����Ѵ�.

    For rr% = 0 To ipGRIDctrl.Rows - 1
        For cc% = 0 To ipGRIDctrl.Cols - 1
            saving_str$ = saving_str$ & ipGRIDctrl.TextMatrix(rr%, cc%) & ","
        Next cc%
        saving_str$ = Left(saving_str$, Len(saving_str$) - 1)
        saving_str$ = saving_str$ & vbCrLf
    Next rr%
    
    '������ �ɸ������� �߶��ش�.
    saving_str$ = Left(saving_str$, Len(saving_str$) - 2)
    '������ �ɸ������� �߶��ش�.
    
    If fl_NewFile = True Then
        Open ipFilePath For Output As #1
    Else
        Open ipFilePath For Append As #1
    End If
    
    Print #1, saving_str$
    Close #1
    
End Sub
Sub GRID_DataCSVToOpen(ipGRIDctrl As MSFlexGrid, ipFilePath As String, fl_AddItem As Boolean)

    'CSV������ ������ �׸��忡 ����Ѵ�.
    '��,GRID_DataSaveToCSV �Լ��� ȣ���Ͽ� ������ ��쿡��.......
    Dim ReadBuf As String
    Dim txtLineArray As Variant
    
    max_row% = ipGRIDctrl.Rows - 1
    max_col% = ipGRIDctrl.Cols - 1
    
    Open ipFilePath For Input As #1
    Do While Not EOF(1)
        Line Input #1, ReadBuf
        
        txtLineArray = Split(ReadBuf, ",", 1024, vbTextCompare)
        If max_col% < UBound(txtLineArray) Then
            Close #1
            MsgBox "������ ������ �÷����� ��µ� �׸����� �÷������� Ů�ϴ�.", vbCritical
            Exit Sub
        End If
        
        For Col_Cnt% = 0 To UBound(txtLineArray)
            ipGRIDctrl.TextMatrix(Row_Cnt%, Col_Cnt%) = txtLineArray(Col_Cnt%)
            'ipGRIDctrl.TopRow = row_cnt% + 1
        Next Col_Cnt%
        
        Row_Cnt% = Row_Cnt% + 1
        If fl_AddItem = True Then
            If Row_Cnt% > 1 Then
                ipGRIDctrl.AddItem ""
            End If
        End If
    Loop

    If fl_AddItem = True Then
        ipGRIDctrl.RemoveItem ipGRIDctrl.Rows - 1 '������ ���� ����
    End If

    Close #1
    
End Sub
