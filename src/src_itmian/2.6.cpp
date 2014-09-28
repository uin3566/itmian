#include "stdafx.h"

ListNode* GetLoopStartNode(ListNode* pHead)//使用set，时间复杂度较高
{
	ListNode* pLoopStartNode = NULL;
	ListNode* pCurNode = NULL;
	std::set<ListNode*> setListNodes;
	int nOffset = 0;
	int nSetSize = 0;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pCurNode = pHead->pNext;
	while (pCurNode)
	{
		nOffset++;
		setListNodes.insert(pCurNode);
		nSetSize = setListNodes.size();
		if (nOffset != nSetSize)
		{
			pLoopStartNode = pCurNode;
			goto Exit0;
		}
		pCurNode = pCurNode->pNext;
	}

Exit0:
	return pLoopStartNode;
}

ListNode* GetLoopStartNode2(ListNode* pHead)//不使用额外的存储空间，时间复杂度较低
{
	ListNode* pLoopStartNode = NULL;
	ListNode* pFastNode = NULL;
	ListNode* pSlowerNode = NULL;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pFastNode = IsLoopList(pHead);
	if (pFastNode == NULL)
	{
		goto Exit0;
	}
	pSlowerNode = pHead->pNext;
	while(pFastNode != pSlowerNode)
	{
		pFastNode = pFastNode->pNext;
		pSlowerNode = pSlowerNode->pNext;
	}
	pLoopStartNode = pFastNode;

Exit0:
	return pLoopStartNode;
}

// void main()
// {	
// 	int arrayListValues[] = {1, 2, 3, 4, 5, 6};
// 	ListNode* pLoopHead = NULL;
// 	ListNode* pLoopStartNode = NULL;
// 	pLoopHead = CreateLoopList(arrayListValues, 6, 2);
// 	pLoopStartNode = GetLoopStartNode2(pLoopHead);
// }