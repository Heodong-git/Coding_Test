#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    int OriginBudget = budget;
    sort(d.begin(), d.end());

    if (d[0] > OriginBudget)
    {
        return 0;
    }

    for (int i = 0; i < d.size(); ++i)
    {
        // 현재 지원금이 0원보다 작거나 현재 지원해야될 금액보다 작으면 return
        if (OriginBudget <= 0 || OriginBudget < d[i])
        {
            return answer;
        }
          
        ++answer;
        OriginBudget -= d[i];
    }

    return answer;
}

int main()
{
    solution({ 1, 3, 2, 5, 4 }, 9);
    return 0;
}