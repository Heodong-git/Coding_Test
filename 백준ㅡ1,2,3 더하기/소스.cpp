#include <iostream>
#include <vector>

void Function(int _Value)
{
	int result = 0;

	// ���� 2�� �־��ٸ�
	// 1,2,3 �� ������ ��Ÿ���� ����� 1���̴�. 
	// 1 + 1

	// 3�� ���
	// 1 + 1 + 1
	// 1 + 2
	// 2 + 1



	std::cout << result;
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	// ���� n �� �־� ���� �� 1,2,3 �� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷� 
	
	// ù�ٿ� �׽�Ʈ ���̽��� ����
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
		Function(values[i]);
	}

	return 0;
}