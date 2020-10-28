#include "userfunc.h"


// 収切 焼艦檎 1鋼発, 因拷(?)戚檎 2 鋼発, 収切檎 0鋼発
int checkDigit(const char* ap_string)
{
	char* p_dest = ap_string;
	while (*p_dest != '\0')
	{
		if (isdigit(*p_dest) == 0)
		{
			if (*p_dest == ' ' || *p_dest == '\t')
			{
				return 2;
			}
			return 1;
		}
		p_dest++;
	}
	return 0;
}
//収切 or 慎庚切 焼艦檎 1鋼発
int checkAlnum(const char* ap_string)
{
	char* p_dest = ap_string;
	while (*p_dest != '\0')
	{
		if (isalnum(*p_dest) == 0)
		{
			return 1;
		}
		p_dest++;
	}
	return 0;
}
// 収切 + 慎庚切亜 焼艦檎 1鋼発
int checkID(const char* ap_string)
{
	char* p_dest = ap_string;
	int IDcon[2] = { 0, };

	while (*p_dest != '\0')
	{
		if (isalnum(*p_dest) == 0)
		{
			return 1;
		}
		else if (isdigit(*p_dest) != 0)
		{
			IDcon[1] = 1;
		}
		else
		{
			IDcon[0] = 1;
		}
		p_dest++;
	}
	if (IDcon[0] && IDcon[1])
	{
		return 0;
	}
	return 1;
}
// 慎庚切 箸精 因拷戚 焼艦檎 1鋼発
int checkName(const char* ap_string)
{
	char* p_dest = ap_string;

	while (*p_dest != '\0')
	{
		if (isalpha(*p_dest) == 0 && *p_dest != ' ')
		{
			return 1;
		}
		p_dest++;
	}
	return 0;
}
// 慎嬢, 収切, 働庚 馬蟹 梢 赤嬢醤敗. 戚雌廃暗 級嬢神暗蟹, 蒸生檎 1鋼発
int checkPW(const char* ap_string)
{
	char* p_dest = ap_string;
	char SC[10] = { '!','@','#','$','%','^','&','*','(',')' };
	int PWcon[3] = { 0, };
	int i = 0;

	while (*p_dest != '\0')
	{
		if (isalpha(*p_dest) != 0)
		{
			PWcon[0] = 1;
		}
		else if (isdigit(*p_dest) != 0)
		{
			PWcon[1] = 1;
		}
		else
		{
			for (i = 0; i < 10; i++)
			{
				if (SC[i] == *p_dest)
				{
					PWcon[2] = 1;
					break;
				}
			}
		}
		p_dest++;
	}
	if (PWcon[0] && PWcon[1] && PWcon[2])
	{
		return 0;
	}
	return 1;
}
//掻娃 因拷 端滴馬奄
int checkSpace(const char* ap_string)
{
	char* p_dest = ap_string;

	while (*p_dest != '\0')
	{
		if (*p_dest++ == ' ')
		{
			return 1;
		}
	}
	return 0;	//固 原走厳拭 null 煽舌
}
//掻娃 因拷 走酔奄
void EraseSpace(char* ap_string)
{
	char* p_dest = ap_string;

	while (*ap_string != 0)
	{
		if (*ap_string != ' ')
		{
			*p_dest = *ap_string;
			p_dest++;
		}

		ap_string++;
	}
	*p_dest = 0;	//固 原走厳拭 null 煽舌
}
// 庚切伸 酔著 因拷庚切 肢薦 敗呪
char* rtrim_malloc(char* des, const char* src)
{
	assert(src != NULL && "src is NULL");
	des = (char*)malloc(sizeof(char) * strlen(src));//fgets 馬檎 鯵楳庚切亀 旭戚級嬢逢艦陥.
	assert(des != NULL && "temp memory allocation is failed.");
	char* tdes = des;
	char* tsrc = src;

	while (*tsrc != '\0')
	{
		*tdes++ = *tsrc++;
	}

	while (*tsrc == ' ')
	{
		tsrc--;
		tdes--;
	}
	*++tdes = '\0';

	return des;
}
// 庚切伸 疎著 因拷庚切 肢薦 敗呪
char* ltrim_malloc(char* des, const char* src)
{
	assert(src != NULL && "src is NULL");
	des = (char*)malloc(sizeof(char) * strlen(src));//fgets 馬檎 鯵楳庚切亀 旭戚級嬢逢艦陥.
	assert(des != NULL && "temp memory allocation is failed.");
	char* end;
	int startFlags = 0;
	char* tdes = des;
	char* tsrc = src;

	while (*tsrc != '\0')
	{
		if (*tsrc == ' ' && startFlags == 0)
		{
			tsrc++;
		}
		else
		{
			startFlags = 1;
			*tdes++ = *tsrc++;
		}
	}
	*tdes = '\0';

	return des;
}
// 庚切伸 蒋及 因拷 乞砧 肢薦 敗呪
char* trim_malloc(char* des, const char* src)
{
	assert(src != NULL && "src is NULL");
	des = (char*)malloc(sizeof(char) * strlen(src));//fgets 馬檎 鯵楳庚切亀 旭戚級嬢逢艦陥.
	assert(des != NULL && "temp memory allocation is failed.");
	char* end;
	int startFlags = 0;
	char* tdes = des;
	char* tsrc = src;

	while (*tsrc != '\0')
	{
		if (*tsrc == ' ' && startFlags == 0)
		{
			tsrc++;
		}
		else
		{
			startFlags = 1;
			*tdes++ = *tsrc++;
		}
	}
	while (*tsrc == ' ')
	{
		tsrc--;
		tdes--;
	}
	*--tdes = '\0';


	return des;
}
// 厳幻窮 敗呪
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
			assert(wtemps[i] != NULL && "wtemps[i] allocation failed");
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
// 厳幻窮 敗呪2
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
		assert(wtemps[i] != NULL && "wtemps[i] memory allocation failed");
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
		for (int c = 0; c < 4; c++)
		{
			free(wATInfo[c]);
			wATInfo[c] = NULL;
		}
		free(wATInfo);
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
// 厳幻窮 敗呪3
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
// 厳幻窮 敗呪4
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
		switch (g_allAccountsListAndName[0][f][2]) // 展脊端滴
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
	return 0;
