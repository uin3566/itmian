#include "stdafx.h"

#define STACK_SIZE 10
#define STACK_COUNT 3

int arrayStack[STACK_SIZE * STACK_COUNT] = {0};
int arrayStackPointer[STACK_COUNT] = {-1, -1, -1};

int GetArrayIndex(int nStackNo)
{
	int nIndex = 0;

	if (nStackNo < 0 || nStackNo >= STACK_COUNT)
	{
		goto Exit0;
	}

	nIndex = nStackNo * STACK_SIZE + arrayStackPointer[nStackNo];

Exit0:
	return nIndex;
}

void push(int nStackNo, int nValue)
{
	int nIndex = 0;

	if (nStackNo < 0 || nStackNo >= STACK_COUNT)
	{
		goto Exit0;
	}

	if (arrayStackPointer[nStackNo] >= STACK_SIZE - 1)//Õ»Âú
	{
		goto Exit0;
	}

	arrayStackPointer[nStackNo]++;
	nIndex = GetArrayIndex(nStackNo);
	arrayStack[nIndex] = nValue;

Exit0:
	return;
}

void pop(int nStackNo)
{
	int nIndex = 0;

	if (nStackNo < 0 || nStackNo >= STACK_COUNT)
	{
		goto Exit0;
	}

	if (arrayStackPointer[nStackNo] == - 1)//Õ»Îª¿Õ
	{
		goto Exit0;
	}

	nIndex = GetArrayIndex(nStackNo);
	arrayStack[nIndex] = 0;
	arrayStackPointer[nStackNo]--;

Exit0:
	return;	
}

int top(int nStackNo)
{
	int nRet = 0;
	int nIndex = 0;

	if (nStackNo < 0 || nStackNo >= STACK_COUNT)
	{
		goto Exit0;
	}

	if (arrayStackPointer[nStackNo] == - 1)//Õ»Îª¿Õ
	{
		goto Exit0;
	}

	nIndex = GetArrayIndex(nStackNo);
	nRet = arrayStack[nIndex];

Exit0:
	return nRet;	
}

BOOL IsEmpty(int nStackNo)
{
	BOOL bRet = FALSE;

	if (nStackNo < 0 || nStackNo >= STACK_COUNT)
	{
		goto Exit0;
	}

	if (arrayStackPointer[nStackNo] == - 1)//Õ»Îª¿Õ
	{
		bRet = TRUE;
	}

Exit0:
	return bRet;	
}

// void main()
// {
// 	for (int i = 0; i < STACK_COUNT; i++)
// 	{
// 		for (int j = 0; j < STACK_SIZE; j++)
// 		{
// 			push(i, j + 1);
// 		}
// 	}
// 
// 	for (int i = 0; i < STACK_COUNT; i++)
// 	{
// 		for (int j = 0; j < STACK_SIZE; j++)
// 		{
// 			pop(i);
// 		}	
// 	}
// }