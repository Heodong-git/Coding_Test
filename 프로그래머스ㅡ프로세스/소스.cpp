#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    int target = location - 1;
    if (target < 0)
    {
        target = 0;
    }


    
    // first = 우선순위, second = idx
    queue<pair<int, int>> processq;
    priority_queue<pair<int, int>> priorityq;

    for (int i = 0; i < priorities.size(); i++)
    {
        processq.push({ priorities[i], i });
        priorityq.push({ priorities[i], i });
    }

    int count = 0;
    while (false == processq.empty())
    {
        pair<int, int> processdata = processq.front();
        pair<int, int> prioritydata = priorityq.top();

        // 서로 같다면 현재 프로세스가 우선순위가 가장 높다는 뜻이다.
        if (processdata.first == prioritydata.first)
        {
            ++count;
            if (processdata.second == target)
            {
                answer = count;
                break;
            }

            processq.pop();
            priorityq.pop();
        }
        // 그게 아니라면 우선순위가 가장 높지 않다는 뜻이다. 제거 한후 다시 뒤쪽에 추가한다.
        else
        {
            processq.pop();
            processq.push(processdata);
        }
    }
    
    return answer;
}

int main()
{

    solution({ 2, 1, 3, 2 }, 2);

    return 0;
}