NEEDTOCORRECTFILE:
	return 1;
}
// 厳幻窮 敗呪5
int checkAcc(FILE* f_target) // 石生形壱...戚背馬形壱 獣亀馬走原室推 せせせせせせ
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
			while ((*piter) != '|') // 域疎戚硯
			{
				if (isalnum(*piter) == 0)
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					fwrite("<-- correct typos\n", sizeof(char), 19, f_target);
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
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
// 厳幻窮 敗呪6
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
				if (isdigit(*piter) == 0 && (*piter) != '.')//接衝
				{
					while (*(++pFileOffset) != '\n')
					{
						CurrentFileOffset++;
					}
					fseek(f_target, CurrentFileOffset + 1, SEEK_SET);
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
// 厳幻窮 敗呪7
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
					int numOfWords = fread(g_filebuff, sizeof(char), FILE_BUFF, f_target);
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
// 焼送 照幻糾
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
// 焼戚巨 掻差鞠澗走 溌昔杯艦陥.
int checkDupID(const char* ID)
{
	assert(ID != NULL && "ID is NULL");
	long CurrentFileOffset = 0;

	char* IDs = NULL;
	int i = 0;
	char* pbuf = NULL;
	char* pID = NULL;

	while (1)
	{
		fseek(f_MemberFile, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_MemberFile);
		if (feof(f_MemberFile))
		{
			break;
		}
		IDs = (char*)malloc(sizeof(char) * 17);
		assert(IDs != NULL && "IDs memory allocation is error");
		pbuf = g_buffer;
		pID = IDs;

		while (*pbuf++ != '|');
		while (*pbuf != '|')
		{
			*pID++ = *pbuf++;
		}
		*pID = '\0';

		if (strcmp(ID, IDs) == 0)
		{
			free(IDs);
			IDs = NULL;
			return 1;
		}

		CurrentFileOffset = ftell(f_MemberFile);
	}
	if (IDs != NULL)
	{
		IDs = NULL;
		free(IDs);
	}
	return 0;
}
// 焼戚巨拭 背雁馬澗 搾腔腰硲亜 限澗走 溌昔杯艦陥.
int checkDupPW(const char* ID, const char* PW)
{
	assert(PW != NULL && "PW is NULL");
	long CurrentFileOffset = 0;

	char* PWs = NULL;
	int i = 0;
	char* pbuf = NULL;
	char* pPW = NULL;

	CurrentFileOffset = setBankByID(ID);
	fseek(f_MemberFile, CurrentFileOffset, SEEK_SET);
	fgets(g_buffer, BUFF_SIZE, f_MemberFile);
	if (feof(f_MemberFile))
	{
		return 0;
	}
	PWs = (char*)malloc(sizeof(char) * 33);
	assert(PWs != NULL && "PWs memory allocation is error");
	pbuf = g_buffer;
	pPW = PWs;

	while (*pbuf++ != '|');
	while (*pbuf++ != '|');
	while (*pbuf != '|')
	{
		*pPW++ = *pbuf++;
	}
	*pPW = '\0';

	if (strcmp(PW, PWs) == 0)
	{
		free(PWs);
		PWs = NULL;
		return 1;
	}

	if (PWs != NULL)
	{
		free(PWs);
		PWs = NULL;
	}
	return 0;
}
// 焼戚巨稽 越稽忽 告滴 坪球 室特馬壱 益 匝 神覗実 鋼発 杯艦陥....蒸生檎 0鋼発
int setBankByID(const char* ID) 
{
	assert(ID != NULL && "ID is NULL");
	long CurrentFileOffset = 0;

	char* IDs = NULL;
	int IDNums = 0;
	int i = 0;
	char* pbuf = NULL;
	char* pID = NULL;
	int bankCode = 0;

	while (1)
	{
		fseek(f_MemberFile, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_MemberFile);
		if (feof(f_MemberFile))
		{
			break;
		}
		IDs = (char*)malloc(sizeof(char) * 17);
		assert(IDs != NULL && "IDs memory allocation is error");
		pbuf = g_buffer;
		pID = IDs;

		while (*pbuf++ != '|');
		while (*pbuf != '|')
		{
			*pID++ = *pbuf++;
		}
		*pID = '\0';

		if (strcmp(ID, IDs) == 0)
		{
			while (*pbuf++ != '|');
			while (*pbuf++ != '|');
			bankCode = atoi(pbuf);
			assert((isdigit(bankCode) == 0 || bankCode == 0) && "get BankCode is failed");

			IDs = NULL;
			free(IDs);

			g_userBank = bankCode;
			return CurrentFileOffset;
		}
		CurrentFileOffset = ftell(f_MemberFile);
	}
	if (IDs != NULL)
	{
		IDs = NULL;
		free(IDs);
	}
	return 0;
}
// 域疎軒什闘 閲嬢紳 獄遁稽 紫遂切 社政 域疎戚硯 掻差昔走 溌昔 杯艦陥. 掻差戚檎 1鋼発 焼艦檎 0鋼発
int checkDupAN(const char* input)
{
	assert(input != NULL && "ID is NULL");

	long CurrentFileOffset = 0;
	int bDulpicate = 0;

	int ANlen = 0;
	char* pbuf = NULL;
	char* pbuftemp = NULL;

	for (int i = 0; i < g_allALANNums; i++)
	{
		for (int j = 0; j < g_userALNums; j++)
		{
			if (strcmp(g_allAccountsListAndName[0][i], g_userAccountsList[j]) == 0)
			{
				if (strcmp(g_allAccountsListAndName[1][i], input) == 0)
				{
					return 1;
				}
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
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < g_userALNums; h++)
			{
				free(g_userAccountsList[0][h]);
				g_userAccountsList[k][h] = NULL;
			}
			free(g_userAccountsList[k]);
			g_userAccountsList[k] = NULL;
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
	int tempnamelen = 0;
	int AccountNums = 0;
	char* piter = NULL;;
	char* pitertemp = NULL;

	while (1)// 域疎 鯵呪歯奄
	{
		fseek(f_AccountList, CurrentFileOffset, SEEK_SET);
		fgets(g_buffer, BUFF_SIZE, f_AccountList);
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
	printf("%d", g_allALANNums);

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
		assert(g_allAccountsListAndName[1][k] != NULL && "g_allAcountsListAndName allocation failed");

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
		printf("%s | ", g_allAccountsListAndName[0][i]);

		while (*piter++ != '|');
		pitertemp = piter;
		while (*piter++ != '|')
		{
			tempnamelen++;
		}
		g_allAccountsListAndName[1][i] = (char*)malloc(sizeof(char) * (tempnamelen+1));
		assert(g_allAccountsListAndName[1][i] != NULL && "g_allAcountsListAndName allocation failed");

		strncpy(g_allAccountsListAndName[1][i], pitertemp, tempnamelen);
		g_allAccountsListAndName[1][i][tempnamelen] = '\0';
		//printf("%s\n", g_allAccountsListAndName[1][i]);

		CurrentFileOffset = ftell(f_AccountList);
		i++;
	}
	return g_allALANNums;
	
}