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
	//��¼ģ��
	Login_in();                                         
	int flag = Login_in();   
	//��½ʧ��ֱ�ӷ���
	if (flag == 1)                                     
	{
		return 0;
	}
	
	//��ȡ��ʼ�ռ�
	InitDate(g_num);                                      
	//�����ļ�
	Read_code_book_Info(&nCount);                         
	while (1)
	{
		//�˵�ģ��
		Menu();                                           
		//��ȡnSelect,����ѡ�������Ŀ
		scanf_s("%d", &nSelect);                         


		//switchѡ��
		switch (nSelect)                                
		{
			case �鿴:                                  
			{
				PrintAllInfo(nCount);   
				system("pause");
				break;
			}
			case ����:
			{
											
				AddInfo(&nCount);                         
				Save_code_book_Info(nCount);
				break;
			}
			case �޸�:
			{
				AlterInfo(nCount);                           
				Save_code_book_Info(nCount);
				break;
			}
			case �鿴ĳվ������:                             
			{
				PrintOneInfo(nCount);
				system("pause");
				break;
			}
			case ɾ��:                                  
			{
				DeleteInfo(&nCount);
				Save_code_book_Info(nCount);
				break;
			}

			case �˳�:                                  
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