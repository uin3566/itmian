#include "stdafx.h"

ListNode* ReverseFindTheKNode(ListNode* pHead, int nK)
{
	ListNode* pRetNode = NULL;
	ListNode* pFastNode = NULL;
	ListNode* pSlowNode = NULL;
	if (pHead == NULL || nK <= 0)
	{
		goto Exit0;
	}

	pFastNode = pHead;
	pSlowNode = pHead;
	for (int i = 0; i < nK - 1; i++)
	{
		if (pFastNode->pNext == NULL)
		{
			goto Exit0;
		}
		pFastNode = pFastNode->pNext;
	}
	while(pFastNode->pNext)
	{
		pSlowNode = pSlowNode->pNext;
		pFastNode = pFastNode->pNext;
	}
	pRetNode = pSlowNode;

Exit0:
	return pRetNode;
}

// void main()
// {
// 	int arrayListValues[] = {1, 2, 3};
// 	ListNode* pHead = NULL;
// 	ListNode* pResult = NULL;
// 	pHead = CreateList(arrayListValues, 3);
// 	pResult = ReverseFindTheKNode(pHead, 5);
// 	DestroyList(&pHead);
// }