#include "userfunc.h"

int strToInquiry(char* str, char* accNum, const eAccType type)
{
	assert(str != NULL && accNum != NULL && "str or accNum points NULL");

	char* piter = str;
	char* attributes[6] = { NULL,0 };
	wchar_t* wtemps[6] = { NULL, 0 };
	int i = 0;

	//域疎 鎧蝕 嗣奄
	attributes[i++] = piter;
	while (*piter != '\n')
	{
		piter++;
		if (*piter == '|')
		{
			*piter = '\0';
			if (i < 6)
			{
				attributes[i++] = piter + 1;
			}
			else
			{
				break;
			}
		}
	}
	if (strcmp(accNum, attributes[2]) != 0 && type != T1) // 域疎 茨虞辞 窒径
	{
		goto ESCAPE;
	}
	// 展脊端滴
	switch (type)
	{
	case T1:
		for (int i = 0; i < 6; i++)
		{
			wtemps[i] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(attributes[i]) + 1));
			for (int j = 0; j < strlen(attributes[i]) + 1; j++)
			{
				mbtowc(wtemps[i] + j, attributes[i] + j, MB_CUR_MAX);
			}
		}
		if (attributes[4][0] == 'i')
		{
			wprintf(L"< %s >/ %16s: %s/ 榎衝: %s (脊榎)/ 接衝: %s\n",
				wtemps[0], wtemps[1], wtemps[2], wtemps[3], wtemps[5]);
		}
		else if (attributes[4][0] == 'o')
		{
			wprintf(L"< %s >/ %16s: %s/ 榎衝: %s (窒榎)/ 接衝: %s\n",
				wtemps[0], wtemps[1], wtemps[2], wtemps[3], wtemps[5]);
		}
		else
		{
			fprintf(stderr, "In and Out account wrong in printing history\n");
			system("pause");
			break;
		}
		break;
	case T2:
		for (int i = 0; i < 5; i++)
		{
			wtemps[i] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(attributes[i]) + 1));
			for (int j = 0; j < strlen(attributes[i]) + 1; j++)
			{
				mbtowc(wtemps[i] + j, attributes[i] + j, MB_CUR_MAX);
			}
		}
		wprintf(L"< %s >/ %16s: %s/ 幻奄背走獣 榎衝: %s / 薄仙 榎衝: %s\n",
			wtemps[0], wtemps[1], wtemps[2], wtemps[3], wtemps[4]);
		break;
	case T3:
		for (int i = 0; i < 5; i++)
		{
			wtemps[i] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(attributes[i]) + 1));
			for (int j = 0; j < strlen(attributes[i]) + 1; j++)
			{
				mbtowc(wtemps[i] + j, attributes[i] + j, MB_CUR_MAX);
			}
		}
		wprintf(L"< %s >/ %16s: %s/ 置企 杉 崖脊衝: %s/ 薄仙 榎衝: %s\n",
			wtemps[0], wtemps[1], wtemps[2], wtemps[3], wtemps[4]);
		break;
	default:
		fprintf(stderr, "Something wrong in printing history.\n");
		system("pause");
		break;

	}

	for (int k = 0; k < 5; k++)
	{
		free(wtemps[k]);
		wtemps[k] = NULL;
	}
	if (type == T1)
	{
		free(wtemps[5]);
		wtemps[5] = NULL;
	}
	return 1;
