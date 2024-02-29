#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;

    if (a == b)
    {
        answer = a;
        return answer;
    }

    if (a > b)
    {
        long long Temp = a;
        a = b;
        b = Temp;
    }
    long long Value = a + 1;
    long long Result = a;



    while (Value <= b)
    {
        Result += Value;
        ++Value;
    }

    answer = Result;
    return answer;
}

int main()
{
    solution(3, 5);
    return 0;
}