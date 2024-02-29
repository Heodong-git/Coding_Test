#include <iostream>
#include <vector>
#include <algorithm>


// i 번째 행은, 


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int N;
	std::cin >> N;

	int K;
	std::cin >> K;

	std::vector<std::vector<int>> A;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		A[i].resize(N);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = (i + 1) * (j + 1);
		}
	}
	
	std::vector<int> v;
	v.reserve(N * N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			v.push_back(A[i][j]);
		}
	}

	// 여기서 이진탐색으로 풀어야되나보네 
	sort(v.begin(), v.end());

	std::cout << v[K];

	return 0;
}