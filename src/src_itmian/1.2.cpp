#include "stdafx.h"

void Reverse(char* pStr)
{
	char chTmp = '0';
	int nStrLength = 0;
	int nLoop = 0;

	nStrLength = strlen(pStr);
	if (NULL == pStr || nStrLength == 0)
	{
		goto Exit0;
	}

	nLoop = nStrLength / 2;
	for (int i = 0; i < nLoop; i++)
	{
		if (pStr[i] == pStr[nStrLength - i - 1])
		{
			continue;
		}
		else
		{
			chTmp = pStr[i];
			pStr[i] = pStr[nStrLength - i - 1];
			pStr[nStrLength - i - 1] = chTmp;
		}
	}

Exit0:
	return;
}

// void main()
// {
// 	char pStr[] = "abcdea";
// 	Reverse(pStr);
// }