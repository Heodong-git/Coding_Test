#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// ���ٸ��� ���� N�� �־�����.
	int len = 0;
	std::cin >> len;
	
	std::vector<bool> Road = std::vector<bool>();
	Road.resize(len + 1);
	for (size_t i = 0; i < Road.size(); i++)
	{
		Road[i] = false;
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
		// ���ε� ��ġ 
		Road[Positions[i]] = true;
	}

	// �̰����ʿ䰡�ֳ�? 

	// �ϴ� ���� ������ ��ġ�� ���ε��� ��ġ������ �������� �ֳ� ������ ��Ȳ�� üũ���� 
	for (size_t i = 0; i < Road.size(); i++)
	{
		std::vector<bool> TempRoad = Road;
		int lt = 0;
		int rt = Road.size() - 1;
		int mid = lt + rt / 2;
		int height = 0;

		while (lt <= rt)
		{
			// �ݺ� ó�� �����Ҷ� ���� ���ε��� ��ġ�� üũ�Ͽ� 
			// ���̰� ���� �ʿ����� ���Ѵ�. 
			if(TempRoad[])
		}
		
	}

	return 0;
}