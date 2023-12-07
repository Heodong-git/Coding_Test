#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<std::set<int>> Nodes;
std::vector<std::pair<bool, int>> VisitAndOrder;

int Order = 1;
// 인자로 시작노드의 인덱스와 
void BFS(int _StartIdx)
{
	// 일단 큐를 만들어
	std::queue<int> q;

	// 큐에 시작노드의 Idx 를 넣어
	q.push(_StartIdx);

	// 방문처리해
	VisitAndOrder[_StartIdx].first = true;
	VisitAndOrder[_StartIdx].second = Order;

	// q가 빌 때 까지 while 돌아 
	while (false == q.empty())
	{
		// q에서 하나 꺼내 
		// 이 때 꺼낸 값이 시작점을 기준으로 시작인덱스인거임 
		int node = q.front();

		// q에서 지워
		q.pop();

		for (auto& Node : Nodes[node])
		{
			if (VisitAndOrder[Node].first == false)
			{
				VisitAndOrder[Node].first = true;
				VisitAndOrder[Node].second = ++Order;
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
	// 시작 노드 번호 
	int V;

	std::cin >> N >> M >> V;

	// 벡터의 인덱스가 노드, set에 저장되는 값이 연결된 노드
	Nodes.resize(N);
	VisitAndOrder.resize(N);
	for (size_t i = 0; i < VisitAndOrder.size(); i++)
	{
		VisitAndOrder[i].first = false;
		VisitAndOrder[i].second = 0;
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

	BFS(V - 1);

	for (size_t i = 0; i < VisitAndOrder.size(); i++)
	{
		std::cout << VisitAndOrder[i].second << "\n";
	}

	return 0;
}