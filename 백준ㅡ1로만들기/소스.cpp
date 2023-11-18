#include <iostream>
#include <vector>

int DP[1000000] = {};

int Function(int _Value)
{
	int result = 0;

	// DP[i] 번째에는 DP[i] 를 1로 연산하기 위한 최소 연산횟수가 저장되어 있다.
	// 1이 되기위한 최소 연산횟수는 0이기 때문에 2 부터 시작
	for (size_t i = 2; i <= _Value; i++)
	{
		// DP[i] 의 최소 연산 횟수는 DP[i-1] 의 최소 연산횟수 + 1 이다.
		DP[i] = DP[i - 1] + 1;

		// 만약 i 의 값이 2로 나누어 떨어진다면
		if (i % 2 == 0)
		{
			// 현재 나의 연산 횟수와 DP[i / 2] + 1 의 연산 횟수를 비교하여 
			// 더 적은 연산횟수를 가진 값이 DP[i] 가 된다. 

			// 비교대상이 / 2 + 1 인 이유는
			// 나누기 2한 값의 연산횟수 + 1 이 의 연산횟수가 
			// 현재 저장된 값보다 작다면 연산횟수를 갱신하기 위해서이다. .. 맞..지? 
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		}

		// 만약 i 의 값이 3으로 나누어 떨어진다면 
		if (i % 3 == 0)
		{
			// 마찬가지로 DP[i] 의 연산횟수와 DP[i / 3] + 1 의 연산 횟수를 비교하여 
			// 더 적은 연산횟수를 가진 값이 DP[i]가 된다. 
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
		}
	}
	
	// DP[_Value] 에 연산횟수가 저장되어 있기 때문에 해당 값을 반환한다. 
	result = DP[_Value];

	return result;
}


int main()
{
	int Value = 0;
	std::cin >> Value;

	int result = Function(Value);
	std::cout << result;

	return 0;
}