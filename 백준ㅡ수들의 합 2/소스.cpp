#include <iostream>
#include <vector>

std::vector<int> Values;

int main()
{	
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// N ���� ���� �̷���� ����
	// M �� ������ ����� ���� ���Ѵ�. 
	int N, M;
	std::cin >> N >> M;
	
	Values.reserve(10000);
	for (int i = 0; i < N; i++)
	{
		int Value;
		std::cin >> Value;
		Values.push_back(Value);
	}

	int a = 0;

	// ������ 2��, ���۰� ���� �� �� �ֵ��� ����
	// ������ �Ѵ� 0, �׻� ���� <= �� �� �����ؾ� �Ѵ�. 

	int Start = 0;
	int End = 0;

	// ���� ������� 0���ε����� �ִ� ���̰� 
	int Sum = Values[0];
	int Count = 0;

	// End�� �����ǰ������� �۴ٸ� ����ؼ� �ݺ� 
	while (End < N)
	{
		// ������ ���� ã���� �ϴ� ������ �۴ٸ� 
		if (Sum < M)
		{
			// ���� �ε����� ������Ű��, ����üũ���ؼ� �ش� �ε�����°�� ���� �����ش�. 
			++End;
			if (End < N)
			{
				Sum += Values[End];
			}
		}

		// ������ ���� ã���� �ϴ� ������ ũ�ٸ� 
		else if (Sum > M)
		{
			// Start �ε��� ��°�� ���� Sum�� ������ ���ְ�, Start �ε����� ������Ų��. 
			Sum -= Values[Start];
			++Start;
		}

		// ������� ���ٸ� 
		else if (Sum == M)
		{
			// ���ϴ� ���� ���Ա� ������ ī��Ʈ ���ش�. 
			++Count;

			// ������� ���Ա� ������ �� ���¿��� Start,End �� ��ġ�� ������� �̵����ѵ� ���ϴ� ���� ������ �ʱ� ������
			// Start ���� ���ְ�, �Ѵ� ++ 
			Sum -= Values[Start];
			++Start;
			++End;

			// ���� End �� N���� �۴ٸ� ���� �߰����ְ� ��ӹݺ�
			if (End < N)
			{
				Sum += Values[End];
			}
		}
	}
	
	// ����� 
	std::cout << Count;

	return 0;
}