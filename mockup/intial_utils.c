#include "userfunc.h"

// 拭君 端滴 敗呪
int setError()
{
	int tempnamelen = 0;
	eAccType type;
	FILE* f_setter;

	setAccListOfAll_malloc();

	for (int f = 0; f < g_allALANNums; f++) //欠覗宜檎辞
	{
		// 背雁 督析達焼亜奄
		wchar_t waccNums[8];
		for (int i = 0; i < 8; i++)
		{
			mbtowc(waccNums + i, g_allAccountsListAndName[0][f] + i, MB_CUR_MAX);
		}
		switch (getAccType(g_allAccountsListAndName[0][f])) // 展脊端滴
		{
		case T1: // 脊窒榎
			type = T1;
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%s.txt", waccNums[1], waccNums);
			f_setter = _wfopen(g_wpath, L"r+");
			if (checkIO(f_setter) == 1)
			{
				fclose(f_setter);
				f_setter = NULL;
				wprintf(L"File: \"%s\" need to correction...\n terminate program...", g_wpath);
				goto NEEDTOCORRECTFILE;
			}
			fclose(f_setter);
			f_setter = NULL;
			break;
		case T2: // 森榎
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
		case T3: // 旋榎
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
			assert("Account Lists file is something wrong.... function: \"setInterset()\"" && 0);
		}
	}
	return 0;
NEEDTOCORRECTFILE:
	return 1;
}
// 脊窒榎域疎督析 端滴
int checkIO(FILE* f_target) // 石生形壱...戚背馬形壱 獣亀馬走原室推 せせせせせせ
{
	assert(f_target != NULL && "I can't find file by account.txt..target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume = 6;
	char* piter = NULL;
	char* pFileOffset = NULL;
	size_t numOfBefore = 0;
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
			while ((*piter) != '|') // 域疎戚硯
			{
				if (isalnum(*piter) == 0)
				{
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '\n') //蟹袴走 袷 収切
			{
				if (isdigit(*piter) == 0 && (*piter) != '|')
				{
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
// 森榎域疎督析 端滴
int checkFix(FILE* f_target)
{
	assert(f_target != NULL && "f_target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume = 6;
	char* piter = NULL;
	char* pFileOffset = NULL;
	size_t numOfBefore = 0;
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
					fwrite(g_filebuff, sizeof(char), numOfWords, f_target);
					return 1;
				}
				piter++;
			}
			piter++;
			while ((*piter) != '|')
			{
				if (isdigit(*piter) == 0 && (*piter) != '.')//接衝
				{
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
// 旋榎域疎督析 溌昔
int checkSav(FILE* f_target)
{
	assert(f_target != NULL && "f_target is NULL");

	long CurrentFileOffset = 0;
	int line = 0;
	int delNume = 6;
	char* piter = NULL;
	char* pFileOffset = NULL;
	size_t numOfBefore = 0;
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
					fseek(f_target, CurrentFileOffset, SEEK_SET);
					while (*(pFileOffset++) != '\n')
					{
						CurrentFileOffset++;
						numOfBefore++;
					}
					fread(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					f_target = _wfreopen(g_wpath, L"w+", f_target);
					fwrite(g_filebuff2, sizeof(char), numOfBefore, f_target);
					fwrite("<-- correct typos", sizeof(char), 18, f_target);
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
// 戚切 旋遂
void setInterest()
{
	FILE* f_checker;
	wchar_t waccNums[8];

	for (int f = 0; f < g_allALANNums; f++) //欠覗宜檎辞
	{
		// 背雁 督析達焼亜奄
		switch (getAccType(g_allAccountsListAndName[0][f])) // 展脊端滴
		{
		case T1: // 脊窒榎 鳶什
			break;
		case T2: // 森榎
		case T3: // 旋榎
			for (int i = 0; i < 8; i++)
			{
				mbtowc(waccNums + i, g_allAccountsListAndName[0][f] + i, MB_CUR_MAX);
			}
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%c%c%c.txt", waccNums[1], waccNums[0], waccNums[1], waccNums[2]);
			f_checker = _wfopen(g_wpath, L"r+");
			setFSInterest(f_checker, g_allAccountsListAndName[0][f]);
			fclose(f_checker);
			f_checker = NULL;
			break;
		default:
			assert("Account Lists file is something wrong.... function: \"setInterset()\"");
		}
	}
}
// 森旋榎 戚切 旋遂
int setFSInterest(FILE* f_accfile, const char* AccNum)
{
	long CurrentFileOffset = 0;
	long AttOffset = 0;
	long beforBal = 0;
	long afterBal = 0;
	int remainService = 0;
	int flag = 0;
	size_t numOfBefore = 0;

	double interestRatio = 0;

	int line = 0;
	int inputMonth = 0;
	int inputDay = 0;
	int inputYear = 0;

	char check = 0;

	char* pcp = NULL;
	char* pgb = NULL;
	char* temp = NULL;

	size_t templen = 0;
	size_t pcplen = 0;

	// 獄遁
	FSattributes_t* targetAT = (FSattributes_t*)malloc(sizeof(FSattributes_t));
	FSinqury_t* targetIQ = (FSinqury_t*)malloc(sizeof(FSinqury_t));
	assert(targetAT != NULL && targetIQ != NULL && "setSavInterest() allocation failed");

	pcplen = fread(g_tempbuff, sizeof(char), FILE_BUFF, f_accfile);
	fflush(f_accfile);
	g_tempbuff[pcplen] = '\0';
	pcp = g_tempbuff;
	pgb = g_buffer;
	while (*pcp != '\0')
	{
		if (*pcp != '\n')
		{
			*pgb++ = *pcp++;
		}
		else
		{
			*pgb = '\0';
			//printf("%s\n", g_buffer);
			if (flag == 0)
			{
				AttOffset = strToFSatt(g_buffer, targetAT, AccNum);
				flag = 1;
			}
			else
			{
				strToFSiq(g_buffer, targetIQ, AccNum);
				inputYear = atoi(&(targetIQ->FS_date[0]));
				inputMonth = atoi(&(targetIQ->FS_date[5]));
				inputDay = atoi(&(targetIQ->FS_date[8]));
				if (inputYear == g_year && inputMonth == g_month &&
					inputDay == g_day && *(targetIQ->FS_income) == '0' &&
					(strcmp(AccNum, targetIQ->FS_mynum) == 0))
				{ // 戚切 設 細嬢赤生檎 蟹亜奄
					free(targetAT);
					free(targetIQ);
					targetAT = NULL;
					targetIQ = NULL;

					fprintf(stdout, "%s good\n", AccNum);
					return 1;
				}
			}
			pcp++;
			pgb = g_buffer;
			memset(g_buffer, '\0', BUFF_SIZE); // 焼艦檎 陥製牒.
		}
	} // 陥 達焼坐亀 蒸生檎
	remainService = atoi(targetAT->FS_remainService);
	if (remainService == 0) // 害精 奄娃 0戚檎 蒸蕉奄
	{
		free(targetAT);
		free(targetIQ);
		targetAT = NULL;
		targetIQ = NULL;

		fprintf(stdout, "%s no remain\n", AccNum);
		return 0;
	}//戚切 域至
	beforBal = atol(targetAT->FS_balance);
	interestRatio = atof(targetAT->FS_interest);
	afterBal = beforBal + (long)(beforBal * interestRatio / 100);



	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}//紗失 床奄
	templen = sizeof(FSattributes_t) / sizeof(char) + 8;
	temp = (char*)malloc(sizeof(char) * templen);
	assert(temp != NULL && "setSavInterset allocation failed");

	if (T3 == getAccType(targetAT->FS_mynum)) // 旋榎戚檎 杉 置企 崖脊衝 段奄鉢
	{
		sprintf(temp, "%s|%s|500000|%s|%d|%.1f|%ld|",
			targetAT->FS_name, targetAT->FS_mynum,targetAT->FS_Passwords,
			remainService - 1, interestRatio, afterBal);
		//system("pause");
		printf("%s\n", temp);
	}
	else
	{
		sprintf(temp, "%s|%s|%s|%s|%d|%.1f|%ld|",
			targetAT->FS_name, targetAT->FS_mynum, targetAT->FS_money,
			targetAT->FS_Passwords, remainService - 1, interestRatio, afterBal);
		printf("%s\n", temp);
		//system("pause");
	}


	//督析拭 床奄
	CurrentFileOffset = AttOffset;
	fseek(f_accfile, CurrentFileOffset, SEEK_SET);

	while (check != ' ' && check != '\n')
	{
		check = fgetc(f_accfile);
		CurrentFileOffset++;
	}
	CurrentFileOffset--;

	if (AttOffset > 0) // 掻娃拭 恩醤拝 凶
	{
		fseek(f_accfile, 0, SEEK_SET); //蒋拭依
		numOfBefore = fread(g_filebuff2, sizeof(char), AttOffset, f_accfile);
	}
	fseek(f_accfile, CurrentFileOffset, SEEK_SET);// 及拭依
	size_t numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_accfile);
	//printf("g_filebuff:\n %s", g_filebuff);
	f_accfile = _wfreopen(g_wpath, L"w+", f_accfile);
	if (AttOffset > 0)
	{
		fwrite(g_filebuff2, sizeof(char), numOfBefore, f_accfile);
	}
	fwrite(temp, sizeof(char), strlen(temp), f_accfile);
	fflush(f_accfile);
	fwrite(g_filebuff, sizeof(char), numOfWords, f_accfile);
	fflush(f_accfile);

	free(temp);
	temp = NULL;

	//戚切 鎧蝕 床奄
	CurrentFileOffset = 0;
	fseek(f_accfile, CurrentFileOffset, SEEK_END);

	templen = sizeof(FSinqury_t) / sizeof(char) + 5;
	temp = (char*)malloc(sizeof(char) * templen);
	assert(temp != NULL && "setSavInterset allocation failed");

	sprintf(temp, "%d-%d-%d|%s|%s|0|%ld|\n",
		g_year, g_month, g_day, targetAT->FS_name, AccNum, afterBal);

	printf("%s\n", temp);

	fwrite(temp, sizeof(char), strlen(temp), f_accfile);
	fflush(f_accfile);

	free(temp);
	temp = NULL;

	fprintf(stdout, "%s bad\n", AccNum);
	return 0;
}
// 切疑戚端 旋遂
int setAutoTransfer()
{
	int tempnamelen = 0;
	eAccType type;
	FILE* f_setter;
	IOattributes_malloc_t* ISatt = NULL;

	setAccListOfAll_malloc();

	for (int f = 0; f < g_allALANNums; f++) //欠覗宜檎辞
	{
		// 背雁 督析達焼亜奄
		ISatt = (IOattributes_malloc_t*)malloc(sizeof(IOattributes_malloc_t));
		assert(ISatt != NULL && "ISatt allocation failed \"setAutoTransfer()\"");
		wchar_t waccNums[8];
		for (int i = 0; i < 8; i++)
		{
			mbtowc(waccNums + i, g_allAccountsListAndName[0][f] + i, MB_CUR_MAX);
		}
		switch (getAccType(g_allAccountsListAndName[0][f])) // 展脊端滴
		{
		case T1: // 脊窒榎
			type = T1;
			swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%s.txt", waccNums[1], waccNums);
			f_setter = _wfopen(g_wpath, L"r+");
			fgets(g_buffer, BUFF_SIZE, f_setter);
			strToIOatt_malloc(g_buffer, ISatt);
			if (ISatt->autoNums > 0)
			{
				setAutoIOTransfer(f_setter);
				freeIOattriutes(ISatt);
				free(ISatt);
				ISatt = NULL;
			}
			else
			{
				freeIOattriutes(ISatt);
				free(ISatt);
				ISatt = NULL;
			}
			fclose(f_setter);
			f_setter = NULL;
			break;
		case T2: // 森榎
		case T3: // 旋榎
			break;
		default:
			assert("Account Lists file is something wrong.... function: \"setInterset()\"" && 0);
		}
	}
	free(ISatt);
	ISatt = NULL;
	return 0;
}
// 脊窒榎 切疑戚端 旋遂
int setAutoIOTransfer(FILE* f_io)
{
	assert(f_io != NULL && "setAutoIOTransfer() f_io is NULL");
	IOattributes_malloc_t* IOatt = (IOattributes_malloc_t*)malloc(sizeof(IOattributes_malloc_t));
	IOinqury_t* IOiq = (IOinqury_t*)malloc(sizeof(IOinqury_t));

	FILE* f_temp = f_io;

	fseek(f_temp, 0, SEEK_SET);
	fgets(g_buffer, BUFF_SIZE, f_temp);
	strToIOatt_malloc(g_buffer, IOatt);
	char toerase[30];
	for (int i = 0; i < IOatt->autoNums; i++)
	{
	ESCAPE:
		if (g_day == atoi(IOatt->autoattributes[i][0]))
		{
			while (1)
			{
				fgets(g_buffer, BUFF_SIZE, f_temp);
				if (feof(f_temp))
				{
					break;
				}
				strToIOiq(g_buffer, IOiq);
				if (g_year == atoi(IOiq->IO_date) && g_month == atoi(&(IOiq->IO_date[5])) && g_day == atoi(&(IOiq->IO_date[8])) &&
					(strncmp(IOatt->autoattributes[i][2], IOiq->IO_othernum, 7) == 0) &&
					strncmp(IOatt->autoattributes[i][1], IOiq->IO_money, strlen(IOiq->IO_money)) == 0)
				{
					goto ESCAPE;
				}
			}
			moneyOutIO(IOatt->IO_mynum, IOatt->autoattributes[i][2], atol(IOatt->autoattributes[i][1]), 0);
			switch (getAccType(IOatt->autoattributes[i][2]))
			{
			case T1:
				moneyInIO(IOatt->autoattributes[i][2], IOatt->IO_mynum, atol(IOatt->autoattributes[i][1]));
				sprintf(toerase, "%s|%s|%s|%s|", IOatt->autoattributes[i][0], IOatt->autoattributes[i][1], IOatt->autoattributes[i][2], IOatt->autoattributes[i][3]);
				eraseAuto(IOatt->IO_mynum, toerase, 1);
				PRINTLEFT(L"戚端 鞠醸柔艦陥.");
				break;
			case T3:
				if (moneyInFS(IOatt->autoattributes[i][2], atol(IOatt->autoattributes[i][1]), 0) == 1)
				{
					sprintf(toerase, "%s|%s|%s|%s|", IOatt->autoattributes[i][0], IOatt->autoattributes[i][1], IOatt->autoattributes[i][2], IOatt->autoattributes[i][3]);
					eraseAuto(IOatt->IO_mynum, toerase, 1);
					PRINTLEFT(L"戚端 鞠醸柔艦陥.");
				}
				break;
			default:
				break;
			}
		}

	}

	return 0;
}
// 汽戚斗督析戚櫛 業旭戚 背操亜走壱 角移操醤, 肢薦研 馬暗蟹 判呪研 匝食掃艦陥. 肢薦 叔鳶馬檎 0 失因馬檎 1
int eraseAuto(const char* accNum, const char* toerase, int num)
{
	assert(accNum != NULL && toerase != NULL && "src is NULL moneyOutIO() function");

	FILE* f_IO;
	long CurrentFileOffset = 0;
	char* gp = NULL;
	IOattributes_malloc_t* IOatt = (IOattributes_malloc_t*)malloc(sizeof(IOattributes_malloc_t));

	if (g_tempwcp != NULL)
	{
		free(g_tempwcp);
		g_tempwcp = NULL;
	}
	// 督析 達焼亜奄
	g_tempwcp = (wchar_t*)malloc(sizeof(wchar_t) * (strlen(accNum) + 1));
	for (int i = 0; i < strlen(accNum) + 1; i++)
	{
		mbtowc(g_tempwcp + i, accNum + i, MB_CUR_MAX);
	}
	swprintf(g_wpath, MAX_PATH, L"C:\\banksystemlog\\0%c\\%s.txt", *(g_tempwcp + 1), g_tempwcp);
	free(g_tempwcp);
	g_tempwcp = NULL;

	f_IO = _wfopen(g_wpath, L"r+");
	fseek(f_IO, 0, SEEK_SET);
	fgets(g_buffer, BUFF_SIZE, f_IO);
	strToIOatt_malloc(g_buffer, IOatt);
	int j = 0;

	gp = g_buffer;
	for (int i = 0; i < 5; i++)
	{
		while (*gp++ != '|');
	}
	while (*gp != '\n')
	{
		if (strncmp(toerase, gp, strlen(toerase)) == 0)
		{
			int remain = atoi(IOatt->autoattributes[j][3]);
			char temp[30];
			if (remain - num > 0)
			{
				sprintf(temp, "%s|%s|%s|%d|", IOatt->autoattributes[j][0], IOatt->autoattributes[j][1], IOatt->autoattributes[j][2], remain - num);
			}

			CurrentFileOffset = (long)(gp - g_buffer);
			fseek(f_IO, 0, SEEK_SET);
			size_t num2 = fread(g_filebuff2, sizeof(char), CurrentFileOffset, f_IO);
			fseek(f_IO, CurrentFileOffset + (long)strlen(toerase), SEEK_SET);
			size_t num1 = fread(g_filebuff, sizeof(char), FILE_BUFF, f_IO);

			f_IO = _wfreopen(g_wpath, L"w+", f_IO);
			fseek(f_IO, 0, SEEK_SET);
			fwrite(g_filebuff2, sizeof(char), num2, f_IO);
			if (remain - num > 0)
			{
				fwrite(temp, sizeof(char), strlen(temp), f_IO);
			}
			fwrite(g_filebuff, sizeof(char), num1, f_IO);
			fflush(f_IO);
			fclose(f_IO);

			return 1;
		}
		else
		{
			j++;
			for (int i = 0; i < 4; i++)
			{
				while (*gp++ != '|');
			}
		}
	}
	return 0;
}
// 焼戚巨稽 紫遂切 社政 域疎軒什闘 持失 域疎 鯵呪 鋼発
int setAccListByID_malloc(const char* ID)
{

	assert(ID != NULL && "ID is NULL");
	long CurrentFileOffset = 0;
	int bDulpicate = 0;

	char* IDs = NULL;
	int AccountsNums = 0;
	int i = 0;
	char* pbuf = NULL;
	char* pbuftemp = NULL;
	char* pID = NULL;

	CurrentFileOffset = setBankByID(ID);

	fseek(f_MemberFile, CurrentFileOffset, SEEK_SET);
	fgets(g_buffer, BUFF_SIZE, f_MemberFile);
	if (feof(f_MemberFile))
	{
		return 0;
	}
	pbuf = g_buffer;
	pID = IDs;
	for (int j = 0; j < 4; j++)
	{
		while (*pbuf++ != '|')
		{
			CurrentFileOffset++;
		}
	}
	pbuftemp = pbuf;
	while (*pbuf != '\0')
	{
		if (*pbuf++ == '|')
		{
			AccountsNums++;
		}
	}
	pbuf = pbuftemp;

	if (g_userAccountsList != NULL)
	{

		for (int h = 0; h < g_userALNums; h++)
		{
			free(g_userAccountsList[h]);
			g_userAccountsList[h] = NULL;
		}
		free(g_userAccountsList);
		g_userAccountsList = NULL;
	}
	g_userALNums = AccountsNums;

	if (g_userALNums != 0)
	{
		g_userAccountsList = (char**)malloc(sizeof(char*) * g_userALNums);
		assert(g_userAccountsList != NULL && "g_userAccountsList memory allocation is failed");
		for (int k = 0; k < g_userALNums; k++)
		{
			g_userAccountsList[k] = (char*)malloc(sizeof(char) * 8);
			assert(g_userAccountsList[k] != NULL && "g_userAccountsList[i] memory allocation is failed");
			for (int h = 0; h < 7; h++)
			{
				g_userAccountsList[k][h] = *pbuf++;
			}
			pbuf++;
			g_userAccountsList[k][7] = '\0';
			//printf("%s\n", g_userAccountsList[k]);
		}
		return g_userALNums;
	}
	return 0;
}
// 域疎軒什闘 督析 閲嬢辞 獄遁拭 隔奄. 域疎 鯵呪 鋼発
int setAccListOfAll_malloc()
{
	long CurrentFileOffset = 0;

	int i = 0;
	size_t tempnamelen = 0;
	int AccountNums = 0;
	char* piter = NULL;;
	char* pitertemp = NULL;

	while (1)// 域疎 鯵呪歯奄
	{
		fseek(f_AccountList, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_AccountList);
		//printf("%s", g_buffer);
		if (feof(f_AccountList))
		{
			break;
		}
		AccountNums++;
		CurrentFileOffset = ftell(f_AccountList);
	}

	if (g_allAccountsListAndName != NULL)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < g_allALANNums; h++)
			{
				free(g_allAccountsListAndName[k][h]);
				g_allAccountsListAndName[k][h] = NULL;
			}
			free(g_allAccountsListAndName[k]);
			g_allAccountsListAndName[k] = NULL;
		}
		free(g_allAccountsListAndName);
		g_allAccountsListAndName = NULL;
	}
	g_allALANNums = AccountNums;
	//printf("%d", g_allALANNums);

	g_allAccountsListAndName = (char***)malloc(sizeof(char**) * 2);
	assert(g_allAccountsListAndName != NULL && "g_allAcountsListAndName allocation failed");
	for (int j = 0; j < 2; j++)
	{
		g_allAccountsListAndName[j] = (char**)malloc(sizeof(char*) * g_allALANNums);
		assert(g_allAccountsListAndName[j] != NULL && "g_allAcountsListAndName allocation failed");
	}
	for (int k = 0; k < g_allALANNums; k++)
	{
		g_allAccountsListAndName[0][k] = (char*)malloc(sizeof(char) * 8);
		assert(g_allAccountsListAndName[0][k] != NULL && "g_allAcountsListAndName allocation failed");

	}
	CurrentFileOffset = 0;
	i = 0;
	while (i < g_allALANNums) // 域疎腰硲 獄遁拭 眼奄
	{
		tempnamelen = 0;
		fseek(f_AccountList, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_AccountList);
		if (feof(f_AccountList))
		{
			break;
		}
		piter = g_buffer;
		strncpy(g_allAccountsListAndName[0][i], g_buffer, 7);
		g_allAccountsListAndName[0][i][7] = '\0';
		//printf("%s |", g_allAccountsListAndName[0][i]);

		while (*piter++ != '|');
		pitertemp = piter;
		while (*piter++ != '|')
		{
			tempnamelen++;
		}
		g_allAccountsListAndName[1][i] = (char*)malloc(sizeof(char) * (tempnamelen + 1));
		assert(g_allAccountsListAndName[1][i] != NULL && "g_allAcountsListAndName allocation failed");

		strncpy(g_allAccountsListAndName[1][i], pitertemp, tempnamelen);
		g_allAccountsListAndName[1][i][tempnamelen] = '\0';
		//printf("%s\n", g_allAccountsListAndName[1][i]);

		CurrentFileOffset = ftell(f_AccountList);
		i++;
	}
	//system("pause");
	return g_allALANNums;

}