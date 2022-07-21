#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"FileOper.h"
#include"date.h"
#include"ctrl.h"

void Read_code_book_Info(int* pCount)
{
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, ".\\mima.txt", "r");
	if (nError == 0)
	{
		
			fread(&g_num, 4, 1, pFile);
			fread(&nCount, 4, 1, pFile);
			InitDate(g_num);


			for (int i = 0; i < nCount; i++)
			{
				fscanf_s(pFile, "%s", g_pInfo[i].cWebSite,50);
				fscanf_s(pFile, "%s", g_pInfo[i].cUserName,50);
				fscanf_s(pFile, "%s", g_pInfo[i].cPassWord,50);
				fscanf_s(pFile, "%s", g_pInfo[i].cMemo,50);

			}

			printf("Read complete!\n");
			fclose(pFile);
	}

}

void Save_code_book_Info(int nCount)
{

	FILE* pFile = NULL;
	fopen_s(&pFile, ".\\mima.txt", "w");
      
	fwrite(&g_num, 4, 1, pFile);
	fwrite(&nCount, 4, 1, pFile);

	for (size_t i = 0; i < nCount; i++)
	{
		fprintf(pFile, "%s ", g_pInfo[i].cWebSite,50);
		fprintf(pFile, "%s ", g_pInfo[i].cUserName,50);
		fprintf(pFile, "%s ", g_pInfo[i].cPassWord,50);
		fprintf(pFile, "%s ", g_pInfo[i].cMemo,50);

	}


	fclose(pFile);


}