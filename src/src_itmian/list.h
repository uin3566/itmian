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
ListNode* CreateLoopList(int arrayListVaLue[], int nListLength, int nLoopPos);//����һ���л�������
void DestroyList(ListNode** pHead);

ListNode* GetNode(ListNode* pHead, int nNo);
void ReverseList(ListNode* pHead);
int GetListLength(ListNode* pHead);
void InsertNodeAfterHead(ListNode* pHead, ListNode** pInsertNode);
ListNode* IsLoopList(ListNode* pHead);//���ؿ���ָ��������node��null
ListNode* GetMidNode(ListNode* pHead, BOOL& bIsLengthOdd);//��ȡ�����м���