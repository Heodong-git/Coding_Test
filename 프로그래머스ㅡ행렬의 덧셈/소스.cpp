#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;


    for (int i = 0; i < static_cast<int>(arr1.size()); ++i)
    {
        vector<int> Temp;
        for (int j = 0; j < static_cast<int>(arr1[i].size()); ++j)
        {
            Temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        
        answer.push_back(Temp);
    }
    return answer;
}

int main()
{
  
    return 0;
}