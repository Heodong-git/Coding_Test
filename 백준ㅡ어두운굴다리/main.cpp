#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// 굴다리의 길이 N이 주어진다.
	int len = 0;
	std::cin >> len;

	std::vector<int> Road = std::vector<int>();
	Road.resize(len + 1);
	for (size_t i = 0; i < Road.size(); i++)
	{
		Road[i] = i;
	}

	// 가로등의 개수 M 이 주어진다.
	int count = 0;
	std::cin >> count;

	// 설치할 수 있는 M 개의 가로등의 위치가 주어진다.
	// 위치는 오름차순으로 입력받으며 중복 X, 정수 
	std::vector<int> Positions = std::vector<int>();
	Positions.resize(count);
	for (size_t i = 0; i < Positions.size(); i++)
	{
		std::cin >> Positions[i];
	}

	// 여기부터 주석 
	int max = 0;
	// 첫번째 포지션의 값이 max가 된다. 
	max = Positions[0];
	for (size_t i = 0; i < Positions.size() - 1; i++)
	{
		float temp = 0;
		temp = ceil((static_cast<float>(Positions[i + 1]) - static_cast<float>(Positions[i])) / 2.0f);
		if (max < temp)
		{
			max = temp;
		}
	}
	
	// 마지막 가로등에서부터 최종 위치까지의 거리를 구한다.
	int last = Road[Road.size() - 1] - Positions[Positions.size() - 1];
	if (max < last)
	{
		max = last;
	}
	
	std::cout << max;

	return 0;
}