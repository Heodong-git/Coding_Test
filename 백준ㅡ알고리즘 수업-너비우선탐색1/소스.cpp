#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<std::set<int>> Nodes;
std::vector<std::pair<bool, int>> VisitAndOrder;

int Order = 1;
// ���ڷ� ���۳���� �ε����� 
void BFS(int _StartIdx)
{
	// �ϴ� ť�� �����
	std::queue<int> q;

	// ť�� ���۳���� Idx �� �־�
	q.push(_StartIdx);

	// �湮ó����
	VisitAndOrder[_StartIdx].first = true;
	VisitAndOrder[_StartIdx].second = Order;

	// q�� �� �� ���� while ���� 
	while (false == q.empty())
	{
		// q���� �ϳ� ���� 
		// �� �� ���� ���� �������� �������� �����ε����ΰ��� 
		int node = q.front();

		// q���� ����
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

	// ������ ���� 
	int N;
	// ������ ���� 
	int M;
	// ���� ��� ��ȣ 
	int V;

	std::cin >> N >> M >> V;

	// ������ �ε����� ���, set�� ����Ǵ� ���� ����� ���
	Nodes.resize(N);
	VisitAndOrder.resize(N);
	for (size_t i = 0; i < VisitAndOrder.size(); i++)
	{
		VisitAndOrder[i].first = false;
		VisitAndOrder[i].second = 0;
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

	BFS(V - 1);

	for (size_t i = 0; i < VisitAndOrder.size(); i++)
	{
		std::cout << VisitAndOrder[i].second << "\n";
	}

	return 0;
}