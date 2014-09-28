#include "stdafx.h"
#include "list.h"

ListNode* CreateList(int arrayListValue[], int nListLength)
{
	ListNode* pHead = NULL;
	ListNode* pPre = NULL;
	ListNode* pNode = NULL;

	if (arrayListValue == NULL || nListLength <= 0)
	{
		goto Exit0;
	}

	pHead = new ListNode;
	pPre = pHead;
	for (int i = 0; i < nListLength; i++)
	{
		pNode = NULL;
		pNode = new ListNode;
		pNode->nValue = arrayListValue[i];
		pPre->pNext = pNode;
		pPre = pNode;
	}

Exit0:
	return pHead;
}

void DestroyList(ListNode** pHead)
{
	ListNode* pNode = NULL;
	if (pHead == NULL)
	{
		goto Exit0;
	}
	pNode = (*pHead);

	while((*pHead)->pNext)
	{
		pNode = (*pHead)->pNext;
		(*pHead)->pNext = pNode->pNext;
		delete pNode;
		pNode = NULL;
	}
	delete *pHead;
	(*pHead) = NULL;

Exit0:
	return;
}

ListNode* GetNode(ListNode* pHead, int nNo)
{
	ListNode* pRetNode = NULL;

	if (pHead == NULL || nNo <= 0)
	{
		goto Exit0;
	}

	pRetNode = pHead;
	for (int i = 0; i < nNo; i++)
	{
		pRetNode = pRetNode->pNext;
		if (pRetNode == NULL)
		{
			goto Exit0;
		}
	}

Exit0:
	return pRetNode;
}

int GetListLength(ListNode* pHead)
{
	int nRet = 0;
	ListNode* pNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}
	pNode = pHead->pNext;
	while(pNode)
	{
		pNode = pNode->pNext;
		nRet++;
	}

Exit0:
	return nRet;
}

void InsertNodeAfterHead(ListNode* pHead, ListNode** pInsertNode)
{
	if (pHead == NULL || pInsertNode == NULL)
	{
		goto Exit0;
	}
	(*pInsertNode)->pNext = pHead->pNext;
	pHead->pNext = (*pInsertNode);

Exit0:
	return;
}

void ReverseList(ListNode* pHead)
{
	ListNode* pInsertNode = NULL;
	ListNode* pLaterInsertNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pInsertNode = pHead->pNext;
	pHead->pNext = NULL;
	while(pInsertNode)
	{
		pLaterInsertNode = pInsertNode->pNext;
		InsertNodeAfterHead(pHead, &pInsertNode);
		pInsertNode = pLaterInsertNode;
	}

Exit0:
	return;
}

ListNode* CreateLoopList(int arrayListVaLue[], int nListLength, int nLoopPos)//创建一个有环的链表
{
	ListNode* pHead = NULL;
	ListNode* pLoopStartNode = NULL;
	ListNode* pTail = NULL;

	if (arrayListVaLue == NULL || nListLength <= 0 || nLoopPos <= 0 || nLoopPos >nListLength)
	{
		goto Exit0;
	}

	pHead = CreateList(arrayListVaLue, nListLength);
	pTail = GetNode(pHead, nListLength);
	pLoopStartNode = GetNode(pHead, nLoopPos);
	pTail->pNext = pLoopStartNode;

Exit0:
	return pHead;
}

ListNode* IsLoopList(ListNode* pHead)
{
	ListNode* pCollisionNode = NULL;
	ListNode* pFastNode = NULL;
	ListNode* pSlowerNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pFastNode = pHead->pNext;
	pSlowerNode = pHead->pNext;
	while(pFastNode && pFastNode->pNext)
	{
		pFastNode = pFastNode->pNext->pNext;
		pSlowerNode = pSlowerNode->pNext;
		if (pFastNode == pSlowerNode)
		{
			pCollisionNode = pFastNode;
			goto Exit0;
		}
	}

Exit0:
	return pCollisionNode;
}

ListNode* GetMidNode(ListNode* pHead, BOOL& bIsLengthOdd)
{
	ListNode* pMidNode = NULL;
	ListNode* pFastNode = NULL;
	ListNode* pSlowerNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pFastNode = pHead->pNext;
	pSlowerNode = pHead->pNext;
	while(pFastNode && pFastNode->pNext)
	{
		pFastNode = pFastNode->pNext->pNext;
		pSlowerNode = pSlowerNode->pNext;
	}
	if (pFastNode != NULL)
	{
		bIsLengthOdd = TRUE;
	}
	pMidNode = pSlowerNode;

Exit0:
	return pMidNode;
}