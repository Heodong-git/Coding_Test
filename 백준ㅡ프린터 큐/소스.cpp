#include <iostream>
#include <queue>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int TestCase = 0;
	std::cin >> TestCase;
	
	std::vector<int> results;

	// ��� �����Ұ����� �׽�Ʈ���̽��ε� �Է����޾ƾ߰���?
	for (int i = 0; i < TestCase; i++)
	{
		int N = 0, M = 0;
		std::cin >> N >> M;

		// struct �� ���� ����Ϸ��ٰ� �񱳿����ڰ� ��� �׳� std::pair ���
		std::priority_queue<std::pair<int, int>> pqueDocuments;
		std::queue<std::pair<int, int>> queDocuments;

		

		// N�� ������ �߿䵵�� ���ʴ�� �־�����. 1 ~ 9 
		for (size_t i = 0; i < N; i++)
		{
			int Imp;
			std::cin >> Imp;

			std::pair<int, int> Newpair;
			// �߿䵵  
			Newpair.first = Imp;
			// �ε��� 
			Newpair.second = static_cast<int>(i);
			queDocuments.push(Newpair);
			pqueDocuments.push(Newpair);
		}

		std::pair<int, int> test = queDocuments.front();
		std::pair<int, int> test2 = pqueDocuments.top();

		// �����Ͱ� ��µ� Ƚ�� 
		int count = 0;

		// �׸��� �ݺ�����
		while (queDocuments.empty() == false)
		{
			// ť�� �������� �ݺ����� 

			// ť���� ������ ����
			std::pair<int, int> queData = queDocuments.front();
			std::pair<int, int> pqueData = pqueDocuments.top();

			// ž�� �����Ϳ� ���� ť�� front �������� �߿䵵�� ���ٸ�
			// ���絥���Ͱ� �߿䵵�� ���� ���� �Ŵϱ�
			if (queData.first == pqueData.first)
			{
				// �����͸� ť���� ����� 
				queDocuments.pop();
				pqueDocuments.pop();

				// �����Ͱ� ��� �ɰű� ������ 
				++count;

				// ����, �ε����� ���ٸ� count ����ϰ� break;
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