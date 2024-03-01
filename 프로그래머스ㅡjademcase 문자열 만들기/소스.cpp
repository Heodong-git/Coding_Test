#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int StrSize = static_cast<int>(s.size());
       
    for (int i = 0; i < StrSize; ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            continue;
        }

        // 현재 첫번째 문자이고 소문자라면 대문자로 변경
        if (i == 0 && ('a' <= s[i] && s[i] <= 'z'))
        {
            s[i] = s[i] - 32;
            continue;
        }
        
        // 현재 내가 공백이고 뒤의 문자가 소문자라면 대문자로 변경
        if (s[i] == ' ' && 0 != islower(s[i + 1]))
        {
            s[i + 1] = s[i + 1] - 32;
            ++i;
            continue;
        }

        if (0 == islower(s[i]) && s[i] != ' ')
        {
            s[i] = s[i] + 32;
        }
       
    }

    answer = s;

    return answer;
}

int main()
{
    solution("3people unFollowed me TeTe eeeeTE");
    return 0;
}