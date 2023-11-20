#include <iostream>
#include <vector>

// ����� �ִ� ������ ������ �迭 
int DP[10000] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// ù°�ٿ� ����� ������ �־�����.
	int count = 0;
	std::cin >> count;

	// ��°�ٺ��� ���� �Ʒ��� ���� ��ܺ��� �����ִ� ������ �־�����.
	std::vector<int> Scores = std::vector<int>();
	Scores.reserve(10000);
	
	// 0��° �ε����� 0������ �־��ְ�
	Scores.push_back(0);

	// 1����ܺ��� ������ �־��ش�. 
	for (size_t i = 0; i < count; i++)
	{
		int value = 0;
		std::cin >> value;
		Scores.push_back(value);
	}

	// �ʱ� 1,2,3��° ����� �ִ� ������ �߰����ش�. 
	DP[0] = 0;
	DP[1] = Scores[1];
	DP[2] = Scores[1] + Scores[2];

	// DP �� ������ �������ش�. 
	// DP[i] = �ش��ϴ� ��°�� ��ܿ� �������� �� ���� �� �ִ� �ִ� ������ ����
	for (size_t i = 3; i <= count; i++)
	{
		// ���� ����� ���� ����� �ִ����� + �������� ������ ���� �� �ִ� ������ �ִ밪 
		int value = DP[i] = DP[i - 2] + Scores[i];
		// ���� ����� ������ ����� �ִ����� + ���� ������� ���� + ���� ����� ������ ���� �� �ִ� ������ �ִ밪�̴�. 
		int value2 = DP[i] = DP[i - 3] + Scores[i - 1] + Scores[i];
		// ���� ���ؼ� �� �������� �� ū ���� DP[i] �� �ȴ�.
		DP[i] = std::max(value, value2);
	}
 
	std::cout << DP[count];
	
	return 0;
}