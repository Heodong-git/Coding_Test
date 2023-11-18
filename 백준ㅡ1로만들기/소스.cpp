#include <iostream>
#include <vector>
#include <set>


int Function(int _Value)
{
	int result = 0;
	
	// set의 사용 이유 : std::vector<std::vector<int>> 를 사용해도 되지만
	// set 은 중복값의 예외처리를 해주기 때문에 사용. 
	std::vector<std::set<int>> CalCounts = std::vector<std::set<int>>();
	CalCounts.resize(100);

	int Target = _Value;
	int Count = 1;

	for (int i = 1; i <= Target; i++)
	{
		// 타겟 나머지 3을 했을때 0으로 나누어 떨어진다면 그 값을 저장한다. 
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