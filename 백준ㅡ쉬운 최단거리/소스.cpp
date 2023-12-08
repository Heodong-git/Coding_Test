#include <iostream>
#include <vector>
#include <set>
#include <queue>

// 지도의 크기 n과 m
int N, M;

// 길 
std::vector<std::vector<int>> Road;
// 길에 방문했는지 
std::vector<std::vector<bool>> Visit;

std::vector<std::vector<std::set<std::pair<int,int>>>> LinkNodes;
// 시작점부터의 거리 
std::vector<std::vector<int>> Distances;

// 여기서 뭘해줘야되냐면. 시작지점으로 부터 내가 얼마나 떨어져 있는지를 저장해야함. 
void BFS(std::pair<int, int> _StartIdx)
{
	// 깊이를 저장할 배열
	Distances.resize(N);
	for (size_t i = 0; i < Distances.size(); i++)
	{
		Distances[i].resize(M);
		for (size_t j = 0; j < Distances[i].size(); j++)
		{
			if (Road[i][j] == 0)
			{
				Distances[i][j] = 0;
				continue;
			}

			Distances[i][j] = -1;
		}
	}

	// q 만들어
	std::queue<std::pair<int, int>> q;
	
	// q에 넣어 
	q.push(_StartIdx);
	
	// 방문상태로 바꿔 
	Visit[_StartIdx.first][_StartIdx.second] = true;	
	Distances[_StartIdx.first][_StartIdx.second] = 0;

	// while 돌아
	// q가 빌때 까지 돌아
	while (false == q.empty())
	{
		// q에서 꺼내 
		std::pair<int ,int> Idx = q.front();
		// 지워
		q.pop();

		// 여기서 
		for (auto& LinkNode : LinkNodes[Idx.first][Idx.second])
		{
			// 순회돌건데. pair 의 first, second 의 값이 둘다 0 이상이어야만 함
			if ((0 <= LinkNode.first && 0 <= LinkNode.second) && (N > LinkNode.first && M > LinkNode.second))
			{
				if (false == Visit[LinkNode.first][LinkNode.second])
				{
					// 근데 만약 거기가 벽이야 그러면 continue
					if (0 == Distances[LinkNode.first][LinkNode.second])
					{
						continue;
					}

					Visit[LinkNode.first][LinkNode.second] = true;
					Distances[LinkNode.first][LinkNode.second] = Distances[Idx.first][Idx.second] + 1;
					q.push(LinkNode);
				}
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N >> M;
	std::pair<int, int> Target;

	// 길 
	Road.resize(N);
	for (size_t i = 0; i < Road.size(); i++)
	{
		Road[i].resize(M);
		for (size_t j = 0; j < Road[i].size(); j++)
		{
			std::cin >> Road[i][j];
			if (2 == Road[i][j])
			{
				Target = { i , j };
			}
		}
	}

	// 방문상태
	Visit.resize(N);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i].resize(M);
		for (size_t j = 0; j < Visit[i].size(); j++)
		{
			Visit[i][j] = false;
		}
	}
	
	// 링크노드 
	LinkNodes.resize(N);
	for (int i = 0; i < static_cast<int>(LinkNodes.size()); i++)
	{
		LinkNodes[i].resize(M);
		for (int j = 0; j < static_cast<int>(LinkNodes[i].size()); j++)
		{
			// 그냥 다 연결하고, 탐색할때 0 이하면 탐색 안함
			LinkNodes[i][j].insert(std::make_pair(i, j + 1));
			LinkNodes[i][j].insert(std::make_pair(i + 1, j));
			LinkNodes[i][j].insert(std::make_pair(i, j - 1));
			LinkNodes[i][j].insert(std::make_pair(i - 1, j));
		}
	}

	BFS(Target);

	for (size_t i = 0; i < Distances.size(); i++)
	{
		for (size_t j = 0; j < Distances[i].size(); j++)
		{
			std::cout << Distances[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}