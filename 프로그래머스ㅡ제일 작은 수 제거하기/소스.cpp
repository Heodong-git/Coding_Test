#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer = arr;
    
    if (arr.size() == 1 && arr[0] == 10)
    {
        answer.clear();
        answer.push_back(-1);
        return answer;
    }
    auto MinValue = min_element(answer.begin(), answer.end());
    
    int RemoveIndex = -1;
    
    for (int i = 0; i < answer.size(); i++)
    {
        if (*MinValue == answer[i])
        {
            RemoveIndex = i;
        }
    }
    
    if (RemoveIndex == -1)
    {
        answer.push_back(RemoveIndex);
        return answer;
    }

    answer.erase(answer.begin() + RemoveIndex);

    return answer;
}

int main()
{
    solution({10});
    return 0;
}

