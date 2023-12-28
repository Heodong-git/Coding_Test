#include <iostream>
#include <vector>

std::vector<int> Values;

int main()
{	
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	// N 개의 수로 이루어진 수열
	// M 이 나오는 경우의 수를 구한다. 
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

	// 포인터 2개, 시작과 끝을 알 수 있도록 구분
	// 시작은 둘다 0, 항상 시작 <= 끝 을 만족해야 한다. 

	int Start = 0;
	int End = 0;

	// 현재 결과값은 0번인덱스에 있는 값이고 
	int Sum = Values[0];
	int Count = 0;

	// End가 원소의개수보다 작다면 계속해서 반복 
	while (End < N)
	{
		// 원소의 합이 찾고자 하는 값보다 작다면 
		if (Sum < M)
		{
			// 뒤쪽 인덱스를 증가시키고, 조건체크를해서 해당 인덱스번째의 값을 더해준다. 
			++End;
			if (End < N)
			{
				Sum += Values[End];
			}
		}

		// 원소의 합이 찾고자 하는 값보다 크다면 
		else if (Sum > M)
		{
			// Start 인덱스 번째의 값을 Sum의 값에서 빼주고, Start 인덱스를 증가시킨다. 
			Sum -= Values[Start];
			++Start;
		}

		// 결과값이 같다면 
		else if (Sum == M)
		{
			// 원하는 값이 나왔기 때문에 카운트 해준다. 
			++Count;

			// 결과값이 나왔기 때문에 이 상태에서 Start,End 의 위치중 어느쪽을 이동시켜도 원하는 값이 나오지 않기 때문에
			// Start 값을 빼주고, 둘다 ++ 
			Sum -= Values[Start];
			++Start;
			++End;

			// 만약 End 가 N보다 작다면 값을 추가해주고 계속반복
			if (End < N)
			{
				Sum += Values[End];
			}
		}
	}
	
	// 값출력 
	std::cout << Count;

	return 0;
}