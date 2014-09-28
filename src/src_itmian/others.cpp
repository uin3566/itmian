#include "stdafx.h"
using namespace std;

int BinarySearch(int a[], int nLength, int nValue)
{
	if (a == NULL || nLength <= 0)
	{
		return -1;
	}

	int nStart = 0;
	int nEnd = nLength - 1;
	int nMid = 0;

	while(nStart <= nEnd)
	{
		nMid = (nStart + nEnd) / 2;
		if (a[nMid] > nValue)
		{
			nEnd = nMid - 1;
		}
		else if (a[nMid] < nValue)
		{
			nStart = nMid + 1;
		}
		else
		{
			return nMid;
		}
	}

	return -1;
}

void QuikSort(int a[], int nLow, int nHigh)
{
	if (a == NULL || nLow < 0 || nHigh <= nLow)
	{
		return;
	}

	int nFirst = nLow;
	int nLast = nHigh;
	int nKey = a[nLow];
	while (nFirst < nLast)
	{
		while (nFirst < nLast && a[nLast] >= nKey)
		{
			nLast--;
		}
		a[nFirst] = a[nLast];
		while (nFirst < nLast && a[nFirst] < nKey)
		{
			nFirst++;
		}
		a[nLast] = a[nFirst];
	}
	a[nFirst] = nKey;
	QuikSort(a, nLow, nFirst - 1);
	QuikSort(a, nLast + 1, nHigh);
}

void BubbleSort(int a[], int nLength)
{
	if (a == NULL || nLength <= 0)
	{
		return;
	}

	int nTmp = 0;
	for (int j = nLength; j > 0; j--)
	{
		for (int i = 0; i < j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				nTmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = nTmp;
			}
		}
	}
}

BOOL IsLittleEndian()
{
	union UNCheck
	{
		int nVal;
		char chVal;
	};
	UNCheck unCheck;
	unCheck.nVal = 1;
	if (unCheck.chVal == 1)
	{
		return TRUE;
	}
	return FALSE;
}

int Add(int nLhs, int nRhs)
{
	int nAdd = 0;
	int nCarry = 0;
	do 
	{
		nAdd = nLhs ^ nRhs;
		nCarry = (nLhs & nRhs) << 1;
		nLhs = nAdd;
		nRhs = nCarry;
	} while (nCarry);
	return nAdd;
}

#define mul(a) (a)*(a)

int main(void)
{
	int a = 5, b, c;
	b = mul(a++);
	c = mul(++a);

	if (!a && c++)
		b++;
	else
		c++;

	printf("%d %d", b, c);

	getchar();
	return 0;
}