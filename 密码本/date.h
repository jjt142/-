#pragma once
#define �鿴 1
#define ���� 2
#define �޸� 3
#define �鿴ĳվ������ 4
#define ɾ�� 5
#define ��ʼ���� 4
#define �˳� 00000

typedef struct _TEXTINFO
{
	char cWebSite[50];
	char cUserName[50];
	char cPassWord[50];
	char cMemo[50];
}TEXTINFO, * pTEXTINFO;

extern TEXTINFO* g_pInfo;              
extern int g_num;                      
extern int  nCount;                    
extern int nExit;                      
extern int nSelect;                    

