#include <iostream>
#include <vector>
#include <set>
#include <queue>


std::vector<std::set<int>> Nodes;
std::vector<bool> Visit;

// ��ȸ�� ������ ����� �ε����� ���ڷ� �޴´�. 
void DFS(int _StartIdx)
{
	// �湮�ҰŴϱ� �湮���� true �� ����
	Visit[_StartIdx] = true;

	// �湮 ��尪 ���, 0�� idx�� ����߱� ������ + 1 �� ������ 
	std::cout << _StartIdx + 1 << " ";

	// ����� ������ ��ȸ�ϸ� �湮���°� false��� �湮�Ѵ�. 
	//std::set<int>::iterator StartIter = Nodes[_StartIdx].begin();
	//std::set<int>::iterator EndIter = Nodes[_StartIdx].end();
	//for (; StartIter != EndIter; ++StartIter)
	//{
	//	// �湮���°� false��� 
	//	if (Visit[*StartIter] == false)
	//	{
	//		DFS(*StartIter);
	//	}
	//}

	for (auto& Node : Nodes[_StartIdx])
	{
		if (Visit[Node] == false)
		{
			DFS(Node);
		}
	}
}

// ���ڷ� ���۳���� �ε����� 
void BFS(int _StartIdx)
{
	// �ϴ� ť�� �����
	std::queue<int> q;

	// ť�� ���۳���� Idx �� �־� 
	q.push(_StartIdx);
	
	// �湮ó����
	Visit[_StartIdx] = true;

	// q�� �� �� ���� while ���� 
	while (false == q.empty())
	{
		// q���� �ϳ� ���� 
		// �� �� ���� ���� �������� �������� �����ε����ΰ��� 
		int node = q.front();

		// q���� ����
		q.pop();
		
		// ����� 
		std::cout << node + 1 << " ";
		
		// �ݺ�����
		//std::set<int>::iterator StartIter = Nodes[node].begin();
		//std::set<int>::iterator EndIter = Nodes[node].end();
		//for (; StartIter != EndIter; ++StartIter)
		//{
		//	// �湮���°� false��� 
		//	if (Visit[*StartIter] == false)
		//	{
		//		// true �� ����
		//		Visit[*StartIter] = true;

		//		// q�� �־�
		//		q.push(*StartIter);
		//	}
		//}

		for (auto& Node : Nodes[node])
		{
			if (Visit[Node] == false)
			{
				Visit[Node] = true;
				q.push(Node);
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// ������ ���� 
	int N;
	// ������ ���� 
	int M;
	// Ž���� ������ ������ ��ȣ
	int V;

	std::cin >> N >> M >> V;

	// ������ �ε����� ���, set�� ����Ǵ� ���� ����� ���
	Nodes.resize(N); 
	Visit.resize(N);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i] = false;
	}
	
	// ������ ���� ��ŭ �ݺ�
	for (int i = 0; i < M; i++)
	{
		// ����ȣ 
		int Idx;
		// ���� ����� ��� 
		int LinkIdx;
		std::cin >> Idx >> LinkIdx;
		Nodes[Idx - 1].insert(LinkIdx - 1);
		Nodes[LinkIdx - 1].insert(Idx - 1);
	}

	// ������ �ư� 
	DFS(V - 1);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i] = false;
	}
	std::cout << std::endl;
	BFS(V - 1);

	return 0;
}