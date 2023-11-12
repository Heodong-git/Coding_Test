#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// 굴다리의 길이 N이 주어진다.
	int len = 0;
	std::cin >> len;
	
	std::vector<bool> Road = std::vector<bool>();
	Road.resize(len + 1);
	for (size_t i = 0; i < Road.size(); i++)
	{
		Road[i] = false;
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
		// 가로등 배치 
		Road[Positions[i]] = true;
	}

	// 이걸할필요가있나? 

	// 일단 내가 정해준 위치에 가로등을 배치했을때 지나갈수 있냐 없냐의 상황을 체크를해 
	for (size_t i = 0; i < Road.size(); i++)
	{
		std::vector<bool> TempRoad = Road;
		int lt = 0;
		int rt = Road.size() - 1;
		int mid = lt + rt / 2;
		int height = 0;

		while (lt <= rt)
		{
			// 반복 처음 시작할때 현재 가로등의 위치를 체크하여 
			// 높이가 몇이 필요한지 구한다. 
			if(TempRoad[])
		}
		
	}

	return 0;
}