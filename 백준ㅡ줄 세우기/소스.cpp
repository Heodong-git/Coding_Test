#include <iostream>
#include <vector>


template <typename T>
class TemplateTest
{
public:
	TemplateTest(const T _Value, const T _Value2) :
		Value(_Value), Value2(_Value2)
	{
		
	}

private:
	T Value;
	T Value2;
};



int main()
{
	int Value = 1;
	int Value2 = 2;
	TemplateTest<int> Test(Value, Value2);

	float FValue = 1.0f;
	float FValue2 = 2.0f;
	TemplateTest<float> FTest(FValue, FValue2);

	return 0;
}