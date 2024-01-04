#include <iostream>


int solution(int _N)
{
	int battery = 0;

	// 순간이동 : 여태까지 온 거리의 x2 위치로 이동
	// 점프 : n 만큼 이동, 단 배터리를 n 만큼 소모함
	// 배터리를 최소화 하여 목적지에 도달 할 수 있는 방법은 목적지로 들어온 값을 0이 될 때 까지 계속 2로 나눠주고, 
	// 나누어떨어지지 않을 때 마다 -1 해주고, 배터리 사용량을 ++ 하여 갱신해주면 된다.

	int N = _N;
	
	// N 이 0보다 크다면 반복한다. 
	while (N > 0)
	{
		// 나눈 값이 짝수라면 
		if (N % 2 == 0)
		{
			N /= 2;
		}
		
		// 나눈 값이 홀수라면 
		else if (N % 2 != 0)
		{
			// 배터리 값을 ++ 
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