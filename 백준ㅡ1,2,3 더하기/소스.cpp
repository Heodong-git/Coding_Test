#include <iostream>
#include <vector>

// ���� n �� �־� ���� �� 1,2,3 �� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷� 
int DP[11] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// ù�ٿ� �׽�Ʈ ���̽��� ����
	int count = 0;
	std::cin >> count;
	
	// 1�� ���ϴ� ��� + 1 �Ѱ���
	DP[1] = 1;
	// 2�� ���ϴ� ��� 1 + 1 , + 2 �ΰ��� 
	DP[2] = 2;
	// 3�� ���ϴ� ��� 1 + 1 + 1 , 1 + 2, 2 + 1, +3 
	DP[3] = 4;

	// �׷��� 
	// DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1] �� �ȴ�. 
	for (size_t i = 4; i <= 10; ++i)
	{
		DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
	}
	
	// �Է����޴´�.
	std::vector<int> Values = std::vector<int>();
	Values.resize(count);

	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cin >> Values[i];
	}
	
	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cout << DP[Values[i]] << "\n";
	}

	return 0;
}