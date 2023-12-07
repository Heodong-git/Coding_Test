#include <iostream>
#include <vector>
#include <algorithm>


// 중복되지 않은 M개 중에, n개를 뽑는 경우의 수 순서는 중요하지 않음 - 조합 

int T;
int R, N;
 
int DP[30][30] = {};

int Combination(int _N, int _R)
{
	// 만약 R 이 0이라면 경우의 수는 1이 된다.
	// 또는 N과 R 이 같다면 경우의 수는 1 이된다.
	//if (_R == 0 || _N == _R)
	//{
	//	return 1;
	//}
	//// 그게 아니라면 공식 그대로 사용
	//// nCr = n-1Cr-1 + n-1Cr 
	//else
	//{
	//	return Combination(_N - 1, _R - 1) + Combination(_N - 1, _R);
	//}

	return DP[_N][_R];
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
	// i 개를 0개 뽑는 경우의 수는 1이기 때문에 전부 1 저장
	for (int i = 1; i <= 29; i++)
	{
		DP[i][0] = 1;
	}

	// 마찬가지로 i 개를 1개 뽑는 경우의 수는 i 개 이기 때문에 전부 i 저장
	for (int i = 1; i <= 29; i++)
	{
		DP[i][1] = i;
	}
	
	// 반복돌면서 그냥 공식 넣어서 저장해 
	for (int N = 1; N <= 29; N++)
	{
		for (int R = 2; R <= 29; R++)
		{
			DP[N][R] = DP[N - 1][R - 1] + DP[N - 1][R];
		}
	}

	// 정답 저장해놓을 벡터
	std::vector<int> Values = {};

	std::cin >> T;
	Values.resize(T);
	for (int i = 0; i < T; ++i)
	{
		std::cin >> R >> N;
		Values[i] =  Combination(N, R);
	}
	
	// 저장해놓은 값 출력
	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cout << Values[i] << std::endl;
	}


	return 0;
}