#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = 1; j < numbers.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }
            int result = numbers[i] + numbers[j];
            answer.push_back(result);
        }
    }

    sort(answer.begin(), answer.end());
    vector<int>::iterator eraseiter = unique(answer.begin(), answer.end());
    answer.erase(eraseiter, answer.end());

    return answer;
}

int main()
{

    solution({ 2,1,3,4,1 });
    return 0;
}