#include <iostream>
#include <vector>
#include <set>


int Function(int _Value)
{
	int result = 0;
	
	// set�� ��� ���� : std::vector<std::vector<int>> �� ����ص� ������
	// set �� �ߺ����� ����ó���� ���ֱ� ������ ���. 
	std::vector<std::set<int>> CalCounts = std::vector<std::set<int>>();
	CalCounts.resize(100);

	int Target = _Value;
	int Count = 1;

	for (int i = 1; i <= Target; i++)
	{
		// Ÿ�� ������ 3�� ������ 0���� ������ �������ٸ� �� ���� �����Ѵ�. 
		if (Target % 3 == 0) 
		{
			CalCounts[i].insert(Target / 3);
		}

		if (Target % 2 == 0)
		{
			CalCounts[i].insert(Target / 2);
		}

		CalCounts[i].insert(Target - 1);
		
		std::set<int>::iterator StartIter = CalCounts[i].begin();
		std::set<int>::iterator EndIter = CalCounts[i].end();
		for (; StartIter != EndIter; ++StartIter)
		{
			int Value = *StartIter;
			if()
		}

		++Count;
	}

	return result;
}


int main()
{
	int Value = 0;
	std::cin >> Value;

	int result = Function(Value);
	std::cout << result;

	return 0;
}