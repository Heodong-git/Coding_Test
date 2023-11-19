#include <iostream>
#include <vector>

int Function(int _Value)
{
	int result = 0;

	


	return result;
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	// 정수 n 이 주어 졌을 때 1,2,3 의 합으로 나타내는 방법의 수를 구하는 프로그램 
	
	// 첫줄에 테스트 케이스의 개수
	int count = 0;
	std::cin >> count;
	
	std::vector<int> values = std::vector<int>();
	values.resize(count);
	for (size_t i = 0; i < values.size(); i++)
	{
		std::cin >> values[i];
	}
	
	for (size_t i = 0; i < values.size(); i++)
	{
		int result = Function(values[i]);
		std::cout << result;
	}

	return 0;
}