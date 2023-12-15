#include <iostream>
#include <vector>
#include <assert.h>

template <typename T>
class MyVector
{
public:
	class iterator
	{
	public:
		template <typename T>
		friend class MyVector;

	public:
		// ����
		iterator& operator++ ()
		{
			++m_pData;

			return *this;
		}

		// ���� �����򰥸��ϱ� ���߿��� 
		iterator operator++ (int)
		{
			m_pData++;
			return *this;
		}
		
		bool operator!= (iterator& _iter)
		{
			if (m_pData != _iter.m_pData)
			{
				return true;
			}
			
			return false;
		}

		T& operator* ()
		{
			return *m_pData;
		}
	private:
		T* m_pData = nullptr;
	};


public:
	MyVector()
	{
		m_pData = new T[8];
		m_iSize = 0;
		m_iCapacity = 8;
	}
	~MyVector()
	{
		delete[] m_pData;
		m_pData = nullptr;
		m_iSize = 0;
		m_iCapacity = 0;
	}

public:
	// �����ڿ����ε�
	T& operator[] (const int _Index)
	{
		return m_pData[_Index];
	}

	iterator begin()
	{
		iterator iter;
		iter.m_pData = m_pData;

		return iter;
	}

	iterator end()
	{
		iterator iter;
		// ������ ������ ���� ��ġ�� ��ȯ
		iter.m_pData = m_pData + m_iSize;

		return iter;
	}

	void clear()
	{
		m_iSize = 0;
	}

	size_t size()
	{
		return m_iSize;
	}

	size_t capacity()
	{
		return m_iCapacity;
	}

	void push_back(T _Data)
	{
		// �ϴ� ������ �ް�
		T Data = _Data;

		// �����͸� �־��ٰǵ�, �迭 ����� Ȯ���ؼ� size == capacity ��� �迭�� �÷������
		// ���࿡ ����� ���� 
		if (m_iSize == m_iCapacity)
		{
			// �׷��� �迭�� �ִ�ũ�� �ι�� �÷�
			size_t Capacity = m_iCapacity * 2;

			// ���ο� �迭 �����
			T* Temp = new T[Capacity];
			
			// ���θ��� �迭�� ���� �迭�� �����͸� �߰�����
			for (size_t i = 0; i < m_iSize; ++i)
			{
				Temp[i] = m_pData[i];
			}
			
			// ���� �迭�� ����
			delete[] m_pData;
			m_pData = nullptr;

			// �׸��� Temp �� �����ּҸ� �ϰ� ������ 
			m_pData = Temp;

			// �ִ� ũ�Ⱑ �þ���ϱ� ������
			m_iCapacity = Capacity;

			// ������ �־� 
			m_pData[m_iSize] = Data;
		}

		else
		{
			// �װ� �ƴϸ� �׳� �־�
			// // Size�� index �ϱ� ������ �־��ְ�
			m_pData[m_iSize] = Data;
		}

		// ������ �߰� 
		++m_iSize;
	}

	void pop_back()
	{
		--m_iSize;
	}


	void resize(const size_t _Size)
	{
		// �迭�� �ִ�ũ��� ���Ұ�������
		size_t Size = _Size;

		// ���� ���ڷ� ���� ����� �� ũ�ٸ� 
		if (m_iSize < Size)
		{
			T* Temp = new T[Size];

			// ���������͸� ���� �迭�� �����ŭ ä���ְ� 
			for (size_t i = 0; i < m_iSize; ++i)
			{
				Temp[i] = m_pData[i];
			}

			m_iSize = Size;
			m_iCapacity = Size;
		}

		// ���۴ٸ� 
		// �ܼ��ϰ� �׳� ����� �ٿ� 
		else if (m_iSize > Size)
		{
			m_iSize = Size;
		}
	}

	// �迭�� �ִ� ũ�� �����ε�, ũ�⿹��
	// std::vector �� ��� 32 ������ �þ 
	void reserve(const size_t _Capacity)
	{
		size_t Capacity = _Capacity;

		// ���� ���� �ִ�ũ�⺸�� ���� ���� ���Դٸ� 
		if (m_iCapacity > _Capacity)
		{
			// ���ڷ� ���� ũ�� ��ŭ�� �迭�� �����Ҵ���
			T* Temp = new T[Capacity];

			// ���� �迭�� �����ŭ ������ ä���ְ�
			for (size_t i = 0; i < Capacity; ++i)
			{
				Temp[i] = m_pData[i];
			}

			// ���� �迭�� ����
			delete[] m_pData;
			m_pData = nullptr;

			// �׸��� Temp �� �����ּҸ� �ϰ� ������ 
			m_pData = Temp;

			// �ִ� ũ�Ⱑ ����Ǿ����ϱ� ����
			m_iCapacity = Capacity;
			m_iSize = Capacity;

			return;
		}

		// ���ڷ� ���� ũ�� ��ŭ�� �迭�� �����Ҵ���
		T* Temp = new T[Capacity];

		// ���� �迭�� �����ŭ ������ ä���ְ�
		for (size_t i = 0; i < m_iSize; ++i)
		{
			Temp[i] = m_pData[i];
		}

		// ���� �迭�� ����
		delete[] m_pData;
		m_pData = nullptr;

		// �׸��� Temp �� �����ּҸ� �ϰ� ������ 
		m_pData = Temp;

		// �ִ� ũ�Ⱑ ����Ǿ����ϱ� ����
		m_iCapacity = Capacity;
	}

private:
	T* m_pData = nullptr;
	size_t m_iSize;        // ���Ϳ� ����Ǿ� �ִ� �������� ũ�� 
	size_t m_iCapacity;    // ������ ��üũ�� 
};



int main()
{
	{
		MyVector<int> v;
		v.push_back(6);
		v.push_back(4);
		size_t Size = v.size();
		size_t Capacity = v.capacity();
		v.resize(1);
		v.reserve(10);
		v.push_back(1);

		v.clear();
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		int a = 0;

		MyVector<int>::iterator StartIter = v.begin();
		MyVector<int>::iterator EndIter = v.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter) = 3;
		}


		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << std::endl;
		}

		v.pop_back();

		size_t TestSize = v.size();
		v.push_back(5);

	}
	
	{
		std::vector<int> V;
		V.push_back(6);
		V.push_back(4);
		size_t Size = V.size();
		size_t Capacity = V.capacity();
		V.resize(1);
		V.reserve(10);
		V.push_back(1);

		V.clear();
		V.push_back(2);
		V.push_back(3);
		V.push_back(4);

		std::vector<int>::iterator StartIter = V.begin();
		std::vector<int>::iterator EndIter = V.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter) = 3;
		}


		for (size_t i = 0; i < V.size(); i++)
		{
			std::cout << V[i] << std::endl;
		}
	}

	return 0;
}