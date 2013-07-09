VERSION 5.00
Begin VB.Form frmHeadSelect 
   BorderStyle     =   1  '���� ����
   Caption         =   "����� ��� ��Ʈ�ѷ� ����"
   ClientHeight    =   2415
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4980
   Icon            =   "frmHeadSelect.frx":0000
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2415
   ScaleWidth      =   4980
   StartUpPosition =   2  'ȭ�� ���
   Begin VB.CommandButton cmdExit 
      Caption         =   "����"
      Height          =   600
      Left            =   2610
      Picture         =   "frmHeadSelect.frx":058A
      Style           =   1  '�׷���
      TabIndex        =   3
      Top             =   1500
      Width           =   1605
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "Ȯ��"
      Height          =   600
      Left            =   690
      Picture         =   "frmHeadSelect.frx":0B14
      Style           =   1  '�׷���
      TabIndex        =   2
      Top             =   1485
      Width           =   1605
   End
   Begin VB.ComboBox cboHeadType 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   405
      ItemData        =   "frmHeadSelect.frx":109E
      Left            =   690
      List            =   "frmHeadSelect.frx":10A8
      TabIndex        =   0
      Top             =   855
      Width           =   3555
   End
   Begin VB.Label lblHeadType 
      Alignment       =   2  '��� ����
      AutoSize        =   -1  'True
      Caption         =   "����Ͻ� ��Ʈ�ѷ��� �����Ͽ� �ֽʽÿ�."
      BeginProperty Font 
         Name            =   "����"
         Size            =   12
         Charset         =   129
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   225
      TabIndex        =   1
      Top             =   270
      Width           =   4725
   End
End
Attribute VB_Name = "frmHeadSelect"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdExit_Click()
    End
End Sub

Private Sub cmdOK_Click()
On Error GoTo syserr
    Dim nHeadType As HeadType
    
    nHeadType = cboHeadType.ListIndex
    SaveSetting App.Title, "SYSTEM", "HEAD_TYPE", nHeadType
    
    g_nHeadType = nHeadType
    
    If g_nHeadType = nLG_Q Then
        MDI_Main.Caption = "LG PRI - 2013 G System( LG-PRI Q_Head )"
    ElseIf g_nHeadType = nKM Then
        MDI_Main.Caption = "LG PRI - 2013 G System( IJCS-1 KM_Head )"
    End If
    
    Unload Me
Exit Sub
syserr:

End Sub

Private Sub Form_Load()
On Error GoTo syserr
    
    g_nHeadType = CInt(GetSetting(App.Title, "SYSTEM", "HEAD_TYPE", "0"))
    cboHeadType.ListIndex = g_nHeadType
    
Exit Sub
syserr:

End Sub

Private Sub Form_Unload(Cancel As Integer)
On Error GoTo syserr
    Call cmdOK_Click
Exit Sub
syserr:

End Sub
