#include <iostream>
#include <vector>
#include <set>
#include <queue>


std::vector<std::set<int>> Nodes;
std::vector<bool> Visit;

// 순회를 시작할 노드의 인덱스를 인자로 받는다. 
void DFS(int _StartIdx)
{
	// 방문할거니까 방문상태 true 로 변경
	Visit[_StartIdx] = true;

	// 방문 노드값 출력, 0번 idx도 사용했기 때문에 + 1 한 값으로 
	std::cout << _StartIdx + 1 << " ";

	// 연결된 노드들을 순회하며 방문상태가 false라면 방문한다. 
	//std::set<int>::iterator StartIter = Nodes[_StartIdx].begin();
	//std::set<int>::iterator EndIter = Nodes[_StartIdx].end();
	//for (; StartIter != EndIter; ++StartIter)
	//{
	//	// 방문상태가 false라면 
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

// 인자로 시작노드의 인덱스와 
void BFS(int _StartIdx)
{
	// 일단 큐를 만들어
	std::queue<int> q;

	// 큐에 시작노드의 Idx 를 넣어 
	q.push(_StartIdx);
	
	// 방문처리해
	Visit[_StartIdx] = true;

	// q가 빌 때 까지 while 돌아 
	while (false == q.empty())
	{
		// q에서 하나 꺼내 
		// 이 때 꺼낸 값이 시작점을 기준으로 시작인덱스인거임 
		int node = q.front();

		// q에서 지워
		q.pop();
		
		// 출력해 
		std::cout << node + 1 << " ";
		
		// 반복돌아
		//std::set<int>::iterator StartIter = Nodes[node].begin();
		//std::set<int>::iterator EndIter = Nodes[node].end();
		//for (; StartIter != EndIter; ++StartIter)
		//{
		//	// 방문상태가 false라면 
		//	if (Visit[*StartIter] == false)
		//	{
		//		// true 로 변경
		//		Visit[*StartIter] = true;

		//		// q에 넣어
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

	// 정점의 개수 
	int N;
	// 간선의 개수 
	int M;
	// 탐색을 시작할 정점의 번호
	int V;

	std::cin >> N >> M >> V;

	// 벡터의 인덱스가 노드, set에 저장되는 값이 연결된 노드
	Nodes.resize(N); 
	Visit.resize(N);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i] = false;
	}
	
	// 간선의 개수 만큼 반복
	for (int i = 0; i < M; i++)
	{
		// 노드번호 
		int Idx;
		// 노드와 연결될 노드 
		int LinkIdx;
		std::cin >> Idx >> LinkIdx;
		Nodes[Idx - 1].insert(LinkIdx - 1);
		Nodes[LinkIdx - 1].insert(Idx - 1);
	}

	// 연결은 됐고 
	DFS(V - 1);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i] = false;
	}
	std::cout << std::endl;
	BFS(V - 1);

	return 0;
}