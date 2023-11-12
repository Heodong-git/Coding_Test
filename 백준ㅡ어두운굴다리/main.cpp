#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// ���ٸ��� ���� N�� �־�����.
	int len = 0;
	std::cin >> len;

	std::vector<int> Road = std::vector<int>();
	Road.resize(len + 1);
	for (size_t i = 0; i < Road.size(); i++)
	{
		Road[i] = i;
	}

	// ���ε��� ���� M �� �־�����.
	int count = 0;
	std::cin >> count;

	// ��ġ�� �� �ִ� M ���� ���ε��� ��ġ�� �־�����.
	// ��ġ�� ������������ �Է¹����� �ߺ� X, ���� 
	std::vector<int> Positions = std::vector<int>();
	Positions.resize(count);
	for (size_t i = 0; i < Positions.size(); i++)
	{
		std::cin >> Positions[i];
	}

	// ������� �ּ� 
	int max = 0;
	// ù��° �������� ���� max�� �ȴ�. 
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
	
	// ������ ���ε������ ���� ��ġ������ �Ÿ��� ���Ѵ�.
	int last = Road[Road.size() - 1] - Positions[Positions.size() - 1];
	if (max < last)
	{
		max = last;
	}
	
	std::cout << max;

	return 0;
}