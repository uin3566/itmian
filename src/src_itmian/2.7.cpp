#include "stdafx.h"

BOOL IsPalindromeList(ListNode* pHead)
{
	BOOL bRet = FALSE;
	BOOL bIsLengthOdd = FALSE;
	ListNode* pMidNode = NULL;
	ListNode* pNode = NULL;
	ListNode* pCompareNode = NULL;
	std::stack<ListNode*> stackListNodes;

	if (pHead == NULL)
	{
		goto Exit0;
	}

	pNode = pHead->pNext;
	pMidNode = GetMidNode(pHead, bIsLengthOdd);
	if (pMidNode == NULL)
	{
		goto Exit0;
	}
	while(pNode != pMidNode)
	{
		stackListNodes.push(pNode);
		pNode = pNode->pNext;
	}
	if (bIsLengthOdd == TRUE)//长度为奇数
	{
		stackListNodes.push(pNode);
	}
	pCompareNode = pNode;
	while(pCompareNode)
	{
		pNode = stackListNodes.top();
		if (pNode->nValue != pCompareNode->nValue)
		{
			goto Exit0;
		}
		stackListNodes.pop();
		pCompareNode = pCompareNode->pNext;
	}
	bRet = TRUE;

Exit0:
	return bRet;
}

// void main()
// {
// 	int arrayNodes[] = {1, 2, 3, 4, 3, 2, 1};
// 	ListNode* pHead = NULL;
// 	ListNode* pMidNode = NULL;
// 	BOOL IsPalindrome = FALSE;
// 	pHead = CreateList(arrayNodes, 7);
// 	IsPalindrome = IsPalindromeList(pHead);
// }