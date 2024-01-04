#include <iostream>
#include <vector>


// ��� 21 ���� , ������ �ʿ��� ���� 84 ù���� ���������� ��°���� 84�� ��ᰡ�ʿ��ϱ� ������ �ȵ�. 2���
// 1������ 1 + 6 + 2 + 4 = 13
// 2������ 2 + 1 + 3 + 5 = 11
// 3������ 3 + 2 + 4 + 6 = 15
// 4������ 4 + 3 + 5 + 1 = 13
// 5������ 5 + 4 + 6 + 2 = 17
// 6������ 6 + 5 + 1 + 3 = 15


// ù������ ��ᰡ 22�� �ʿ���, ù������ ������ �ȵ� 1��� ��°���� 88 ��ᰡ �ʿ��� �������� ������ �������� ����� 4�谡 �ʿ��� 
// 1������ 1 + 7 + 2 + 4 = 14
// 2������ 2 + 1 + 3 + 5 = 11
// 3������ 3 + 2 + 4 + 7 = 16
// 4������ 4 + 3 + 5 + 1 = 13
// 5������ 5 + 4 + 7 + 2 = 18
// 6������ 7 + 5 + 1 + 3 = 16


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int T;
	std::cin >> T;

	// ����� ����� 
	std::vector<int> results;

	// �׽�Ʈ�� T�� �����ҰŰ�
	for (int i = 0; i < T; i++)
	{
		std::vector<int> values;
		values.reserve(6);

		// �Ϸ翡 ���޵Ǵ� ����� ��
		int Food;
		std::cin >> Food;

		int OriginFood = Food;

		// �ʿ������Ǿ� 
		int AllFood = 0;

		// �ʿ��� ����� ���� �Է¹ް�, ù�� �ʿ��� ����� ���� �����صд�. = AllFood  
		for (int i = 0; i < 6; i++)
		{
			int value;
			std::cin >> value;
			AllFood += value;
			values.push_back(value);
		}
		
		// ��¥ 
		int date = 1;

		// ���޵Ǵ� ��ᰡ ����¥�� �ʿ��� �纸�� ���ٸ� �ݺ� ���� ����
		while (Food >= AllFood)
		{
			// ������ �ʿ��� ������ ���� 4�谡 �þ�� ������ �����ְ�
			AllFood *= 4;
			Food = OriginFood;
			++date;
		}

		// �ݺ����� ������������ ��¥ ����
		results.push_back(date);
	}
	
	// ����� 
	for (size_t i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << "\n";
	}


	return 0;
}