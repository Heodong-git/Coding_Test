#include <iostream>
#include <vector>


// 사료 21 기준 , 다음날 필요한 사료는 84 첫날엔 가능하지만 둘째날엔 84의 사료가필요하기 때문에 안됨. 2출력
// 1번돼지 1 + 6 + 2 + 4 = 13
// 2번돼지 2 + 1 + 3 + 5 = 11
// 3번돼지 3 + 2 + 4 + 6 = 15
// 4번돼지 4 + 3 + 5 + 1 = 13
// 5번돼지 5 + 4 + 6 + 2 = 17
// 6번돼지 6 + 5 + 1 + 3 = 15


// 첫날부터 사료가 22가 필요함, 첫날부터 만족이 안됨 1출력 둘째날엔 88 사료가 필요함 다음날엔 이전에 먹은날의 사료의 4배가 필요해 
// 1번돼지 1 + 7 + 2 + 4 = 14
// 2번돼지 2 + 1 + 3 + 5 = 11
// 3번돼지 3 + 2 + 4 + 7 = 16
// 4번돼지 4 + 3 + 5 + 1 = 13
// 5번돼지 5 + 4 + 7 + 2 = 18
// 6번돼지 7 + 5 + 1 + 3 = 16


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;

	// 결과값 저장용 
	std::vector<int> results;

	// 테스트는 T번 진행할거고
	for (int i = 0; i < T; i++)
	{
		std::vector<int> values;
		values.reserve(6);

		// 하루에 지급되는 사료의 양
		int Food;
		std::cin >> Food;

		int OriginFood = Food;

		// 필요음식의양 
		int AllFood = 0;

		// 필요한 사료의 량을 입력받고, 첫날 필요한 사료의 양을 저장해둔다. = AllFood  
		for (int i = 0; i < 6; i++)
		{
			int value;
			std::cin >> value;
			AllFood += value;
			values.push_back(value);
		}
		
		// 날짜 
		int date = 1;

		// 지급되는 사료가 각날짜에 필요한 양보다 많다면 반복 수행 가능
		while (Food >= AllFood)
		{
			// 다음날 필요한 음식의 양은 4배가 늘어나기 때문에 곱해주고
			AllFood *= 4;
			Food = OriginFood;
			++date;
		}

		// 반복문을 빠져나왔으면 날짜 저장
		results.push_back(date);
	}
	
	// 답출력 
	for (size_t i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << "\n";
	}


	return 0;
}