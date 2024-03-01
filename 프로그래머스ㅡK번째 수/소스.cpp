#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    vector<int> temp;
    
    // 커맨드 임시저장
    vector<int> values;
    
    // 커맨드의 사이즈 만큼 반복 돌거고 
    for (int i = 0; i < static_cast<int>(commands.size()); ++i)
    {
        values = commands[i];

        // 시작인덱스, 끝인덱스, 몇번째 인덱스를 구할 것인지를 받고.
        int StartIdx = values[0];
        int EndIdx = values[1];
        int FindIdx = values[2];

        // 반복돌면서 temp 에 push_back 해서 넣어주고 
        for (int Idx = StartIdx - 1; Idx < EndIdx; ++Idx)
        {
            temp.push_back(array[Idx]);
        }

        // 정렬
        sort(temp.begin(), temp.end());

        // temp 의 FindIdx 번째 값 저장
        answer.push_back(temp[FindIdx - 1]);
        temp.clear();
    }

    return answer;
}

int main()
{

    solution({ 1, 5, 2, 6, 3, 7, 4 }, { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } });
    return 0;
}