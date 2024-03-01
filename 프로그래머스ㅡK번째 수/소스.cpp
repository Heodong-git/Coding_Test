#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    vector<int> temp;
    
    // Ŀ�ǵ� �ӽ�����
    vector<int> values;
    
    // Ŀ�ǵ��� ������ ��ŭ �ݺ� ���Ű� 
    for (int i = 0; i < static_cast<int>(commands.size()); ++i)
    {
        values = commands[i];

        // �����ε���, ���ε���, ���° �ε����� ���� �������� �ް�.
        int StartIdx = values[0];
        int EndIdx = values[1];
        int FindIdx = values[2];

        // �ݺ����鼭 temp �� push_back �ؼ� �־��ְ� 
        for (int Idx = StartIdx - 1; Idx < EndIdx; ++Idx)
        {
            temp.push_back(array[Idx]);
        }

        // ����
        sort(temp.begin(), temp.end());

        // temp �� FindIdx ��° �� ����
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