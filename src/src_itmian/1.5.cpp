#include "stdafx.h"

int GetCompressedLength(const char* pStr)
{
	int nRet = -1;
	int nCharCount = 0;
	if (pStr == NULL)
	{
		goto Exit0;
	}
	while (*pStr)
	{
		if (*pStr != *(pStr + 1))
		{
			nCharCount++;
		}
		pStr++;
	}
	nRet = nCharCount * 2;

Exit0:
	return nRet;
}

void CompressStr(const char* pStr, char* pCompressedStr)
{
	int nCharCount = 0;
	int nStrLength = 0;
	int nCompressedLength = 0;
	int nCompressedStrOffset = 0;

	if (pStr == NULL || pCompressedStr == NULL)
	{
		goto Exit0;
	}
	nStrLength = strlen(pStr);
	if (nStrLength == 0)
	{
		goto Exit0;
	}

	nCompressedLength = GetCompressedLength(pStr);
	if (nCompressedLength >= nStrLength)
	{
		strcpy_s(pCompressedStr, (nStrLength + 1) * sizeof(char), pStr);
		goto Exit0;
	}

	while (*pStr)
	{
		nCharCount = 1;
		while(*pStr == *(pStr + 1))
		{
			nCharCount++;
			pStr++;
		}
		pStr++;
		pCompressedStr[nCompressedStrOffset] = *(pStr - 1);
		pCompressedStr[nCompressedStrOffset + 1] = '0' + nCharCount;
		nCompressedStrOffset += 2;
	}
	pCompressedStr[nCompressedStrOffset] = '\0';

Exit0:
	return;
}

// void main()
// {
// 	int nCompressedLength = 0;
// 	char arrayStr[256] = "aa";
// 	char arrayCompressedStr[256];
// 	nCompressedLength = GetCompressedLength(arrayStr);
// 	CompressStr(arrayStr, arrayCompressedStr);
// }