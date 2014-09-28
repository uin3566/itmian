#pragma once

//两个栈实现一个队列
template<typename T>
class CMyQueue
{
public:
	void PushBack(T tValue)
	{
		m_stkPushStack.push(tValue);
	}

	void PopFront()
	{
		if (m_stkPopStack.size() == 0)
		{
			_MoveStackData(m_stkPushStack, m_stkPopStack);
		}
		if (m_stkPopStack.size())
		{
			m_stkPopStack.pop();
		}
	}

	T PeekFront()
	{
		T tRet;
		if (m_stkPopStack.size() == 0)
		{
			_MoveStackData(m_stkPushStack, m_stkPopStack);
		}
		if (m_stkPopStack.size())
		{
			tRet = m_stkPopStack.top();
		}
		return tRet;
	}

	T PeekBack()
	{
		T tRet;
		if (m_stkPushStack.size() == 0)
		{
			_MoveStackData(m_stkPopStack, m_stkPushStack);
		}
		if (m_stkPushStack.size())
		{
			tRet = m_stkPushStack.top();
		}
		return tRet;
	}

	int GetQueueSize()
	{
		return m_stkPushStack.size() + m_stkPopStack.size();
	}

private:
	void _MoveStackData(std::stack<T>& stkSrc, std::stack<T>& stkDes)
	{
		T tTmp;

		if (stkSrc.size() == 0)
		{
			goto Exit0;
		}

		while(stkSrc.size())
		{
			tTmp = stkSrc.top();
			stkDes.push(tTmp);
			stkSrc.pop();
		}

	Exit0:
		return;
	}

private:
	std::stack<T> m_stkPushStack;//入队栈
	std::stack<T> m_stkPopStack;//出队栈
};

//两个队列实现一个栈
template<typename T>
class CMyStack
{
private:
	typedef std::queue<T> Queue;

public:
	CMyStack() : m_pDataQueue(NULL), m_pEmptyQueue(NULL), m_pSwapQueue(NULL)
	{
		m_pDataQueue = new Queue;
		m_pEmptyQueue = new Queue;
	}

	~CMyStack()
	{
		if (m_pDataQueue)
		{
			delete m_pDataQueue;
			m_pDataQueue = NULL;
		}
		if (m_pEmptyQueue)
		{
			delete m_pEmptyQueue;
			m_pEmptyQueue = NULL;
		}
	}

	void PushStack(T tValue)
	{
		m_pDataQueue->push(tValue);
	}

	void PopStack()
	{
		if (m_pDataQueue->empty())
		{
			goto Exit0;
		}
		while(m_pDataQueue->size() > 1)
		{
			T tValue;
			tValue = m_pDataQueue->front();
			m_pEmptyQueue->push(tValue);
			m_pDataQueue->pop();
		}
		m_pDataQueue->pop();
		_SwapQueuePointer();

	Exit0:
		return;
	}

	int GetStackSize()
	{
		return m_pDataQueue->size();
	}

	T PeekTop()
	{
		T tRet;
		if (m_pDataQueue->size())
		{
			tRet = m_pDataQueue->back();
		}
		return tRet;
	}

private:
	void _SwapQueuePointer()
	{
		m_pSwapQueue = m_pDataQueue;
		m_pDataQueue = m_pEmptyQueue;
		m_pEmptyQueue = m_pSwapQueue;
	}

private:
	Queue* m_pSwapQueue;
	Queue* m_pDataQueue;
	Queue* m_pEmptyQueue;
};