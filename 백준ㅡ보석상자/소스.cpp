#include <iostream>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// ù°�ٿ� ���̵��� �� N �� ������ �� M�� �־�����.
	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	// �� ������ ������ �Է¹޴´�.
	// ������ : ���� ���� ������ ���� �л��� ������
	std::vector<int> Values = std::vector<int>();
	Values.resize(M);
	for (size_t i = 0; i < Values.size(); i++)
	{
		// ������ �Է¹޴´�. 
		std::cin >> Values[i];
	}
	
	// ���̵��� ���࿡ 5���̾� �׷��� 
	for (size_t i = 0; i < Values.size(); i++)
	{
		int result = Values[i] / M;

		int a = 0;


	}
	


	int a = 0;


	return 0;
}