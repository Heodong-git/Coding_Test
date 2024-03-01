#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    double Value = sqrt(n);
    if (Value == static_cast<int>(Value))
    {
        answer = static_cast<long long>(pow(++Value, 2));
    }
    else
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    cout << solution(7);

    return 0;
}