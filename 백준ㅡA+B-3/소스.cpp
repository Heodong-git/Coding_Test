#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

	int Loop;
	std::cin >> Loop;

	for (int i = 0; i < Loop; i++)
	{
		int A, B;
		std::cin >> A >> B;

		std::cout << A + B << std::endl;
	}
	
	return 0;
}