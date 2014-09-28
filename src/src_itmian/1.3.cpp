#include "stdafx.h"

BOOL IsStrComposeWithSameChar(const char* pStrA, const char* pStrB)//确定一个字符串重新排列能否变成另外一个字符串
{
	BOOL bRet = FALSE;
	int arrayCharSet[256] = {0};
	int nStrALength = 0;
	int nStrBLength = 0;
	char chTmp = '0';
	int nTmp = 0;

	if (pStrA == NULL || pStrB == NULL)
	{
		goto Exit0;
	}
	nStrALength = strlen(pStrA);
	nStrBLength = strlen(pStrB);
	if (nStrALength != nStrBLength)
	{
		goto Exit0;
	}
	if (nStrALength == 0)
	{
		bRet = TRUE;
		goto Exit0;
	}
	for (int i = 0; i < nStrALength; i++)
	{
		chTmp = pStrA[i];
		nTmp = chTmp;
		arrayCharSet[nTmp]++;
	}
	for (int i = 0; i < nStrBLength; i++)
	{
		chTmp = pStrB[i];
		nTmp = chTmp;
		arrayCharSet[nTmp]--;
		if (arrayCharSet[nTmp] < 0)
		{
			goto Exit0;
		}
	}
	bRet = TRUE;

Exit0:
	return bRet;
}

// void main()
// {
// 	BOOL bResult = FALSE;
// 	char StrA[] = "abcde";
// 	char StrB[] = "edcaa";
// 	bResult = IsStrComposeWithSameChar(StrA, StrB);
// }