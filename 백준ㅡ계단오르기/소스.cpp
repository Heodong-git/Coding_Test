#include <iostream>
#include <vector>

// 계단의 최대 점수를 저장할 배열 
int DP[10000] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// 첫째줄에 계단의 개수가 주어진다.
	int count = 0;
	std::cin >> count;

	// 둘째줄부터 제일 아래에 놓인 계단부터 쓰여있는 점수가 주어진다.
	std::vector<int> Scores = std::vector<int>();
	Scores.reserve(10000);
	
	// 0번째 인덱스를 0점으로 넣어주고
	Scores.push_back(0);

	// 1번계단부터 점수를 넣어준다. 
	for (size_t i = 0; i < count; i++)
	{
		int value = 0;
		std::cin >> value;
		Scores.push_back(value);
	}

	// 초기 1,2,3번째 계단의 최대 점수를 추가해준다. 
	DP[0] = 0;
	DP[1] = Scores[1];
	DP[2] = Scores[1] + Scores[2];

	// DP 의 값들을 저장해준다. 
	// DP[i] = 해당하는 번째의 계단에 도달했을 때 얻을 수 있는 최대 점수를 저장
	for (size_t i = 3; i <= count; i++)
	{
		// 현재 계단의 전전 계단의 최대점수 + 현재계단의 점수가 얻을 수 있는 점수의 최대값 
		int value = DP[i] = DP[i - 2] + Scores[i];
		// 현재 계단의 전전전 계단의 최대점수 + 나의 전계단의 점수 + 현재 계단의 점수가 얻을 수 있는 점수의 최대값이다. 
		int value2 = DP[i] = DP[i - 3] + Scores[i - 1] + Scores[i];
		// 둘중 비교해서 총 합점수가 더 큰 값이 DP[i] 가 된다.
		DP[i] = std::max(value, value2);
	}
 
	std::cout << DP[count];
	
	return 0;
}