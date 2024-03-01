#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    int OriginBudget = budget;

    // ù��° �μ����� ���� ���� �ݾ׺��� �䱸ġ�� ���ٸ� �ٷ� ����
    if (d[0] > OriginBudget)
    {
        return 0;
    }

    // �װ� �ƴ϶�� ����
    for (int i = 0; i < d.size(); ++i)
    {
        // ���� ���������� �ϴ� ù��°�� ���������ѰŰ� 
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