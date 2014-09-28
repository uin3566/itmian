#include "stdafx.h"

BOOL IsAllCharNoSame(const char* pStr)
{
	BOOL bRet = FALSE;
	static const int MAX_ASCII_CHAR_COUNT = 256;
	int nStrLength = 0;
	int nStrOffset = 0;
	int nCharSetSize = 0;
	const char* pStrTmp;
	std::set<char> CharSet;

	if (pStr == NULL)
	{
		goto Exit0;
	}

	nStrLength = strlen(pStr);
	if (nStrLength == 0 || nStrLength > MAX_ASCII_CHAR_COUNT)
	{
		goto Exit0;
	}
	pStrTmp = pStr;

	while(pStrTmp[nStrOffset])
	{
		CharSet.insert(pStrTmp[nStrOffset]);
		nStrOffset++;
		nCharSetSize = CharSet.size();
		if (nStrOffset != nCharSetSize)
		{
			goto Exit0;
		}
	}
	bRet = TRUE;

Exit0:
	return bRet;
}

//void main()
// {
// 	BOOL bResult = FALSE;
// 	char* pStr = "abcdefghijklmnopqrstuvwxyz";
// 	bResult = IsAllCharNoSame(pStr);
// }