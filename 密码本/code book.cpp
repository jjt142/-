#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"ctrl.h"
#include"date.h"
#include"ShowMenu.h"
#include"FileOper.h"

int main()
{
	//登录模块
	Login_in();                                         
	int flag = Login_in();   
	//登陆失败直接返回
	if (flag == 1)                                     
	{
		return 0;
	}
	
	//获取初始空间
	InitDate(g_num);                                      
	//读入文件
	Read_code_book_Info(&nCount);                         
	while (1)
	{
		//菜单模块
		Menu();                                           
		//获取nSelect,用于选择操作项目
		scanf_s("%d", &nSelect);                         


		//switch选择
		switch (nSelect)                                
		{
			case 查看:                                  
			{
				PrintAllInfo(nCount);   
				system("pause");
				break;
			}
			case 增加:
			{
											
				AddInfo(&nCount);                         
				Save_code_book_Info(nCount);
				break;
			}
			case 修改:
			{
				AlterInfo(nCount);                           
				Save_code_book_Info(nCount);
				break;
			}
			case 查看某站点密码:                             
			{
				PrintOneInfo(nCount);
				system("pause");
				break;
			}
			case 删除:                                  
			{
				DeleteInfo(&nCount);
				Save_code_book_Info(nCount);
				break;
			}

			case 退出:                                  
			{
				int* pExit = &nExit;
				*pExit = 1;
			}

		}


		system("CLS");
		if (nExit == 1)
		{
			Save_code_book_Info(nCount);
			break;
		}
	}
	return 0;
}