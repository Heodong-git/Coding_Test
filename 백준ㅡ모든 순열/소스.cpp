#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


int N;

std::vector<int> Values;
std::vector<std::vector<int>> LinkNodes;
std::vector<bool> Visit;

std::vector<int> Results;

void DFS(int _StartIdx)
{
	// 방문상태로 변경
	Visit[_StartIdx] = true;
	Results.push_back(_StartIdx);

	if (N == static_cast<int>(Results.size()))
	{
		for (size_t i = 0; i < Results.size(); i++)
		{
			std::cout << Results[i] + 1 << " ";
		}

		std::cout << "\n";
	}

	// 해당 노드에 연결된 모든 노드 방문 
	for (auto& Node : LinkNodes[_StartIdx])
	{
		// 만약 해당 노드의 방문 상태가 false라면 
		if (false == Visit[Node])
		{
			DFS(Node);
		}
	}

	Results.pop_back();
	Visit[_StartIdx] = false;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N;
	
	Values.resize(N);
	Visit.resize(N);
	Results.reserve(N);
	for (int i = 0; i < N; i++)
	{
		Values[i] = i;
	}

	LinkNodes.resize(N);
	for (int i = 0; i < N; i++)
	{
		LinkNodes[i].reserve(N);
		for (int j = 0; j < N; j++)
		{
			if (j == i)
			{
				continue;
			}

			LinkNodes[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i);
	}

	return 0;
}