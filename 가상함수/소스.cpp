#include <iostream>



class Parent
{
public:
	Parent()
	{
		
	}
	virtual ~Parent()
	{

	}

private:
	void TestFunction()
	{
		std::cout << "¤·¤·" << std::endl;
	}
};

class Child : public Parent
{
public:
	Child()
	{

	}
	~Child()
	{

	}


};



int main()
{
	Child TestChild;



	int a = 0;
	return 0;
}