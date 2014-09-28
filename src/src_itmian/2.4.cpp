#include "stdafx.h"

void SpliteList(ListNode* pHead, int nSpliteValue)
{
	ListNode* pNewHead = NULL;
	ListNode* pCurNewNode = NULL;
	ListNode* pPreCurNode = NULL;
	ListNode* pCurNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pNewHead = new ListNode;
	pPreCurNode = pHead;
	pCurNode = pHead->pNext;
	while(pCurNode)
	{
		if (pCurNode->nValue >= nSpliteValue)
		{
			pPreCurNode->pNext = pCurNode->pNext;
			pCurNode->pNext = pNewHead->pNext;
			pNewHead->pNext = pCurNode;
			pCurNode = pPreCurNode->pNext;
		}
		else
		{
			pPreCurNode = pPreCurNode->pNext;
			pCurNode = pCurNode->pNext;
		}
	}

	pPreCurNode->pNext = pNewHead->pNext;

Exit0:
	if (pNewHead)
	{
		delete pNewHead;
		pNewHead = NULL;
	}
	return;
}

// void main()
// {
// 	int arrayListValues[] = {4, 1, 3, 5, 12, 3};
// 	ListNode* pHead = NULL;
// 	pHead = CreateList(arrayListValues, 6);
// 	SpliteList(pHead, 4);
// 	DestroyList(&pHead);
// }