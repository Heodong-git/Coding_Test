#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        if (q.size() == 0)
        {
            q.push(arr[i]);
            continue;
        }

        if (q.back() != arr[i])
        {
            q.push(arr[i]);
        }
    }

    while (q.size() != 0)
    {
        int value = q.front();
        answer.push_back(value);
        q.pop();
    }

    return answer;
}

int main()
{

    solution({ 1,1,3,3,0,1,1 });
    return 0;
}