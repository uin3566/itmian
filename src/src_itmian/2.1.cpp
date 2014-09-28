#include "stdafx.h"

void RemoveRepeatNodes(ListNode* pHead)//用set作辅助存储空间，时间复杂度O(n),空间复杂度O(n)
{
	ListNode* pPre = NULL;
	ListNode* pNode = NULL;
	int nValue = 0;
	int nValueSetSize = 0;
	int nListOffset = 0;
	std::set<int> setListValues;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pPre = pHead;
	while(pPre->pNext)
	{
		pNode = pPre->pNext;
		nValue = pNode->nValue;
		nListOffset++;
		setListValues.insert(nValue);
		nValueSetSize = setListValues.size();
		if (nListOffset == nValueSetSize)
		{
			pPre = pNode;
			continue;
		}
		else
		{
			pPre->pNext = pNode->pNext;
			nListOffset--;
			delete pNode;
		}
	}

Exit0:
	return;
}

void RemoveRepeatNodes2(ListNode* pHead)//不用额外的存储空间，时间复杂度为O(n2)
{
	ListNode* pFrontNode = NULL;
	ListNode* pPreLaterNode = NULL;
	ListNode* pLaterNode = NULL;
	ListNode* pRepeatNode = NULL;
	int nFrontValue = 0;
	int nLaterValue = 0;

	if (pHead == NULL)
	{
		goto Exit0;
	}
	
	pFrontNode = pHead->pNext;
	pLaterNode = pHead->pNext;
	while(pFrontNode->pNext)
	{
		nFrontValue = pFrontNode->nValue;
		pPreLaterNode = pFrontNode;
		pLaterNode = pFrontNode->pNext;
		while(pLaterNode->pNext)
		{
			nLaterValue = pLaterNode->nValue;
			if (nFrontValue == nLaterValue)
			{
				pRepeatNode = pLaterNode;
				pPreLaterNode->pNext = pLaterNode->pNext;
				pLaterNode = pLaterNode->pNext;
				delete pRepeatNode;
			}
			else
			{
				pPreLaterNode = pPreLaterNode->pNext;
				pLaterNode = pLaterNode->pNext;
			}
		}
		pFrontNode = pFrontNode->pNext;
	}

Exit0:
	return;
}

// void main()
// {
// 	int arrayListValues[] = {1, 2, 1, 2, 3, 4, 5, 6, 7, 8};
// 	ListNode* pHead = NULL;
// 	pHead = CreateList(arrayListValues, 6);
// 	RemoveRepeatNodes2(pHead);
// 	DestroyList(&pHead);
// }