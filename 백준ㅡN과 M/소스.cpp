#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// 순열 문제
// nPr 이고 n개의 중복되지 않는 값 중 r개를 뽑는 경우의 수 인데 순서가 상관이 있다. 

// next_permutation  오름차순 배열 기반
// prev_permutation  내림차순 배열 기반

// next_permutation([first, last))
//- first : 순열을 시작할 범위의 첫번째 주소
//- last : 포함되지 않은 마지막 주소

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, R;
	std::cin >> N >> R;

	std::vector<int> vValues = {};
	vValues.resize(N);

	// set 에도 저장을 해
	std::set<int> sValues;

	for (size_t i = 0; i < N; i++)
	{
		int Value;
		std::cin >> Value;
		vValues[i] = Value;
	}

	// 오름차순 정렬 
	std::sort(vValues.begin(), vValues.end());

	// N 개의 자연수와 자연수 M이 주어졌을 때 N 개의 자연수 중에서 M개를 고른 수열
	// ex) n C r 
	// 중복어케막냐? 

	// 3 2
	// 4 4 2 의 경우
	// 2 4 4 
	// 4 2 4
	std::set<std::vector<int>> temp;
	do
	{
		// 배열을 뽑을 개수 만큼만 resize 
		std::vector<int> v;
		v.resize(R);
		for (size_t i = 0; i < v.size(); i++)
		{
			v[i] = vValues[i];
		}

		temp.insert(v);
		
	} while (std::next_permutation(vValues.begin(), vValues.end()));

	// 여기서 출력
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