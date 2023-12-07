#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> v(N);
	for (size_t i = 0; i < v.size(); i++)
	{
		int value;
		std::cin >> value;
		v[i] = (value);
	}
	
	int Find;
	std::cin >> Find;
	int Count = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (Find == v[i])
		{
			++Count;
		}
	}

	std::cout << Count;

	return 0;
}