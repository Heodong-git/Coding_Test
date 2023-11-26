#include <iostream>
#include <vector>

// 정수 n 이 주어 졌을 때 1,2,3 의 합으로 나타내는 방법의 수를 구하는 프로그램 
int DP[11] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// 첫줄에 테스트 케이스의 개수
	int count = 0;
	std::cin >> count;
	
	// 1을 구하는 방식 + 1 한가지
	DP[1] = 1;
	// 2를 구하는 방식 1 + 1 , + 2 두가지 
	DP[2] = 2;
	// 3을 구하는 방식 1 + 1 + 1 , 1 + 2, 2 + 1, +3 
	DP[3] = 4;

	// 그러면 
	// DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1] 이 된다. 
	for (size_t i = 4; i <= 10; ++i)
	{
		DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
	}
	
	// 입력을받는다.
	std::vector<int> Values = std::vector<int>();
	Values.resize(count);

	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cin >> Values[i];
	}
	
	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cout << DP[Values[i]] << "\n";
	}

	return 0;
}