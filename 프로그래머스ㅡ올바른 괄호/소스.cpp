#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> result;
    for (int i = 0; i < static_cast<int>(s.size()); ++i)
    {
        if (s[i] == '(')
        {
            result.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (0 == result.size())
            {
                answer = false;
                break;
            }

            result.pop();
        }
    }

    if (0 != result.size())
    {
        answer = false;
    }
    
    return answer;
}

int main()
{
    solution("()()");
    return 0;
}