#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    size_t StrSize = s.size();
    if (StrSize == 4 || StrSize == 6)
    {
        for (int i = 0; i < static_cast<int>(StrSize); ++i)
        {
            if (65 <= s[i] && s[i] <= 90)
            {
                answer = false;
                break;
            }

            else if (97 <= s[i] && s[i] <= 122)
            {
                answer = false;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    solution("1234");
    return 0;
}