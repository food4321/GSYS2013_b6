VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IMGPROC_GEOP"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'****************************************************************************
'*                   Visoion ǥ��ȭ - Geometry Pattern Matching             *
'*                       2007/11/22           ������                        *
'*                          IMGPROC_GEOP.Cls                                *
'*                        cGEO_Structure.Bas                                *
'****************************************************************************
Public Sub Save_Mod(ipModelFindCtrl As Control, ipMainBuf As Control, ipTargetBox As Control, ipFlagModelShape As Integer, ipMMF_Path As String, ipFlag_DefaultSave As Boolean)

    Dim Tag_X As Double
    Dim Tag_Y As Double
    Dim Tag_W As Double
    Dim Tag_H As Double
    
    On Error GoTo Error_Handdler
    
    Tag_X = ipTargetBox.Left / Screen.TwipsPerPixelX
    Tag_Y = ipTargetBox.Top / Screen.TwipsPerPixelY
    Tag_W = ipTargetBox.Width / Screen.TwipsPerPixelX
    Tag_H = ipTargetBox.Height / Screen.TwipsPerPixelY
    
    'OCX�� �ε� Model ����
    
    'MsgBox ipModelFindCtrl.Models.Count
    
    For i% = ipModelFindCtrl.Models.count To 1 Step -1
        ipModelFindCtrl.Models.Remove i% ' + 1
    Next i%
    'OCX�� �ε� Model ����
    
    'ipModelFindCtrl.image = frmVision.Buf_Main
    If ipFlag_DefaultSave = False Then
        ipModelFindCtrl.ModelFinderType = set_GeoPara.cModelFinderType
        
        'Models Global Para-----------------------------------------
        ipModelFindCtrl.Models.TotalNumberOfOccurrences = set_GeoPara.cTotalNumberOfOccurrences                  'ã�� ���ü ����(GlobalPara Set������ modAll�� ����)
        ipModelFindCtrl.Models.SmoothnessLevel = set_GeoPara.cSmoothnessLevel                                            '0.0 ~ 100.0 %
        ipModelFindCtrl.Models.DetailLevel = set_GeoPara.cDetailLevel                                                    '��� ǥ�� ���ش�
        ipModelFindCtrl.Models.Speed = set_GeoPara.cSpeed                                                                '�˻� �ӵ�
        ipModelFindCtrl.Models.Accuracy = set_GeoPara.cAccuracy                                                          '�˻� ���ش�
                                                                                                                                '
        ipModelFindCtrl.Models.SearchAngleEnabled = set_GeoPara.cSearchAngleEnabled                                      'Ratation Pattern Searching
        ipModelFindCtrl.Models.SearchScaleEnabled = set_GeoPara.cSearchScaleEnabled                                      'ũ�⿡ ������� �˻� / �������� �ö� �� ����.
        ipModelFindCtrl.Models.SharedEdges = set_GeoPara.cSharedEdges                                                    '���յ� ��輱�� ���� ���� ����
        
        'ipModelFindCtrl.Models.FirstLevel = N / S
        'ipModelFindCtrl.Models.LastLevel  = N / S
        
        ipModelFindCtrl.Models.Timeout = set_GeoPara.cTimeout
    End If
    'Models Global Para-----------------------------------------
    
    'Models/General---------------------------------------------
    '���� �� ó����....(��Ƽ ���� ���� �߰� ����)
    'rtn_lng& = ipModelFindCtrl.Models.AddImageModel(frmvision.Buf_Main, Tag_X, Tag_Y, Tag_W, Tag_H)
    
    If ipFlag_DefaultSave = False Then
        Select Case ipFlagModelShape
            Case 1 'GEO_CONST_MODEL_TYPE_IMAGE
                rtn_Lng& = ipModelFindCtrl.Models.AddImageModel(ipMainBuf, Tag_X, Tag_Y, Tag_W, Tag_H)
                
            Case 2 'GEO_CONST_MODEL_TYPE_CROSS
                rtn_Lng& = ipModelFindCtrl.Models.AddCrossModel(set_GeoPara.cForground, Tag_W, Tag_H, _
                                                set_GeoPara.cCross_HorThickness, set_GeoPara.cCross_VerThickness)
            Case 3 'GEO_CONST_MODEL_TYPE_CIRCLE
                If Tag_W > Tag_H Then
                    rrr# = Tag_H
                Else
                    rrr# = Tag_W
                End If
                'rtn_Lng& = ipModelFindCtrl.Models.AddImageModel(ipMainBuf, Tag_X, Tag_Y, Tag_W, Tag_H) '�ͱ ����
                rtn_Lng& = ipModelFindCtrl.Models.AddCircleModel(set_GeoPara.cForground, rrr#)
            Case 4 'GEO_CONST_MODEL_TYPE_RACTANGLE
                rtn_Lng& = ipModelFindCtrl.Models.AddRectangleModel(set_GeoPara.cForground, Tag_W, Tag_H)
                
            Case 5 'GEO_CONST_MODEL_TYPE_ELLIPSE
                rtn_Lng& = ipModelFindCtrl.Models.AddEllipseModel(set_GeoPara.cForground, Tag_W, Tag_H)
                
            Case 6 'GEO_CONST_MODEL_TYPE_RING
                rtn_Lng& = ipModelFindCtrl.Models.AddRingModel(set_GeoPara.cForground, set_GeoPara.cRing_InRadius, _
                                                set_GeoPara.cRing_OutRadius)
            Case 7 'GEO_CONST_MODEL_TYPE_SQUARE
                If Tag_W > Tag_H Then
                    www# = Tag_H
                Else
                    www# = Tag_W
                End If
                rtn_Lng& = ipModelFindCtrl.Models.AddSquareModel(set_GeoPara.cForground, www#)
            Case 8 'GEO_CONST_MODEL_TYPE_DxF
                rtn_Lng& = ipModelFindCtrl.Models.AddDxfModel(set_GeoPara.cDxF_FilaPath)
                
        End Select
            
        added_model_num% = ipModelFindCtrl.Models.count
        
        '�� �߰��� ���� ���� (Default���� ������ �Ѵ�)
        'ipModelFindCtrl.Models(added_model_num%).ReferenceAngle = 0                                                     'Set Axis Angle
        'ipModelFindCtrl.Models(added_model_num%).ReferenceX = Tag_W / 2                                                 'Set Axis Center X
        'ipModelFindCtrl.Models(added_model_num%).ReferenceY = Tag_H / 2                                                 'Set Axis Center Y
        'Models/General---------------------------------------------------------------------------------------------------------------------------
        
        '�� �߰��� ���� ���� (Default���� ������ �Ѵ�)
        'Models/Attributes------------------------------------------
        ipModelFindCtrl.Models(added_model_num%).UserLabel = set_GeoPara.cUserLabel
        ipModelFindCtrl.Models(added_model_num%).NumberOfOccurrences = set_GeoPara.cNumberOfOccurrences                  'ã�� ���ü�� ������ ���⼭ ���� / Default = 1 ����!!!!
        ipModelFindCtrl.Models(added_model_num%).Acceptance = set_GeoPara.cAcceptance
        ipModelFindCtrl.Models(added_model_num%).AcceptanceTarget = set_GeoPara.cAcceptanceTarget
        ipModelFindCtrl.Models(added_model_num%).Certainty = set_GeoPara.cCertainty
        ipModelFindCtrl.Models(added_model_num%).CertaintyTarget = set_GeoPara.cCertaintyTarget
        'Models/Attributes------------------------------------------
        
        '�� �߰��� ���� ���� (Default���� ������ �Ѵ�)
        'Models/Advanced--------------------------------------------
        ipModelFindCtrl.Models(added_model_num%).MinimumSeparationX = set_GeoPara.cMinimumSeparationX                    '�� �߰��� ���� ����
        ipModelFindCtrl.Models(added_model_num%).MinimumSeparationY = set_GeoPara.cMinimumSeparationY
        ipModelFindCtrl.Models(added_model_num%).MinimumSeparationAngle = set_GeoPara.cMinimumSeparationAngle
        ipModelFindCtrl.Models(added_model_num%).MinimumSeparationScale = set_GeoPara.cMinimumSeparationScale
        ipModelFindCtrl.Models(added_model_num%).Polarity = set_GeoPara.cPolarity
        ipModelFindCtrl.Models(added_model_num%).FitErrorWeightingFactor = set_GeoPara.cFitErrorWeightingFactor
        'Models/Advanced--------------------------------------------
        
        '�� �߰��� ���� ���� (Default���� ������ �Ѵ�)
        'Models/Degree Of Freedom(DOF)------------------------------
        ipModelFindCtrl.Models(added_model_num%).Angle.Value = set_GeoPara.cDOF_Angle                                    '�˻� ���� ����
        ipModelFindCtrl.Models(added_model_num%).Angle.NegativeDelta = set_GeoPara.cDOF_AngleNegative                    '�˻� ���� -
        ipModelFindCtrl.Models(added_model_num%).Angle.PositiveDelta = set_GeoPara.cDOF_AnglePositive                    '�˻� ���� +
        ipModelFindCtrl.Models(added_model_num%).Scale.Value = set_GeoPara.cDOF_Scale                                    '�˻� �� Scale
        ipModelFindCtrl.Models(added_model_num%).Scale.Minimum = set_GeoPara.cDOF_ScaleMinimum                           '�˻� ��� �ν� �ּ� Scale
        ipModelFindCtrl.Models(added_model_num%).Scale.Maximum = set_GeoPara.cDOF_ScaleMaximum                           '�˻� ��� �ν� �ִ� Scale
        'Models/Degree Of Freedom(DOF)------------------------------
    Else
        rtn_Lng& = ipModelFindCtrl.Models.AddImageModel(ipMainBuf, Tag_X, Tag_Y, Tag_W, Tag_H)
    End If
    ipModelFindCtrl.Save ipMMF_Path                                                                                  'File�� ����.
Exit Sub
Error_Handdler:
    Open App.Path & "\GeometryClassErrorLog" & Format(Now, "YYYYMMDD") & " .log" For Append As #1
    Print #1, Err.Description
    Close #1
    
End Sub
Function Find_Model(ipModelFindCtrl As Control, ipGraphicContext As Control, ref_Box As Control, ipModelFilePath As String) As Double

    Dim Ref_Xx As Double
    Dim Ref_Yy As Double
    Dim Ref_Ww As Double
    Dim Ref_Hh As Double
    
    ft_x& = Screen.TwipsPerPixelX: ft_y& = Screen.TwipsPerPixelY

    Ref_Xx = ref_Box.Left / ft_x&: Ref_Yy = ref_Box.Top / ft_y&
    Ref_Ww = ref_Box.Width / ft_x&: Ref_Hh = ref_Box.Height / ft_y&
    model_path$ = ipModelFilePath

    With ipModelFindCtrl
    
        For i& = .Models.count To 1 Step -1
            .Models.Remove i& ' + 1
        Next i&
        
        .Load model_path$
        '.Modified mDefault
        
        .Models(.Models.count).SearchRegion.Mode = roiOffsetSize
        .Models(.Models.count).SearchRegion.OffsetX = Ref_Xx 'ref_Box.Left / ft_x&
        .Models(.Models.count).SearchRegion.OffsetY = Ref_Yy 'ref_Box.Top / ft_y&
        .Models(.Models.count).SearchRegion.SizeX = Ref_Ww 'ref_Box.Width / ft_x&
        .Models(.Models.count).SearchRegion.SizeY = Ref_Hh 'ref_Box.Height / ft_y&
        .Preprocess
        .Find

        If .Results.count = 0 Then
           Find_Model = 999
           '--bada 20090225
           GeometryResult_SearchedModelQuantity = 0
           '--bada 20090225
            Exit Function
        End If
        GeometryResult_SearchedModelQuantity = .Results.count
        ReDim rtnGeoResults(GeometryResult_SearchedModelQuantity - 1)
    
        For i& = 0 To .Results.count - 1
            rtnGeoResults(i&).cScore = .Results(i& + 1).Score
            rtnGeoResults(i&).cPositionX = Ref_Xx + .Results(i& + 1).PositionX
            rtnGeoResults(i&).cPositionY = Ref_Yy + .Results(i& + 1).PositionY
            rtnGeoResults(i&).cWidth = .Results(i& + 1).Width
            rtnGeoResults(i&).cHeight = .Results(i& + 1).Height
            rtnGeoResults(i&).cRadius = .Results(i& + 1).Radius
            rtnGeoResults(i&).cAngle = .Results(i& + 1).Angle
            .Results(i& + 1).Draw ipGraphicContext, modDrawEdges
            .Results(i& + 1).Draw ipGraphicContext, modDrawPosition
        Next i&
        
        If .Results.count = 1 Then
            Find_Model = .Results(1).Score
        End If
        
    End With

Exit Function
Error_Handdler:
    Open App.Path & "\PtrnClassErrorLog" & Format(Now, "YYYYMMDD") & " .log" For Append As #1
    Print #1, Format(Now, "HH:MM:SS") & "," & Err.Description
    Close #1

End Function
