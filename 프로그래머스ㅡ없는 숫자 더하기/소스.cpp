#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < 10; ++i)
    {
        bool check = false;
        for (int j = 0; j < numbers.size(); ++j)
        {
            if (i == numbers[j])
            {
                check = true;
                break;
            }
        }

        if (false == check)
        {
            answer += i;
        }
    }

    return answer;
}

int main()
{

    solution({ 1, 2, 3, 4, 6, 7, 8, 0 });
    return 0;
}