#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// 자연수 N 이 주어진다. 
	int N = 0;
	std::cin >> N;
	if ((1 > N || 100000 < N))
	{
		assert(false);
	}

	// 다음줄에는 N개의 정수가 주어진다.
	std::vector<int> N_Values = std::vector<int>();
	N_Values.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> N_Values[i];
		if ((N_Values[i] < pow(-2, 31)) || N_Values[i] >= pow(2, 31))
		{
			assert(false);
		}

	}

	// 다음줄에는 M이 주어진다. 
	int M = 0;
	std::cin >> M;
	if ((1 > M || 100000 < M))
	{
		assert(false);
	}

	// 다음줄에는 M개의 수가 주어진다.
	std::vector<int> M_Values = std::vector<int>();
	M_Values.resize(M);

	for (int i = 0; i < M; i++)
	{
		std::cin >> M_Values[i];
		if ((M_Values[i] < pow(-2, 31)) || M_Values[i] >= pow(2, 31))
		{
			assert(false);
		}
	}

	// M 벡터에 저장되어있는 수들이 A안에 존재하는지 알아내면 된다.
	// 원소 정렬 
	std::sort(N_Values.begin(), N_Values.end());

	// 자료구조를 순회하며 이진탐색 
	for (size_t i = 0; i < M_Values.size(); i++)
	{
		// 0번인덱스 
		int lt = 0;
		// 마지막 인덱스 
		int rt = static_cast<int>(N_Values.size() - 1);
		bool Check = false;

		// 마지막인덱스 값을 넘어설때 까지 반복 
		while (lt <= rt)
		{
			// 미드 인덱스 값 
			int mid = (lt + rt) / 2;

			// 값이 동일하다면 1 출력, Check 변수 true 로 변경 후 break 로 반복문을 빠져나간다.
			if (N_Values[mid] == M_Values[i])
			{
				std::cout << 1 << "\n";
				Check = true;
				break;
			}

			// 만약 mid 인덱스 번째의 원소 값이 찾고자 하는 값보다 작다면 
			// 시작인덱스값을 현재 mid 값 + 1 로 변경
			else if (N_Values[mid] < M_Values[i])
			{
				lt = mid + 1;
			}

			else if (N_Values[mid] > M_Values[i])
			{
				rt = mid - 1;
			}
		}

		// Check 변수가 false 라면 
		// 값을 찾지 못한 것이다. 0 출력 
		if (false == Check)
		{
			std::cout << 0 << "\n";
		}
	}


	// std::binary_search 를 활용한 풀이
	/*std::sort(N_Values.begin(), N_Values.end());
	for (size_t i = 0; i < M_Values.size(); i++)
	{
		bool Check = std::binary_search(N_Values.begin(), N_Values.end(), M_Values[i]);
		std::cout << Check << "\n";
	}*/

	return 0;
}