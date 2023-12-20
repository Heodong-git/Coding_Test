#include <iostream>
#include <list>

template <typename T>
class LinkNode
{
public:
	template <typename T>
	friend class MyList;
	
private:
	LinkNode()
	{
		
	}
	~LinkNode()
	{

	}


private:
	LinkNode<T>* m_pPrevNode = nullptr;
	LinkNode<T>* m_pNextNode = nullptr;
	T m_Data;
};


template <typename T>
class LinkNode;

template <typename T>
class MyList
{
public:
	class iterator
	{
	public:
		template <typename T>
		friend class MyList;

	public:
		// 리스트의 ++은 다르지 
		iterator& operator++ ()
		{
			m_pNode = m_pNode->m_pNextNode;
			return *this;
		}

		// 후위 ㅈㄴ헷갈리니까 나중에해 
		iterator operator++ (int)
		{
			iterator iter;
			iter.m_pNode = m_pNode->m_NextNode;
			return iter;
		}

		bool operator!= (iterator& _iter)
		{
			if (m_pNode->m_Data != _iter.m_pNode->m_Data)
			{
				return true;
			}

			return false;
		}

		bool operator== (iterator& _iter)
		{
			if (m_pNode->m_Data == _iter.m_pNode->m_Data)
			{
				return true;
			}

			return false;
		}

		T operator* ()
		{
			return (*m_pNode).m_Data;
		}

	private:
		LinkNode<T>* m_pNode = nullptr;
	};

public:
	MyList()
	{
		// 생성자에서 비긴노드랑 리스트노드를 생성하고, 연결시켜줌
		m_pBeginNode = new LinkNode<T>;
		m_pEndNode = new LinkNode<T>;

		m_pBeginNode->m_pNextNode = m_pEndNode;
		m_pEndNode->m_pPrevNode = m_pBeginNode;
	}
	~MyList()
	{
		// begin, end 노드 사이 모두삭제 
		if (0 != m_iSize)
		{
			clear();
			m_iSize = 0;
		}

		// 비긴노드 엔드노드 연결 끊고 삭제 후 nullptr 초기화
		m_pBeginNode->m_pNextNode = nullptr;
		m_pEndNode->m_pPrevNode = nullptr;


		delete m_pBeginNode;
		delete m_pEndNode;
	}

public:
	iterator begin()
	{
		iterator iter;
		iter.m_pNode = m_pBeginNode->m_pNextNode;

		return iter;
	}

	iterator end()
	{
		iterator iter;
		iter.m_pNode = m_pEndNode;

		return iter;
	}

	size_t size() const
	{
		return m_iSize;
	}

	// erase는 해당 이터레이터를 지우고 그 다음 노드를 이터레이터에 담아서 반환한다.
	iterator erase(iterator& _iter)
	{
		iterator iter;

		iterator StartIter = begin();
		iterator EndIter = end();

		for (; StartIter != EndIter; ++StartIter)
		{
			// 데이터가 같다면 삭제 후 앞뒤 노드를 다시 연결해주고
			// 삭제한 노드의 다음 노드를 반환한다. 
			if (StartIter == _iter)
			{
				LinkNode<T>* PrevNode = _iter.m_pNode->m_pPrevNode;
				LinkNode<T>* NextNode = _iter.m_pNode->m_pNextNode;

				delete _iter.m_pNode;
				_iter.m_pNode = nullptr;

				PrevNode->m_pNextNode = NextNode;
				NextNode->m_pPrevNode = PrevNode;

				--m_iSize;

				iter.m_pNode = NextNode;

				return iter;
			}
		}

		// 만약 삭제할 노드를 찾지 못했다면 end 반환 

		return EndIter;
	}
	
	void clear()
	{
		// 리스트 순회, 다지우고 사이즈 0 으로 
		LinkNode<T>* Node = nullptr;
		Node = m_pBeginNode->m_pNextNode;

		// 노드가 엔드노드가 아니라면 반복 
		while (Node != m_pEndNode)
		{
			// 삭제할 노드의 다음 노드를 저장
			LinkNode<T>* NextNode = Node->m_pNextNode;

			// 노드 삭제 
			delete Node;
			Node = nullptr;

			// 다음 노드 저장
			// 엔드노드까지 반복 
			Node = NextNode;
		}

		// 반복이 종료 되었다면 사이즈를 0 으로 초기화
		m_iSize = 0;
	}

	void push_back(T _Data)
	{
		// 생성 후 데이터 넣어주고 
		LinkNode<T>* Node = new LinkNode<T>;
		Node->m_Data = _Data;

		// 연결 
		Node->m_pPrevNode = m_pEndNode->m_pPrevNode;
		m_pEndNode->m_pPrevNode->m_pNextNode = Node;

		Node->m_pNextNode = m_pEndNode;
		m_pEndNode->m_pPrevNode = Node;

		++m_iSize;
	}

	void push_front(T _Data)
	{
		// 생성 후 데이터 넣어주고 
		LinkNode<T>* Node = new LinkNode<T>;
		Node->m_Data = _Data;

		Node->m_pNextNode = m_pBeginNode->m_pNextNode;
		m_pBeginNode->m_pNextNode->m_pPrevNode = Node;

		Node->m_pPrevNode = m_pBeginNode;
		m_pBeginNode->m_pNextNode = Node;

		++m_iSize;
	}

private:
	LinkNode<T>* m_pBeginNode = nullptr;
	LinkNode<T>* m_pEndNode = nullptr;

	size_t m_iSize = 0;
};


int main()
{
	std::list<int> l;

	MyList<int> Test;
	Test.push_back(1);
	Test.push_back(2);
	Test.push_back(3);

	// 이터레이터에 
	MyList<int>::iterator StartIter = Test.begin();
	MyList<int>::iterator EndIter = Test.end();


	Test.erase(StartIter);
	Test.clear();
	


	int a = 0;
	return 0;
}