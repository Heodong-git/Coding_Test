#include <math.h>

using namespace std;


long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long AddResult = 0;
    for (long long i = 1; i < count + 1; ++i)
    {
        AddResult += price * i;
    }

    // 결과값이 양수면 돈이 모자라지 않는 것 0 출력
    // 결과값이 음수면 돈이 모자란 것, abs, 답출력
    answer = static_cast<long long>(money - AddResult);
    if (answer < 0)
    {
        answer = abs(answer);
    }
    else
    {
        answer = 0;
    }
    return answer;
}

int main()
{
    solution(3, 20, 4);
    return 0;
}