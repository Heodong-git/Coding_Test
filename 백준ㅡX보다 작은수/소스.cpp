#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, X;
	std::cin >> N >> X;
	std::vector<int> v;
	v.resize(N);
	for (size_t i = 0; i < v.size(); i++)
	{
		int value;
		std::cin >> value;
		v[i] = value;
	}
	
	for (size_t i = 0; i < v.size(); i++)
	{
		if (X > v[i])
		{
			std::cout << v[i] << " ";
		}
	}
	

	return 0;
}