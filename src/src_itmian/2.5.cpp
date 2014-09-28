#include "stdafx.h"

void SetCarry(int nAddedValue, int& nCarry)
{
	if (nAddedValue >= 10)
	{
		nCarry = 1;
	}
	else
	{
		nCarry = 0;
	}
}

void AddNewNodeToAddedList(ListNode** pCurAddedNode, ListNode** pPreAddedNode, int nNodeValue)
{
	(*pCurAddedNode) = new ListNode;
	(*pCurAddedNode)->nValue = nNodeValue;
	(*pPreAddedNode)->pNext = (*pCurAddedNode);
	(*pPreAddedNode) = (*pCurAddedNode);
}

void AddExtraNodeToAddedList(ListNode** pCurAddedNode, ListNode** pPreAddedNode)
{
	(*pCurAddedNode) = new ListNode;
	(*pCurAddedNode)->nValue = 1;
	(*pPreAddedNode)->pNext = (*pCurAddedNode);
}

ListNode* AddList(ListNode* pHeadLhs, ListNode* pHeadRhs)//链表每个节点是一个数位，链表前面为低位，后面为高位。
{
	ListNode* pAddedListHead = NULL;
	ListNode* pPreAddedNode = NULL;
	ListNode* pCurAddedNode = NULL;
	ListNode* pCurNodeLhs = NULL;
	ListNode* pCurNodeRhs = NULL;
	int nCarry = 0;
	int nNodeValue = 0;
	int nAddedValue = 0;

	if (pHeadLhs == NULL || pHeadRhs == NULL)
	{
		goto Exit0;
	}
	
	pAddedListHead = new ListNode;
	pPreAddedNode = pAddedListHead;
	pCurNodeLhs = pHeadLhs->pNext;
	pCurNodeRhs = pHeadRhs->pNext;
	while(pCurNodeLhs || pCurNodeRhs)
	{
		if (pCurNodeLhs && pCurNodeRhs)
		{
			nAddedValue = pCurNodeLhs->nValue + pCurNodeRhs->nValue + nCarry;
			nNodeValue = nAddedValue % 10;
			SetCarry(nAddedValue, nCarry);
			AddNewNodeToAddedList(&pCurAddedNode, &pPreAddedNode, nNodeValue);
			if (pCurNodeLhs->pNext == NULL && pCurNodeRhs->pNext == NULL && nCarry == 1)
			{
				AddExtraNodeToAddedList(&pCurAddedNode, &pPreAddedNode);
			}
		}
		else if (pCurNodeLhs != NULL && pCurNodeRhs == NULL)
		{
			nAddedValue = pCurNodeLhs->nValue + nCarry;
			nNodeValue = nAddedValue % 10;
			SetCarry(nAddedValue, nCarry);
			AddNewNodeToAddedList(&pCurAddedNode, &pPreAddedNode, nNodeValue);
			if (pCurNodeLhs->pNext == NULL && nCarry == 1)
			{
				AddExtraNodeToAddedList(&pCurAddedNode, &pPreAddedNode);
			}
		}
		else if (pCurNodeLhs == NULL && pCurNodeRhs != NULL)
		{
			nAddedValue = pCurNodeRhs->nValue + nCarry;
			nNodeValue = nAddedValue % 10;
			SetCarry(nAddedValue, nCarry);
			AddNewNodeToAddedList(&pCurAddedNode, &pPreAddedNode, nNodeValue);
			if (pCurNodeRhs->pNext == NULL && nCarry == 1)
			{
				AddExtraNodeToAddedList(&pCurAddedNode, &pPreAddedNode);
			}
		}
		if (pCurNodeLhs)
		{
			pCurNodeLhs = pCurNodeLhs->pNext;
		}
		if (pCurNodeRhs)
		{
			pCurNodeRhs = pCurNodeRhs->pNext;
		}		
	}

Exit0:
	return pAddedListHead;
}

// void main()
// {
// 	int arrayListValuesLhs[] = {1, 2};
// 	int arrayListValuesRhs[] = {1, 2, 3, 6};
// 	ListNode* pHeadLhs = NULL;
// 	ListNode* pHeadRhs = NULL;
// 	ListNode* pAddedListHead = NULL;
// 	pHeadLhs = CreateList(arrayListValuesLhs, 2);
// 	pHeadRhs = CreateList(arrayListValuesRhs, 4);
// 	pAddedListHead = AddList(pHeadLhs, pHeadRhs);
// 	ReverseList(pHeadRhs);
// 	DestroyList(&pHeadLhs);
// 	DestroyList(&pHeadRhs);
// 	DestroyList(&pAddedListHead);
// }