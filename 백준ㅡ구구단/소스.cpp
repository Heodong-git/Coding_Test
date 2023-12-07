#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	for (int i = 1; i <= 9; i++)
	{
		std::cout << N << " * " << i << " = " << N * i << std::endl;
	}

	return 0;
}