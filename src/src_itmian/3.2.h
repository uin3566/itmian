#pragma once

template<typename T>
class CStackWithMin
{
public:
	void PushStack(T tValue)
	{
		T tStkMinTop;

		m_stkData.push(tValue);
		if (m_stkMin.empty())
		{
			m_stkMin.push(tValue);
		}
		else
		{
			tStkMinTop = m_stkMin.top();
			if (tValue <= tStkMinTop)
			{
				m_stkMin.push(tValue);
			}
		}
	}

	void PopStack()
	{
		T tStkDataTop;
		T tSktMinTop;

		if (m_stkData.empty())
		{
			goto Exit0;
		}
		tStkDataTop = m_stkData.top();
		tSktMinTop = m_stkMin.top();
		if (tSktMinTop == tStkDataTop)
		{
			m_stkMin.pop();
			m_stkData.pop();
		}
		else
		{
			m_stkData.pop();
		}

	Exit0:
		return;
	}

	T GetMinInStk()
	{
		T tRet;
		if (m_stkMin.empty())
		{
			memset(&tRet, 0, sizeof(tRet));
		}
		else
		{
			tRet = m_stkMin.top();
		}
		return tRet;
	}

private:
	std::stack<T> m_stkData;
	std::stack<T> m_stkMin;
};