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
		// ����Ʈ�� ++�� �ٸ��� 
		iterator& operator++ ()
		{
			m_pNode = m_pNode->m_pNextNode;
			return *this;
		}

		// ���� �����򰥸��ϱ� ���߿��� 
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
		// �����ڿ��� ������ ����Ʈ��带 �����ϰ�, ���������
		m_pBeginNode = new LinkNode<T>;
		m_pEndNode = new LinkNode<T>;

		m_pBeginNode->m_pNextNode = m_pEndNode;
		m_pEndNode->m_pPrevNode = m_pBeginNode;
	}
	~MyList()
	{
		// begin, end ��� ���� ��λ��� 
		if (0 != m_iSize)
		{
			clear();
			m_iSize = 0;
		}

		// ����� ������ ���� ���� ���� �� nullptr �ʱ�ȭ
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

	// erase�� �ش� ���ͷ����͸� ����� �� ���� ��带 ���ͷ����Ϳ� ��Ƽ� ��ȯ�Ѵ�.
	iterator erase(iterator& _iter)
	{
		iterator iter;

		iterator StartIter = begin();
		iterator EndIter = end();

		for (; StartIter != EndIter; ++StartIter)
		{
			// �����Ͱ� ���ٸ� ���� �� �յ� ��带 �ٽ� �������ְ�
			// ������ ����� ���� ��带 ��ȯ�Ѵ�. 
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

		// ���� ������ ��带 ã�� ���ߴٸ� end ��ȯ 

		return EndIter;
	}
	
	void clear()
	{
		// ����Ʈ ��ȸ, ������� ������ 0 ���� 
		LinkNode<T>* Node = nullptr;
		Node = m_pBeginNode->m_pNextNode;

		// ��尡 �����尡 �ƴ϶�� �ݺ� 
		while (Node != m_pEndNode)
		{
			// ������ ����� ���� ��带 ����
			LinkNode<T>* NextNode = Node->m_pNextNode;

			// ��� ���� 
			delete Node;
			Node = nullptr;

			// ���� ��� ����
			// ��������� �ݺ� 
			Node = NextNode;
		}

		// �ݺ��� ���� �Ǿ��ٸ� ����� 0 ���� �ʱ�ȭ
		m_iSize = 0;
	}

	void push_back(T _Data)
	{
		// ���� �� ������ �־��ְ� 
		LinkNode<T>* Node = new LinkNode<T>;
		Node->m_Data = _Data;

		// ���� 
		Node->m_pPrevNode = m_pEndNode->m_pPrevNode;
		m_pEndNode->m_pPrevNode->m_pNextNode = Node;

		Node->m_pNextNode = m_pEndNode;
		m_pEndNode->m_pPrevNode = Node;

		++m_iSize;
	}

	void push_front(T _Data)
	{
		// ���� �� ������ �־��ְ� 
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

	// ���ͷ����Ϳ� 
	MyList<int>::iterator StartIter = Test.begin();
	MyList<int>::iterator EndIter = Test.end();


	Test.erase(StartIter);
	Test.clear();
	


	int a = 0;
	return 0;
}