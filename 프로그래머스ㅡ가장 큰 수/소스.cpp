#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";

    // �����ϰ� 
    sort(numbers.begin(), numbers.end());
    
    vector<vector<int>> temps;
    
    // ���� ���ϰ� 
    do
    {
        vector<int> temp;
        for (int i = 0; i < static_cast<int>(numbers.size()); i++)
        {
            temp.push_back(numbers[i]);
        }
        temps.push_back(temp);

    } while (next_permutation(numbers.begin(), numbers.end()));


    vector<string> results;
    for (int i = 0; i < static_cast<int>(temps.size()); i++)
    {
        string strtemp;
        for (int j = 0; j < static_cast<int>(temps[j].size()); j++)
        {
            int Value = temps[i][j];
            strtemp += to_string(Value);
        }
        results.push_back(strtemp);
    }
    
    auto Result = max_element(results.begin(), results.end());
    
    answer = *Result;

    return answer;
}

int main()
{
    solution({ 6 , 10, 2 });
    return 0;
}