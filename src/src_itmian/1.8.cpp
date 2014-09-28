#include "stdafx.h"

BOOL IsSubString(const char* pStr, const char* pFindStr)
{
	BOOL bRet = FALSE;
	int nStrLength = 0;
	int nFindStrLength = 0;
	int nLoop = 0;
	int nEqualCount = 0;

	if (pStr == NULL || pFindStr == NULL)
	{
		goto Exit0;
	}
	nStrLength = strlen(pStr);
	nFindStrLength = strlen(pFindStr);
	if (nStrLength <= 0 || nFindStrLength <= 0 || nStrLength < nFindStrLength)
	{
		goto Exit0;
	}
	
	nLoop = nStrLength - nFindStrLength + 1;
	for (int k = 0; k < nLoop; k++)
	{
		nEqualCount = 0;
		for (int i = 0; i < nFindStrLength; i++)
		{
			if (pStr[k + i] == pFindStr[i])
			{
				nEqualCount++;
			}
			if (pStr[k + i] != pFindStr[i])
			{
				break;
			}
		}
		if (nEqualCount == nFindStrLength)
		{
			bRet = TRUE;
			break;
		}
	}

Exit0:
	return bRet;
}

BOOL IsRotateStr(const char* pStr1, const char* pStr2)
{
	BOOL bRet = FALSE;
	int nStr1Length = 0;
	int nStr2Length = 0;
	char* pStr1Str1 = NULL;

	if (pStr1 == NULL || pStr2 == NULL)
	{
		goto Exit0;
	}

	nStr1Length = strlen(pStr1);
	nStr2Length = strlen(pStr2);
	if (nStr1Length != nStr2Length || nStr1Length <= 0 || nStr2Length <= 0)
	{
		goto Exit0;
	}
	pStr1Str1 = new char[nStr1Length * 2 + 1];
	strcpy_s(pStr1Str1, nStr1Length * 2 * sizeof(char) + 1, pStr1);
	strcat_s(pStr1Str1, nStr1Length * 2 * sizeof(char) + 1, pStr1);

	bRet = IsSubString(pStr1Str1, pStr2);

Exit0:
	if (pStr1Str1)
	{
		delete[] pStr1Str1;
		pStr1Str1 = NULL;
	}
	return bRet;
}

// void main()
// {
// 	char str[] = "waterbottle";
// 	char findstr[] = "bottlewater";
// 	BOOL bResult = FALSE;
// 	bResult = IsRotateStr(str, findstr);
// }