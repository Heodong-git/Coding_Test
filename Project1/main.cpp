#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// �ڿ��� N �� �־�����. 
	int N = 0;
	std::cin >> N;
	if ((1 > N || 100000 < N))
	{
		assert(false);
	}

	// �����ٿ��� N���� ������ �־�����.
	std::vector<int> N_Values = std::vector<int>();
	N_Values.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> N_Values[i];
		if ((N_Values[i] < pow(-2, 31)) || N_Values[i] >= pow(2, 31))
		{
			assert(false);
		}

	}

	// �����ٿ��� M�� �־�����. 
	int M = 0;
	std::cin >> M;
	if ((1 > M || 100000 < M))
	{
		assert(false);
	}

	// �����ٿ��� M���� ���� �־�����.
	std::vector<int> M_Values = std::vector<int>();
	M_Values.resize(M);

	for (int i = 0; i < M; i++)
	{
		std::cin >> M_Values[i];
		if ((M_Values[i] < pow(-2, 31)) || M_Values[i] >= pow(2, 31))
		{
			assert(false);
		}
	}

	// M ���Ϳ� ����Ǿ��ִ� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�.
	// ���� ���� 
	std::sort(N_Values.begin(), N_Values.end());

	// �ڷᱸ���� ��ȸ�ϸ� ����Ž�� 
	for (size_t i = 0; i < M_Values.size(); i++)
	{
		// 0���ε��� 
		int lt = 0;
		// ������ �ε��� 
		int rt = static_cast<int>(N_Values.size() - 1);
		bool Check = false;

		// �������ε��� ���� �Ѿ�� ���� �ݺ� 
		while (lt <= rt)
		{
			// �̵� �ε��� �� 
			int mid = (lt + rt) / 2;

			// ���� �����ϴٸ� 1 ���, Check ���� true �� ���� �� break �� �ݺ����� ����������.
			if (N_Values[mid] == M_Values[i])
			{
				std::cout << 1 << "\n";
				Check = true;
				break;
			}

			// ���� mid �ε��� ��°�� ���� ���� ã���� �ϴ� ������ �۴ٸ� 
			// �����ε������� ���� mid �� + 1 �� ����
			else if (N_Values[mid] < M_Values[i])
			{
				lt = mid + 1;
			}

			else if (N_Values[mid] > M_Values[i])
			{
				rt = mid - 1;
			}
		}

		// Check ������ false ��� 
		// ���� ã�� ���� ���̴�. 0 ��� 
		if (false == Check)
		{
			std::cout << 0 << "\n";
		}
	}


	// std::binary_search �� Ȱ���� Ǯ��
	/*std::sort(N_Values.begin(), N_Values.end());
	for (size_t i = 0; i < M_Values.size(); i++)
	{
		bool Check = std::binary_search(N_Values.begin(), N_Values.end(), M_Values[i]);
		std::cout << Check << "\n";
	}*/

	return 0;
}