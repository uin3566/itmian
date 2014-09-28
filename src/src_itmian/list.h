#pragma once

struct ListNode
{
	int nValue;
	ListNode* pNext;

	ListNode()
	{
		nValue = 0;
		pNext = NULL;
	}
};

ListNode* CreateList(int arrayListValue[], int nListLength);
ListNode* CreateLoopList(int arrayListVaLue[], int nListLength, int nLoopPos);//创建一个有环的链表
void DestroyList(ListNode** pHead);

ListNode* GetNode(ListNode* pHead, int nNo);
void ReverseList(ListNode* pHead);
int GetListLength(ListNode* pHead);
void InsertNodeAfterHead(ListNode* pHead, ListNode** pInsertNode);
ListNode* IsLoopList(ListNode* pHead);//返回快慢指针相遇的node或null
ListNode* GetMidNode(ListNode* pHead, BOOL& bIsLengthOdd);//获取链表中间结点