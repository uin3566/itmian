#include "stdafx.h"

#define DISH_COUNT 28

std::stack<int> stkLeft;
std::stack<int> stkMid;
std::stack<int> stkRight;

void InitStack()
{
	for (int i = DISH_COUNT; i > 0; i--)
	{
		stkLeft.push(i);
	}
}

void MoveTopTo(std::stack<int>& stkSrc, std::stack<int>& stkDes)
{
	if (stkSrc.size() == 0)
	{
		goto Exit0;
	}
	int nTop = stkSrc.top();
	stkDes.push(nTop);
	stkSrc.pop();

Exit0:
	return;
}

void HannoTower(int nDiskCount,std::stack<int>& stkSrc, std::stack<int>& stkDes, std::stack<int>& stkBuf)
{
	if (nDiskCount == 0 || stkSrc.size() == 0)
	{
		return;
	}
	if (nDiskCount > 0)
	{
		HannoTower(nDiskCount - 1, stkSrc, stkBuf, stkDes);
		MoveTopTo(stkSrc, stkDes);
		HannoTower(nDiskCount - 1, stkBuf, stkDes, stkSrc);
	}
}

// void main()
// {
// 	InitStack();
// 	HannoTower(DISH_COUNT, stkLeft, stkRight, stkMid);
// }