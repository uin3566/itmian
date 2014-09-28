#pragma once

template<typename T>
class CSetOfStacks
{
private:
	typedef std::stack<T> STACK;
	typedef std::vector<STACK*> STACKVECTOR;
	static const int STACK_SIZE = 5;

public:
	CSetOfStacks()
	{
		m_nDataCount = 0;
		m_nSubStackCount = 0;
	}
	
	~CSetOfStacks(){}

	void PushStack(T tValue)
	{
		if (m_nDataCount % STACK_SIZE == 0)
		{
			STACK* pStack = new STACK;
			m_vecStacks.push_back(pStack);
			m_nSubStackCount++;
		}

		STACK* pStack = m_vecStacks[m_nSubStackCount - 1];
		pStack->push(tValue);
		m_nDataCount++;
	}

	void PopStack()
	{
		if (m_nDataCount == 0)
		{
			goto Exit0;
		}
		STACK* pStack = m_vecStacks[m_nSubStackCount - 1];
		pStack->pop();
		m_nDataCount--;
		if (pStack->empty())
		{
			delete pStack;
			m_vecStacks.pop_back();
			m_nSubStackCount--;
		}

	Exit0:
		return;
	}

	void PopAt(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSubStackCount)
		{
			goto Exit0;
		}

		if (nIndex == m_nSubStackCount - 1)
		{
			PopStack();
			m_nDataCount--;
		}
		else
		{
			_PopAndRefillStacks(nIndex);
		}

	Exit0:
		return;
	}

	int GetDataCount()
	{
		return m_nDataCount;
	}

	int GetSubStackCount()
	{
		return m_nSubStackCount;
	}

private:
	void _PopAndRefillStacks(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSubStackCount - 1)
		{
			goto Exit0;
		}

		STACK* pStack = NULL;
		STACK* pStackRight = NULL;
		int nStackIndex = 0;

		nStackIndex = nIndex;
		pStack = m_vecStacks[nStackIndex];
		pStackRight = m_vecStacks[nStackIndex + 1];
		pStack->pop();
		m_nDataCount--;

		while(nStackIndex < m_nSubStackCount - 2)
		{
			_LeftShift(pStack, pStackRight);
			nStackIndex++;
			pStack = m_vecStacks[nStackIndex];
			pStackRight = m_vecStacks[nStackIndex + 1];
		}

		_LeftShift(pStack, pStackRight);

		if (pStackRight->size() == 0)
		{
			delete pStackRight;
			m_vecStacks.pop_back();
			m_nSubStackCount--;
		}

	Exit0:
		return;
	}

	void _LeftShift(STACK* pStackLeft, STACK* pStackRight)//把右边栈的底部元素取出放入左边栈顶
	{
		if (pStackLeft == NULL || pStackRight == NULL)
		{
			goto Exit0;
		}

		while(pStackRight->size() > 1)
		{
			T tValue = pStackRight->top();
			m_stkTmp.push(tValue);
			pStackRight->pop();
		}

		T tValue = pStackRight->top();
		pStackLeft->push(tValue);
		pStackRight->pop();

		while(m_stkTmp.size())
		{
			T tValue = m_stkTmp.top();
			pStackRight->push(tValue);
			m_stkTmp.pop();
		}
			
	Exit0:
		return;
	}

private:
	STACK m_stkTmp;
	STACKVECTOR m_vecStacks;
	int m_nDataCount;
	int m_nSubStackCount;
};