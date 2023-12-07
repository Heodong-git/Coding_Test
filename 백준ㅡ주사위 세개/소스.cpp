#include <iostream>
#include <queue>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int A, B, C;
	std::cin >> A >> B >> C;
	
	// 세개가 모두 같다면 
	if (A == B && A == C)
	{
		std::cout << 10000 + A * 1000 << std::endl;
		return 0;
	}
	
	// 두개만 같다면 
	if (A == B || A == C)
	{
		std::cout << 1000 + A * 100 << std::endl;
		return 0;
	}

	if (A == B || B == C)
	{
		std::cout << 1000 + B * 100 << std::endl;
		return 0;
	}

	if (A != B && B != C)
	{
		std::priority_queue<int> q;
		q.push(A);
		q.push(B);
		q.push(C);

		std::cout << q.top() * 100 << std::endl;		
		return 0;
	}



	return 0;
}