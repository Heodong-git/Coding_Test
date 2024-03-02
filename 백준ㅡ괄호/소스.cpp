#include <iostream>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int Loop;
	std::cin >> Loop;
	
	for (int i = 0; i < Loop; i++)
	{
		std::queue<char> q;
		std::string Str;
		std::cin >> Str;
		bool check = true;

		if (')' == Str[0])
		{
			std::cout << "NO" << std::endl;
			continue;
		}

		for (int i = 0; i < static_cast<int>(Str.size()); i++)
		{
			if ('(' == Str[i])
			{
				q.push(Str[i]);
			}

			else if (')' == Str[i])
			{
				if (true == q.empty())
				{
					check = false;
					break;
				}
				q.pop();
			}
		}
		
		if (false == check || false == q.empty())
		{
			std::cout << "NO" << std::endl;
		}

		else if (true == check)
		{
			std::cout << "YES" << std::endl;
		}
	}

	return 0;
}