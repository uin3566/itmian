#include "stdafx.h"

ListNode* GetLoopStartNode(ListNode* pHead)//ʹ��set��ʱ�临�ӶȽϸ�
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

ListNode* GetLoopStartNode2(ListNode* pHead)//��ʹ�ö���Ĵ洢�ռ䣬ʱ�临�ӶȽϵ�
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