#include <iostream>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// 첫째줄에 아이들의 수 N 과 색상의 수 M이 주어진다.
	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	// 각 색상의 개수를 입력받는다.
	// 질투심 : 가장 많은 보석을 가진 학생의 보석수
	std::vector<int> Values = std::vector<int>();
	Values.resize(M);
	for (size_t i = 0; i < Values.size(); i++)
	{
		// 개수를 입력받는다. 
		std::cin >> Values[i];
	}
	
	// 아이들이 만약에 5명이야 그러면 
	for (size_t i = 0; i < Values.size(); i++)
	{
		int result = Values[i] / M;

		int a = 0;


	}
	


	int a = 0;


	return 0;
}