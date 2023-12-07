#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// ���� ����
// nPr �̰� n���� �ߺ����� �ʴ� �� �� r���� �̴� ����� �� �ε� ������ ����� �ִ�. 

// next_permutation  �������� �迭 ���
// prev_permutation  �������� �迭 ���

// next_permutation([first, last))
//- first : ������ ������ ������ ù��° �ּ�
//- last : ���Ե��� ���� ������ �ּ�

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, R;
	std::cin >> N >> R;

	std::vector<int> vValues = {};
	vValues.resize(N);

	// set ���� ������ ��
	std::set<int> sValues;

	for (size_t i = 0; i < N; i++)
	{
		int Value;
		std::cin >> Value;
		vValues[i] = Value;
	}

	// �������� ���� 
	std::sort(vValues.begin(), vValues.end());

	// N ���� �ڿ����� �ڿ��� M�� �־����� �� N ���� �ڿ��� �߿��� M���� �� ����
	// ex) n C r 
	// �ߺ����ɸ���? 

	// 3 2
	// 4 4 2 �� ���
	// 2 4 4 
	// 4 2 4
	std::set<std::vector<int>> temp;
	do
	{
		// �迭�� ���� ���� ��ŭ�� resize 
		std::vector<int> v;
		v.resize(R);
		for (size_t i = 0; i < v.size(); i++)
		{
			v[i] = vValues[i];
		}

		temp.insert(v);
		
	} while (std::next_permutation(vValues.begin(), vValues.end()));

	// ���⼭ ���
	std::set<std::vector<int>>::iterator StartIter = temp.begin();
	std::set<std::vector<int>>::iterator EndIter = temp.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		std::vector<int> v = *StartIter;
		for (size_t i = 0; i < v.size(); ++i)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}