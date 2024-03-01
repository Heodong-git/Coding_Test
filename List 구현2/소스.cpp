#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    int OriginBudget = budget;

    // 첫번째 부서에서 부터 가진 금액보다 요구치가 많다면 바로 리턴
    if (d[0] > OriginBudget)
    {
        return 0;
    }

    // 그게 아니라면 포문
    for (int i = 0; i < d.size(); ++i)
    {
        // 포문 진입했으면 일단 첫번째는 지원가능한거고 
        ++answer;
        OriginBudget -= d[i];
        if (OriginBudget <= 0)
        {
            return answer;
        }
    }

    return answer;
}

int main()
{
    solution({ 1, 3, 2, 5, 4 }, 9 );
    return 0;
}