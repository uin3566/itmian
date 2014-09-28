#include "stdafx.h"

void ReplaceSpace(char str[], int nLength)//将空格全部替换成%20
{
	int nSpaceCount = 0;
	int nNewLength = 0;
	if (str == NULL)
	{
		goto Exit0;
	}
	for (int i = 0; i < nLength; i++)
	{
		if (str[i] == ' ')
		{
			nSpaceCount++;
		}
	}
	nNewLength = nLength + nSpaceCount * 2;
	for (int i = nLength; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[nNewLength] = str[i];
			nNewLength--;
		}
		else
		{
			str[nNewLength] = '0';
			str[nNewLength - 1] = '2';
			str[nNewLength - 2] = '%';
			nNewLength = nNewLength - 3;
		}
	}

Exit0:
	return;
}

// void main()
// {
// 	int nStrLength = 0;
// 	char arrayStr[256] = "nice to meet you";
// 	nStrLength = strlen(arrayStr);
// 	ReplaceSpace(arrayStr, nStrLength);
// }