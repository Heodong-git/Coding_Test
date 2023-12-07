#include <iostream>
#include <vector>
#include <algorithm>


// �ߺ����� ���� M�� �߿�, n���� �̴� ����� �� ������ �߿����� ���� - ���� 

int T;
int R, N;
 
int DP[30][30] = {};

int Combination(int _N, int _R)
{
	// ���� R �� 0�̶�� ����� ���� 1�� �ȴ�.
	// �Ǵ� N�� R �� ���ٸ� ����� ���� 1 �̵ȴ�.
	//if (_R == 0 || _N == _R)
	//{
	//	return 1;
	//}
	//// �װ� �ƴ϶�� ���� �״�� ���
	//// nCr = n-1Cr-1 + n-1Cr 
	//else
	//{
	//	return Combination(_N - 1, _R - 1) + Combination(_N - 1, _R);
	//}

	return DP[_N][_R];
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
	// i ���� 0�� �̴� ����� ���� 1�̱� ������ ���� 1 ����
	for (int i = 1; i <= 29; i++)
	{
		DP[i][0] = 1;
	}

	// ���������� i ���� 1�� �̴� ����� ���� i �� �̱� ������ ���� i ����
	for (int i = 1; i <= 29; i++)
	{
		DP[i][1] = i;
	}
	
	// �ݺ����鼭 �׳� ���� �־ ������ 
	for (int N = 1; N <= 29; N++)
	{
		for (int R = 2; R <= 29; R++)
		{
			DP[N][R] = DP[N - 1][R - 1] + DP[N - 1][R];
		}
	}

	// ���� �����س��� ����
	std::vector<int> Values = {};

	std::cin >> T;
	Values.resize(T);
	for (int i = 0; i < T; ++i)
	{
		std::cin >> R >> N;
		Values[i] =  Combination(N, R);
	}
	
	// �����س��� �� ���
	for (size_t i = 0; i < Values.size(); i++)
	{
		std::cout << Values[i] << std::endl;
	}


	return 0;
}