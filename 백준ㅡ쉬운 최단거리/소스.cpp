#include <iostream>
#include <vector>
#include <set>
#include <queue>

// ������ ũ�� n�� m
int N, M;

// �� 
std::vector<std::vector<int>> Road;
// �濡 �湮�ߴ��� 
std::vector<std::vector<bool>> Visit;

std::vector<std::vector<std::set<std::pair<int,int>>>> LinkNodes;
// ������������ �Ÿ� 
std::vector<std::vector<int>> Distances;

// ���⼭ ������ߵǳĸ�. ������������ ���� ���� �󸶳� ������ �ִ����� �����ؾ���. 
void BFS(std::pair<int, int> _StartIdx)
{
	// ���̸� ������ �迭
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

	// q �����
	std::queue<std::pair<int, int>> q;
	
	// q�� �־� 
	q.push(_StartIdx);
	
	// �湮���·� �ٲ� 
	Visit[_StartIdx.first][_StartIdx.second] = true;	
	Distances[_StartIdx.first][_StartIdx.second] = 0;

	// while ����
	// q�� ���� ���� ����
	while (false == q.empty())
	{
		// q���� ���� 
		std::pair<int ,int> Idx = q.front();
		// ����
		q.pop();

		// ���⼭ 
		for (auto& LinkNode : LinkNodes[Idx.first][Idx.second])
		{
			// ��ȸ���ǵ�. pair �� first, second �� ���� �Ѵ� 0 �̻��̾�߸� ��
			if ((0 <= LinkNode.first && 0 <= LinkNode.second) && (N > LinkNode.first && M > LinkNode.second))
			{
				if (false == Visit[LinkNode.first][LinkNode.second])
				{
					// �ٵ� ���� �űⰡ ���̾� �׷��� continue
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

	// �� 
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

	// �湮����
	Visit.resize(N);
	for (size_t i = 0; i < Visit.size(); i++)
	{
		Visit[i].resize(M);
		for (size_t j = 0; j < Visit[i].size(); j++)
		{
			Visit[i][j] = false;
		}
	}
	
	// ��ũ��� 
	LinkNodes.resize(N);
	for (int i = 0; i < static_cast<int>(LinkNodes.size()); i++)
	{
		LinkNodes[i].resize(M);
		for (int j = 0; j < static_cast<int>(LinkNodes[i].size()); j++)
		{
			// �׳� �� �����ϰ�, Ž���Ҷ� 0 ���ϸ� Ž�� ����
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