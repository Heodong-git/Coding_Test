#include <iostream>
#include <vector>
#include <set>

int Arr[1000000] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// �Է¹ް� 
	int N;
	int S;
	std::cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int Value;
		std::cin >> Value;
		Arr[i] = Value;
	}

	int Start = 0;
	int End = 0;
	int Sum = Arr[0];
	int len = 0;
	
	// �ݺ�����. �ٵ�. ���ϴ°� �����ϱ� �������ϱ� �׳� set���ٰ� ���� �������صΰ� ���� �տ��� ����Ұž�. 
	std::set<int> values;
	while (Start <= End && End < N)
	{
		if (Sum < S)
		{
			Sum += Arr[++End];
		}
		else
		{
			// Sum�� S���� ũ�ų� ������ set �ڷᱸ���� �߰�.
			values.insert(End - Start + 1);

			// ���� start idx ���� ���ְ�, idx++ 
			Sum -= Arr[Start];
			++Start;
		}
	}
	
	std::cout << *(values.begin());

	return 0;
}