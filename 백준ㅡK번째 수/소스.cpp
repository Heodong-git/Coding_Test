#include <iostream>
#include <vector>
#include <algorithm>


// i ��° ����, 


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

	// ���⼭ ����Ž������ Ǯ��ߵǳ����� 
	sort(v.begin(), v.end());

	std::cout << v[K];

	return 0;
}