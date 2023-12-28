#include <iostream>
#include <vector>
#include <set>

int Arr[1000000] = {};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	// 입력받고 
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
	
	// 반복돌아. 근데. 비교하는거 생각하기 귀찮으니까 그냥 set에다가 길이 다저장해두고 제일 앞에꺼 출력할거야. 
	std::set<int> values;
	while (Start <= End && End < N)
	{
		if (Sum < S)
		{
			Sum += Arr[++End];
		}
		else
		{
			// Sum이 S보다 크거나 같으면 set 자료구조에 추가.
			values.insert(End - Start + 1);

			// 현재 start idx 값을 빼주고, idx++ 
			Sum -= Arr[Start];
			++Start;
		}
	}
	
	std::cout << *(values.begin());

	return 0;
}