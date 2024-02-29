#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    int Value = n;
    vector<int> Values = vector<int>();
    for (int i = 1; i < Value; ++i)
    {
        int Result = n % i;
        if (1 == Result)
        {
            Values.push_back(i);
        }
    }

    auto MinValueIter = min_element(Values.begin(), Values.end());
    answer = *MinValueIter;

    return answer;
}

int main()
{
    cout << solution(10);

    return 0;
}