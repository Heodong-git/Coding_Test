#include <list>
#include <vector>
#include <iostream>
int main()
{
	/*std::list<int> _list = std::list<int>();

	int value = 1;
	int value2 = 2;
	
	_list.push_back(value);
	_list.push_back(value2);
	
	std::list<int>::iterator Test1 = _list.begin();
	std::list<int>::iterator Test2 = _list.begin();

	_list.erase(Test2);

	int Ptr = *Test1;
	
	int a = 0;*/


	std::vector<int> _vector = std::vector<int>();

	int value = 1;
	//int value2 = 2;

	_vector.push_back(value);
	//_vector.push_back(value2);

	std::vector<int>::iterator Test1 = _vector.begin();
	std::vector<int>::iterator Test2 = _vector.begin();

	_vector.erase(Test2);
	int Value = *Test1;

	int a = 0;

	return 0;
}