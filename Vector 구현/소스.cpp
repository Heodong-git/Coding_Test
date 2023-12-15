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
		// 전위
		iterator& operator++ ()
		{
			++m_pData;

			return *this;
		}

		// 후위 ㅈㄴ헷갈리니까 나중에해 
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
	// 연산자오버로딩
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
		// 마지막 원소의 다음 위치를 반환
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
		// 일단 데이터 받고
		T Data = _Data;

		// 데이터를 넣어줄건데, 배열 사이즈를 확인해서 size == capacity 라면 배열을 늘려줘야함
		// 만약에 사이즈가 같아 
		if (m_iSize == m_iCapacity)
		{
			// 그러면 배열의 최대크기 두배로 늘려
			size_t Capacity = m_iCapacity * 2;

			// 새로운 배열 만들어
			T* Temp = new T[Capacity];
			
			// 새로만든 배열에 현재 배열의 데이터를 추가해줘
			for (size_t i = 0; i < m_iSize; ++i)
			{
				Temp[i] = m_pData[i];
			}
			
			// 기존 배열을 지워
			delete[] m_pData;
			m_pData = nullptr;

			// 그리고 Temp 의 시작주소를 니가 가리켜 
			m_pData = Temp;

			// 최대 크기가 늘어났으니까 저장해
			m_iCapacity = Capacity;

			// 데이터 넣어 
			m_pData[m_iSize] = Data;
		}

		else
		{
			// 그게 아니면 그냥 넣어
			// // Size가 index 니까 데이터 넣어주고
			m_pData[m_iSize] = Data;
		}

		// 사이즈 추가 
		++m_iSize;
	}

	void pop_back()
	{
		--m_iSize;
	}


	void resize(const size_t _Size)
	{
		// 배열의 최대크기와 원소개수조정
		size_t Size = _Size;

		// 만약 인자로 들어온 사이즈가 더 크다면 
		if (m_iSize < Size)
		{
			T* Temp = new T[Size];

			// 기존데이터를 기존 배열의 사이즈만큼 채워주고 
			for (size_t i = 0; i < m_iSize; ++i)
			{
				Temp[i] = m_pData[i];
			}

			m_iSize = Size;
			m_iCapacity = Size;
		}

		// 더작다면 
		// 단순하게 그냥 사이즈만 줄여 
		else if (m_iSize > Size)
		{
			m_iSize = Size;
		}
	}

	// 배열의 최대 크기 조정인데, 크기예약
	// std::vector 의 경우 32 단위로 늘어남 
	void reserve(const size_t _Capacity)
	{
		size_t Capacity = _Capacity;

		// 만약 현재 최대크기보다 작은 값이 들어왔다면 
		if (m_iCapacity > _Capacity)
		{
			// 인자로 들어온 크기 만큼의 배열을 동적할당해
			T* Temp = new T[Capacity];

			// 현재 배열의 사이즈만큼 데이터 채워주고
			for (size_t i = 0; i < Capacity; ++i)
			{
				Temp[i] = m_pData[i];
			}

			// 기존 배열을 지워
			delete[] m_pData;
			m_pData = nullptr;

			// 그리고 Temp 의 시작주소를 니가 가리켜 
			m_pData = Temp;

			// 최대 크기가 변경되었으니까 갱신
			m_iCapacity = Capacity;
			m_iSize = Capacity;

			return;
		}

		// 인자로 들어온 크기 만큼의 배열을 동적할당해
		T* Temp = new T[Capacity];

		// 현재 배열의 사이즈만큼 데이터 채워주고
		for (size_t i = 0; i < m_iSize; ++i)
		{
			Temp[i] = m_pData[i];
		}

		// 기존 배열을 지워
		delete[] m_pData;
		m_pData = nullptr;

		// 그리고 Temp 의 시작주소를 니가 가리켜 
		m_pData = Temp;

		// 최대 크기가 변경되었으니까 갱신
		m_iCapacity = Capacity;
	}

private:
	T* m_pData = nullptr;
	size_t m_iSize;        // 벡터에 저장되어 있는 데이터의 크기 
	size_t m_iCapacity;    // 벡터의 전체크기 
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