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


    
    // first = �켱����, second = idx
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

        // ���� ���ٸ� ���� ���μ����� �켱������ ���� ���ٴ� ���̴�.
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
        // �װ� �ƴ϶�� �켱������ ���� ���� �ʴٴ� ���̴�. ���� ���� �ٽ� ���ʿ� �߰��Ѵ�.
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