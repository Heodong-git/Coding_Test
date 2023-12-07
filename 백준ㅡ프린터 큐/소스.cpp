#include <iostream>
#include <queue>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int TestCase = 0;
	std::cin >> TestCase;
	
	std::vector<int> results;

	// 몇번 실행할건지가 테스트케이스인데 입력을받아야겠지?
	for (int i = 0; i < TestCase; i++)
	{
		int N = 0, M = 0;
		std::cin >> N >> M;

		// struct 로 만들어서 사용하려다가 비교연산자가 없어서 그냥 std::pair 사용
		std::priority_queue<std::pair<int, int>> pqueDocuments;
		std::queue<std::pair<int, int>> queDocuments;

		

		// N개 문서의 중요도가 차례대로 주어진다. 1 ~ 9 
		for (size_t i = 0; i < N; i++)
		{
			int Imp;
			std::cin >> Imp;

			std::pair<int, int> Newpair;
			// 중요도  
			Newpair.first = Imp;
			// 인덱스 
			Newpair.second = static_cast<int>(i);
			queDocuments.push(Newpair);
			pqueDocuments.push(Newpair);
		}

		std::pair<int, int> test = queDocuments.front();
		std::pair<int, int> test2 = pqueDocuments.top();

		// 데이터가 출력된 횟수 
		int count = 0;

		// 그리고 반복돌아
		while (queDocuments.empty() == false)
		{
			// 큐가 빌때까지 반복돌아 

			// 큐에서 데이터 꺼냄
			std::pair<int, int> queData = queDocuments.front();
			std::pair<int, int> pqueData = pqueDocuments.top();

			// 탑의 데이터와 현재 큐의 front 데이터의 중요도가 같다면
			// 현재데이터가 중요도가 가장 높은 거니까
			if (queData.first == pqueData.first)
			{
				// 데이터를 큐에서 지우고 
				queDocuments.pop();
				pqueDocuments.pop();

				// 데이터가 출력 될거기 때문에 
				++count;

				// 만약, 인덱스가 같다면 count 출력하고 break;
				if (queData.second == M)
				{
					results.push_back(count);
					break;
				}
			}
			else
			{
				queDocuments.pop();
				queDocuments.push(queData);
			}
		}

		for (size_t i = 0; i < queDocuments.size(); i++)
		{
			queDocuments.pop();
		}
		for (size_t i = 0; i < pqueDocuments.size(); i++)
		{
			pqueDocuments.pop();
		}
	}

	for (size_t i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << std::endl;
	}


	return 0;
}