#include "stdafx.h"

void MoveDataFromStkToStk(std::stack<int>& stkS1, std::stack<int>& stkS2)
{
	int nTmp = 0;
	if (stkS1.size() == 0)
	{
		goto Exit0;
	}

	nTmp = stkS1.top();
	stkS2.push(nTmp);
	stkS1.pop();

Exit0:
	return;
}

void SortStackAsc(std::stack<int>& stkS1, std::stack<int>& stkS2)//将stkS1中的元素升序排列放入stkS2,最大元素位于栈顶。
{
	int nTmp = 0;

	if (stkS2.size() != 0 || stkS1.size() == 0)
	{
		goto Exit0;
	}
	
	MoveDataFromStkToStk(stkS1, stkS2);
	while(stkS1.size())
	{
		nTmp = stkS1.top();
		stkS1.pop();
		while(!stkS2.empty() && nTmp < stkS2.top())
		{
			MoveDataFromStkToStk(stkS2, stkS1);
		}
		stkS2.push(nTmp);
	}

Exit0:
	return;
}

// void main()
// {
// 	std::stack<int> stkS1;
// 	std::stack<int> stkS2;
// 	stkS1.push(50);
// 	stkS1.push(10);
// 	stkS1.push(90);
// 	stkS1.push(30);
// 	stkS1.push(70);
// 	stkS1.push(40);
// 	stkS1.push(80);
// 	stkS1.push(60);
// 	stkS1.push(20);
// 	SortStackAsc(stkS1, stkS2);
// }