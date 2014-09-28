#include "stdafx.h"

BOOL DeleteListNode(ListNode* pDeleteNode)
{
	BOOL bRet = FALSE;

	if (pDeleteNode == NULL || pDeleteNode->pNext == NULL)
	{
		goto Exit0;
	}

	ListNode* pNextDeleteNode = pDeleteNode->pNext;
	pDeleteNode->nValue = pNextDeleteNode->nValue;
	pDeleteNode->pNext = pNextDeleteNode->pNext;
	delete pNextDeleteNode;
	pNextDeleteNode = NULL;

Exit0:
	return bRet;
}

// void main()
// {
// 	int arrayListValues[] = {1, 2, 3, 4, 5, 6};
// 	ListNode* pHead = NULL;
// 	ListNode* pDeleteNode = NULL;
// 	pHead = CreateList(arrayListValues, 6);
// 	pDeleteNode = GetNode(pHead, 6);
// 	DeleteListNode(pDeleteNode);
// 	DestroyList(&pHead);	
// }