#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;

    int AddValue = 0;
    int Origin = x;
    while (x > 0)
    {
        int Result = x % 10;
        AddValue += Result;
        x /= 10;
    }

    if (0 != Origin % AddValue)
    {
        answer = false;
    }


    return answer;
}

int main()
{

    solution(12);
    return 0;
}