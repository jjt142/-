#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"ctrl.h"
#include"date.h"





int Login_in()
{
	char ca1[20] = {};
	char ca2[20] = {};
	char ca3;
	char pw;


	int	i, j, a = 0;
	int	flag = 0;
	char sz1[30] = { "admin" };
	char sz2[30] = { "password" };

	printf("--------【logn in】--------\n");
	for (i = 0; i < 3; i++)
	{
		printf("USERNAME:");
		scanf_s("%s", ca1, 20);

		printf("logn in:");
		scanf_s("%s", ca2, 20);

		if ((strcmp(ca1, sz1) == 0) && (strcmp(ca2, sz2) == 0))
		{
			flag = 1;
			break;
		}


		if (flag == 1)
		{
			printf("\nsucced!");
			printf("enter!\n");
			system("pause");
			system("cls");

			return 0;

		}
		else
		{
			printf("\nERROR %d：\n", 2 - i);
			return 1;
		}
	}
	if (i == 3)
	{
		printf("ERROR\n");
		return 1;
		
	}
	
}



void InitDate(int g_num)                                   
{
	//获取内存 数目是1
	g_pInfo = (TEXTINFO*)malloc(sizeof(TEXTINFO) * g_num);    
	//初始化
	memset(g_pInfo, 0, sizeof(TEXTINFO) * g_num);              
}

void PrintAllInfo(int nCount)                                           
{
	for (int i = 0; i < nCount; i++)
	{
		printf("WebSite: %s UserName: %s PassWord: %s Memo: %s \n", g_pInfo[i].cWebSite, g_pInfo[i].cUserName, g_pInfo[i].cPassWord, g_pInfo[i].cMemo);
	}
	printf("view success");

}

void AddInfo(int* pCount)
{	//  检查容量 如果不够
	if (*pCount == g_num)                                                            
	{
		//申请原来两倍大的内存
		TEXTINFO* pTemp = (TEXTINFO*)malloc(g_num*2 * sizeof(TEXTINFO));         
		//将申请的空间初始化为零
		memset(pTemp, 0, sizeof(TEXTINFO) * g_num*2);        
		//将原始数据拷贝进新的内存内存
		memcpy(pTemp, g_pInfo, g_num * sizeof(TEXTINFO));      
		//释放掉原来的内存
		free(g_pInfo);          
		//让全局变量的指针指向新的空间
		g_num *= 2;
		g_pInfo = pTemp;                                                            


		return;
	}


	char arr[4][50];
	
	
	printf("Please enter your WebSite:");
	scanf_s("%s", arr[0], 50);
	printf("Please enter your UserName:");
	scanf_s("%s", arr[1], 50);
	printf("Please enter your PassWord:");
	scanf_s("%s", arr[2], 50);
	printf("Please enter your Memo:");
	scanf_s("%s", arr[3], 50);
	strcpy_s(g_pInfo[*pCount].cWebSite, 50, arr[0]);
	strcpy_s(g_pInfo[*pCount].cUserName, 50, arr[1]);
	strcpy_s(g_pInfo[*pCount].cPassWord, 50, arr[2]);
	strcpy_s(g_pInfo[*pCount].cMemo, 50, arr[3]);
	(*pCount)++;


}

void AlterInfo(int nCount)                                 
{
	nCount++;
	printf("Which WebSite do you want to revise,Please enter:");       
	//定义一个数组用于比对 website
	char buf[50] = { 0 };                                                              
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(buf,g_pInfo[i].cWebSite) == 0)                                      
		{
			printf("Please enter your UserName:");                                     
			printf("Please enter your PassWord:");
			scanf_s("%s",g_pInfo[i].cPassWord, 50);
			printf("Please enter your Memo:");
			scanf_s("%s",g_pInfo[i].cMemo, 50);
			nFind = 1;
		    printf("Delete successful!\n");
			system("pause");
		}
	}
		if(nFind==0)
		{
			printf("ERROR!!! Please check carefully !");
		    system("pause");
		}
}

void PrintOneInfo(int nCount)                                  
{
	nCount++;
	int nFind = 0;
	printf("Which WebSite do you want to find,Please enter:");
	char buf[50] = { 0 };                                                              
	scanf_s("%s", buf, 50);
	
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(buf, g_pInfo[i].cWebSite) == 0)                                    
		{
			nFind = 1;
			printf("WebSite: %s UserName: %s PassWord: %s Memo: %s \n", g_pInfo[i].cWebSite, g_pInfo[i].cUserName, g_pInfo[i].cPassWord, g_pInfo[i].cMemo);
		}
		
	}
    if(nFind == 0)
	printf("ERROR!!! Please check carefully !");
	system("pause");
}

void DeleteInfo(int* pCount)                             
{
	printf("Which WebSite do you want to delete,Please enter:");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	for (int i = 0; i < *pCount; i++)
	{
		if (strcmp(buf, g_pInfo[i].cWebSite) == 0)
		{
			for (int j = i; j< *pCount - 1; j++)
			{
				g_pInfo[j] = g_pInfo[j + 1];
			}
			printf("Delete successful!\n");
			system("pause");
		}
		else
			printf("ERROR!!! Please check carefully !");
	}
	(*pCount)--;
}

