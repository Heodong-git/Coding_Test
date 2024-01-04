#include <iostream>


int solution(int _N)
{
	int battery = 0;

	// �����̵� : ���±��� �� �Ÿ��� x2 ��ġ�� �̵�
	// ���� : n ��ŭ �̵�, �� ���͸��� n ��ŭ �Ҹ���
	// ���͸��� �ּ�ȭ �Ͽ� �������� ���� �� �� �ִ� ����� �������� ���� ���� 0�� �� �� ���� ��� 2�� �����ְ�, 
	// ����������� ���� �� ���� -1 ���ְ�, ���͸� ��뷮�� ++ �Ͽ� �������ָ� �ȴ�.

	int N = _N;
	
	// N �� 0���� ũ�ٸ� �ݺ��Ѵ�. 
	while (N > 0)
	{
		// ���� ���� ¦����� 
		if (N % 2 == 0)
		{
			N /= 2;
		}
		
		// ���� ���� Ȧ����� 
		else if (N % 2 != 0)
		{
			// ���͸� ���� ++ 
			++battery;
			N -= 1;
			N /= 2;
		}

	}

	return battery;
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int len;
	std::cin >> len;

	int result = solution(len);

	std::cout << result;

	return 0;
}