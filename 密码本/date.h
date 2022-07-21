#pragma once
#define 查看 1
#define 增加 2
#define 修改 3
#define 查看某站点密码 4
#define 删除 5
#define 初始容量 4
#define 退出 00000

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