ESCAPE:
	return 0;
}
int strToAccInfo(char* str, char* accNum, const eAccType type)
{
	assert(str != NULL && accNum != NULL && "str or accNum points NULL");

	char* piter = str;
	char* attributes[6] = { NULL, };
	char*** autoTransferInfo = NULL;
	char*** autoTemp1 = NULL;
	char** autoTemp2 = NULL;
	wchar_t* wtemps[6] = { NULL, };
	wchar_t** wATInfo = NULL;

	int i = 0;
	size_t l = 0;
	int autoFlags = 0;
	size_t autoNums = 0;



	//域疎 舛左 嗣奄
	attributes[i++] = piter;
	while (*piter != '\n')
	{
		piter++;
		if (*piter == '|')
		{
			*piter = '\0';
			if (i < 6)
			{
				attributes[i++] = piter + 1;
			}
			else
			{
				autoFlags = 1;
				autoNums = 1;
				break;
			}
		}
	}
	//切疑戚端 舛左 嗣奄
	l = autoNums - 1;
	while (autoFlags == 1 && *piter != '\n')
	{
		if (autoTransferInfo == NULL)
		{
			autoTransferInfo = (char***)malloc(sizeof(char**) * autoNums);
			assert(autoTransferInfo != NULL && "\nautoTransferInfo memory allocation failed\n");
			autoTransferInfo[0] = (char**)malloc(sizeof(char*) * 4);
			assert(autoTransferInfo[0] != NULL && "\nautoTransferInfo[0] memory allocation failed\n");
		}
		else if (l == autoNums - 2)
		{
			l++;
			//autoTemp1 = (char***)realloc(autoTransferInfo, sizeof(char**) * autoNums);
			autoTemp1 = (char***)malloc(sizeof(char**) * autoNums);
			assert(autoTransferInfo != NULL && "\nautoTransferInfo memory 're'allocation failed\n");
			memcpy(autoTemp1, autoTransferInfo, sizeof(char**) * autoNums - 1);
			autoTransferInfo = autoTemp1;
			autoTemp1 = NULL;
			for (int d = 0; d < autoNums - 1; d++)
			{
				autoTemp2 = (char**)malloc(sizeof(char*) * 4);
				memcpy(autoTemp2, autoTransferInfo[d], sizeof(char*) * 4);
				autoTransferInfo[d] = autoTemp2;
				autoTemp2 = NULL;
				//autoTemp2 = (char**)realloc(autoTransferInfo,sizeof(char*) * 4);
				//autoTransferInfo[d] = autoTemp2;
				//autoTemp2 = NULL;
			}
			autoTransferInfo[autoNums - 1] = (char**)malloc(sizeof(char*) * 4);
			assert(autoTransferInfo[l] != NULL && "\nautoTransferInfo[l] memory allocation failed\n");
		}
		autoTransferInfo[l][0] = ++piter;
		i = 0;
		while (1)
		{
			if (i % 4 != 0 || i == 0)
			{
				piter++;
				if (*piter == '|')
				{
					*piter = '\0';
					if (i % 4 != 0 || i == 0)
					{
						autoTransferInfo[l][++i] = piter + 1;
					}
				}
			}
			else
			{
				autoNums++;
				break;
			}
		}
		if (*(piter + 1) == '\n')
		{
			break;
		}
	}
ESCAPE:

	for (int i = 0; i < 6; i++)
	{
		wtemps[i] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(attributes[i]) + 1));
		for (int j = 0; j < strlen(attributes[i]) + 1; j++)
		{
			mbtowc(wtemps[i] + j, attributes[i] + j, MB_CUR_MAX);
		}
	}
	wprintf(L"< 脊窒榎 域疎 >/ %16s: %s/ 接衝: %s 戚端廃亀 %s(析)/%s(杉)\n",
		wtemps[0], wtemps[1], wtemps[2], wtemps[4], wtemps[5]);
	if (autoNums != 0)
	{
		wATInfo = (wchar_t**)malloc(sizeof(wchar_t*) * 4);

		for (int u = 0; u < autoNums - 1; u++)
		{
			for (int y = 0; y < 4; y++)
			{
				wATInfo[y] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(autoTransferInfo[u][y]) + 1));
				for (int t = 0; t < strlen(autoTransferInfo[u][y]) + 1; t++)
				{
					mbtowc(wATInfo[y] + t, autoTransferInfo[u][y] + t, MB_CUR_MAX);
				}
			}
			wprintf(L"[切疑戚端 舛左]: 古杉 %s析 %s (幻)据聖 %s 域疎拭 %s 幻鏑 左垣艦陥.\n",
				wATInfo[0], wATInfo[1], wATInfo[2], wATInfo[3]);
		}
	}


	for (int k = 0; k < 5; k++)
	{
		free(wtemps[k]);
		wtemps[k] = NULL;
	}
	if (type == T1)
	{
		free(wtemps[5]);
		wtemps[5] = NULL;
	}
	for (int c = 0; c < 4; c++)
	{
		free(wATInfo[c]);
		wATInfo[c] = NULL;
	}
	free(wATInfo);
	wATInfo = NULL;
	for (int f1 = 0; f1 < autoNums - 2; f1++)
	{
		free(autoTransferInfo[f1]);
		autoTransferInfo[f1] = NULL;
	}

	free(autoTransferInfo);
	autoTransferInfo = NULL;

	return autoNums;
}
int strToFSInfo(char* str, char* accNum, const eAccType type)
{
	assert(str != NULL && accNum != NULL && "str or accNum points NULL");


	char* piter = str;
	char* attributes[7] = { NULL, };
	wchar_t* wtemps[7] = { NULL, };

	int k = 0;
	int flags = 0;

	//域疎 舛左 嗣奄
	attributes[k++] = piter;
	while (*piter != '\n')
	{
		piter++;
		if (*piter == '|')
		{
			*piter = '\0';
			if (k < 7)
			{
				attributes[k++] = piter + k;
			}
			else
			{
				if (strcmp(attributes[1], accNum) == 0)
				{
					flags = 1;
					break;
				}
				else
				{
					k = 0;
					attributes[k++] = ++piter;
					continue;
				}
			}
		}
	}
	if (flags == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			wtemps[i] = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(attributes[i]) + 1));
			for (int j = 0; j < strlen(attributes[i]) + 1; j++)
			{
				mbtowc(wtemps[i] + j, attributes[i] + j, MB_CUR_MAX);
			}
		}
		if (type == T2)
		{
			wprintf(L"< 森榎 域疎 >/ %16s: %s/ 接衝: %s 害精 重短奄娃 %s(析) 戚切晴: %s 背走獣 榎衝 %s\n",
				wtemps[0], wtemps[1], wtemps[2], wtemps[4], wtemps[5], wtemps[6]);
		}
		else
		{
			wprintf(L"< 旋榎 域疎 >/ %16s: %s/ 接衝: %s 害精 重短奄娃 %s(析) 戚切晴: %s 背走獣 榎衝 %s\n",
				wtemps[0], wtemps[1], wtemps[2], wtemps[4], wtemps[5], wtemps[6]);
		}
		for (int f = 0; f < 7; f++)
		{
			free(wtemps[f]);
			wtemps[f] = NULL;
		}
		return 1;
	}
	return 0;
}
int setError(FILE* f_accList)
{
	assert(f_accList != NULL && "accList is NULL");

	long CurrentFileOffset = 0;
	
	int i = 0;
	int accNumToCheck = 0;
	char* piter;
	char** accNums = NULL;
	eAccType type;
	FILE* f_setter;

	while (1)// 域疎 鯵呪歯奄
	{
		fseek(f_accList, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_accList);
		if (feof(f_accList))
		{
			break;
		}
		accNumToCheck++;
		CurrentFileOffset = ftell(f_accList);
	}
	i = 0;
	CurrentFileOffset = 0;

	accNums = (char**)malloc(sizeof(char*) * accNumToCheck);
	for (int j = 0; j < accNumToCheck; j++)
	{
		accNums[j] = (char*)malloc(sizeof(char) * 8);
	}
	while (i < accNumToCheck) // 域疎腰硲 獄遁拭 眼奄
	{
		fseek(f_accList, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_accList);
		if (feof(f_accList))
		{
			break;
		}
		strncpy(accNums[i], g_buffer, 7);
		accNums[i++][7] = '\0';
		CurrentFileOffset = ftell(f_accList);
	}
	int senseError = 0;
	for (int f = 0; f < accNumToCheck; f++) //欠覗宜檎辞
	{
		// 背雁 督析達焼亜奄
		wchar_t waccNums[8];
		for (int i = 0; i < 8; i++)
		{
			mbtowc(waccNums+i, accNums[f]+i, MB_CUR_MAX);
		}
		switch (accNums[f][2]) // 展脊端滴
		{
		case '1': // 脊窒榎
			type = T1;
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%s.txt", waccNums[1], waccNums);
			f_setter = _wfopen(g_wpath, L"r+");
			if (checkAcc(f_setter) == 1)
			{
				fclose(f_setter);
				f_setter = NULL;
				wprintf(L"File: \"%s\" need to correction...\n terminate program...", g_wpath);
				goto NEEDTOCORRECTFILE;
			}
			fclose(f_setter);
			f_setter = NULL;
			break;
		case '2': // 森榎
			type = T2;
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%c%c%c.txt", waccNums[1], waccNums[0], waccNums[1], waccNums[2]);
			f_setter = _wfopen(g_wpath, L"r+");
			if (checkFix(f_setter) == 1)
			{
				fclose(f_setter);
				f_setter = NULL;
				wprintf(L"File: \"%s\" need to correction...\n terminate program...", g_wpath);
				goto NEEDTOCORRECTFILE;
			}
			fclose(f_setter);
			f_setter = NULL;
			break;
		case'3': // 旋榎
			type = T3;
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%c%c%c.txt", waccNums[1], waccNums[0], waccNums[1], waccNums[2]);
			f_setter = _wfopen(g_wpath, L"r+");
			if (checkSav(f_setter) == 1)
			{
				fclose(f_setter);
				f_setter = NULL;
				wprintf(L"File: \"%s\" need to correction...\n terminate program...", g_wpath);
				goto NEEDTOCORRECTFILE;
			}
			fclose(f_setter);
			f_setter = NULL;
			break;
		default:
			assert("Critical + fatal + horrendous error.... function: \"setInterset()\"" && 0);
		}
	}
	for (int k = 0; k < accNumToCheck; k++)
	{
		free(accNums[k]);
		accNums[k] = NULL;
	}
	free(accNums);
	accNums = NULL;
	return 0;
NEEDTOCORRECTFILE:
	return 1;
}
int checkAcc(FILE* f_target) // 石生形壱...戚背馬形壱 獣亀馬走原室推 せせせせせせ
{
	assert(f_target != NULL && "f_target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume=6;
	char* piter = NULL;
	char* pFileOffset =NULL;
	while (1)
	{
		fseek(f_target, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_target);
		if (feof(f_target))
		{
			break;
		}
		piter = g_buffer;
		pFileOffset = g_buffer;
		if (line == 0) //湛腰属匝
		{
			while ((*piter)!='|') // 域疎戚硯
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset+1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char),1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char),19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '\n') //蟹袴走 袷 収切
			{
				if (isdigit(*piter) == 0 && (*piter)!='|')
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
		}
		else//砧腰属 匝 ~ 
		{
			while ((*piter) != '|') // 劾促
			{
				if (isdigit(*piter) == 0 && *piter != '-')
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|') // 焼戚巨
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//域疎腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//儀
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if ((*piter) != 'o' && (*piter) != 'i') // i or o
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//接衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			
		}
		line++;
		CurrentFileOffset = ftell(f_target);
	}
	
	
	return 0;
}
int checkFix(FILE* f_target)
{
	assert(f_target != NULL && "f_target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume = 6;
	char* piter = NULL;
	char* pFileOffset = NULL;
	while (1)
	{
		fseek(f_target, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_target);
		if (feof(f_target))
		{
			break;
		}
		piter = g_buffer;
		pFileOffset = g_buffer;
		if (line == 0) //湛腰属匝
		{
ANOTHER_ACCOUNT:
			while ((*piter) != '|') // 域疎戚硯
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//域疎腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.') //薄仙榎衝
				{
					while (*(++pFileOffset) != '\n' )
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//搾腔腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)// 害精 奄娃
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')// 戚切晴
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')// 背走獣 榎衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			if (*piter++ == ' ')
			{
				goto ANOTHER_ACCOUNT;
			}
		}
		else //砧腰属 匝 ~ 
		{
			while ((*piter) != '|') // 劾促
			{
				if (isdigit(*piter) == 0 && *piter != '-')
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|') // 焼戚巨
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//域疎腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')//幻奄獣 背走 榎衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0&&(*piter) != '.')//接衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;

		}
		line++;
		CurrentFileOffset = ftell(f_target);
	}
	return 0;
}
int checkSav(FILE* f_target)
{
	assert(f_target != NULL && "f_target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume = 6;
	char* piter = NULL;
	char* pFileOffset = NULL;
	while (1)
	{
		fseek(f_target, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_target);
		if (feof(f_target))
		{
			break;
		}
		piter = g_buffer;
		pFileOffset = g_buffer;
ANOTHER:
		if (line == 0) //湛腰属匝
		{

 			while ((*piter) != '|') // 域疎戚硯
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//域疎腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.') //薄仙榎衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//搾腔腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)// 害精 奄娃
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')// 戚切晴
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')// 背走獣 榎衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			if (*piter++ == ' ')
			{
				goto ANOTHER;
			}
		}
		else //砧腰属 匝 ~ 
		{
			while ((*piter) != '|') // 劾促
			{
				if (isdigit(*piter) == 0 && *piter != '-')
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|') // 焼戚巨
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0)//域疎腰硲
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')//幻奄獣 背走 榎衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|' && (*piter) != '.')
			{
				if (isdigit(*piter) == 0)//接衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), 1024, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
		}
		line++;
		CurrentFileOffset = ftell(f_target);
	}
	return 0;
}
int setInterest(FILE* f_target)
{

	time_t curTime;
	struct tm* pTS;
	curTime = time(NULL);
	pTS = localtime(&curTime);

	int year;
	int month;
	int day;

	year = pTS->tm_year + 1900;
	month = pTS->tm_mon + 1;
	day = pTS->tm_mday;
}