// Manage_File.cpp: implementation of the CManage_File class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PRI_HeadIF.h"
#include "Manage_File.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManage_File::CManage_File()
{
	memset(&m_JetDB,0,sizeof(m_JetDB));
}

CManage_File::~CManage_File()
{

}

PRIDB CManage_File::Read_JetDB(char *psPath, int nHeadNo, int nReadLine)
{
	char *ctoken;	  //token
	char strDB[256]; //������ �� ���� ������ ���ڿ�����
	int i = 0;
	int nData = 0;
	int nActive = 0;
	int nNzlNo = 0;	
	FILE *ifp;

	memset(&m_JetDB,0,sizeof(m_JetDB));
	memset(strDB,'\0',sizeof(char)*256);

	ifp = fopen(psPath,"r");

	if (ifp == NULL )
	{
		return m_JetDB;
	}

	while(fgets(strDB,256,ifp) != NULL) //<-----------------------------------�̺κ�
	{
		ctoken = strtok(strDB,"="); // '='���� ��ū�� ����
		ctoken = strtok(NULL," ");

		if(i>=nReadLine)
		{
			switch(nData) 
			{
				case 0:
					
					if(ctoken) 
					{ 
						nActive = atoi(ctoken);
						if(nActive == 1) 
						{
							m_JetDB.HEAD[nHeadNo].bActive[nNzlNo] = true;
						}
						else
						{
							m_JetDB.HEAD[nHeadNo].bActive[nNzlNo] = false;
						}
					}

					nData = 1;
					break;

				case 1:
					
					if(ctoken) 
					{ 
						m_JetDB.HEAD[nHeadNo].fVoltage[nNzlNo] = (float)atof(ctoken);
					}

					nData = 2;
					break;

				case 2:
					
					if(ctoken) 
					{
						m_JetDB.HEAD[nHeadNo].nWaveForm[nNzlNo] = atoi(ctoken);
					}

					nData = 3;
					break;

				case 3:
					
					if(ctoken) 
					{
						m_JetDB.HEAD[nHeadNo].fSlantOffset[nNzlNo] = (float)atof(ctoken);
					}

					nData = 0;
					nNzlNo++;
					break;

				default:
					break;
			}
		}
		
		i++;
		memset(strDB,'\0',sizeof(char)*256);
	}
    
	fclose(ifp);
	return m_JetDB;
}

BOOL CManage_File::Open(CFile *pRtnFile, char *psPath, int nAttribute)
{
	int nPathLen = 0;
	BOOL bOpen = FALSE;

	if(CFile::hFileNull != pRtnFile->m_hFile)
	{
		pRtnFile->Close();
		return FALSE;
	}

	if (nAttribute == Write_Attr)
	{
		nAttribute = CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite;
	}
	else
	{
		nAttribute = CFile::modeRead;	
	}

	nPathLen = strlen(psPath);

	if (nPathLen <= 0)
	{
		AfxMessageBox( "������ ���ϰ�ΰ� ������ �ȵǾ����ϴ�." );
		pRtnFile = NULL;
		return FALSE;
	}

	bOpen = pRtnFile->Open(psPath, nAttribute);
	if(bOpen == FALSE)
	{
		AfxMessageBox( "������ ������ ���� �����ϴ�." );

		pRtnFile = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CManage_File::ReadLine(CFile *file, char* pcStream)
{
    char buffer[1024];
    BOOL bNEWLINE=FALSE;
    BOOL bEOF = FALSE;

	memset(buffer,'\0',sizeof(buffer));

    while (!bNEWLINE) 
	{
		// 1k Byte = 1024 character
        DWORD read = file->Read(buffer, 1024);

        for (DWORD i=0; i<read; i++) 
		{
			// ASCII ���ڶ�� 0000 0000 ~ 0111 1111 �� ����. : 0~127 (���� �ƽ�Ű 1BYTEó��)
			// Extend ASCII ���ڶ�� 1000 0000 ~ 1111 1111 �� ����. : 128~255 (���� �ƽ�Ű 1BYTEó��)
			// 2Byte ����ó�� �ѱ��� ����µȴ�.
			// ASCII�� �ƴ� ������ ��� TRUE�� �ǰ�, ASCII ���ڴ� ��� FALSE ��

			// �ѱ�ó��
            if (buffer[i] & 0x80) 
			{ 
				//�ѱ� : 2Byte
				pcStream[i] = buffer[i];
				pcStream[i++] = buffer[i++];
            } 

			// Carriage Return 
			else if (buffer[i] == '\r' || buffer[i] == '\n') 
			{
                i++; //skip 
                
				if (buffer[i] == '\r' || buffer[i] == '\n') 
				{
					i++; //skip
				}
				
				// ó�� ������ ��������Ʈ�� �̵��Ѵ�.
                file->Seek(-(long)((read-i)), CFile::current);
                bNEWLINE = TRUE;
                break;
            }

			// ����ó��
			else
			{
				pcStream[i] = buffer[i];
			}
        }

		// ���� ������ 1024���ڳ��� ���Դٸ� bNEWLINE�� �Ѿ�ٴ� ���ϰ��� ó���Ѵ�.
        if (read < 1024) 
		{ 
			//���� ��
            bNEWLINE = TRUE;

			// ���� ������ ���� ���ڿ��� �����Ϳ� ��ü ���ڰ����� �´ٸ� ���� ���µǾ��� 
			// ������ ���ڴ� ������������� �����Ѵ�.
            if (file->GetPosition() == file->GetLength()) 
			{
				bEOF = TRUE;
			}
        } 
    }

    return !bEOF;
} 
