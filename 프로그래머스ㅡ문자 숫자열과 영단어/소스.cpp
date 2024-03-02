#include <string>
#include <vector>

using namespace std;

vector<pair<string, string>> StrVector = { {"zero", "0"},
                                           {"one", "1"},
                                           {"two", "2"},
                                           {"three", "3"}, 
                                           {"four", "4"}, 
                                           {"five", "5"}, 
                                           {"six", "6"},
                                           {"seven", "7"}, 
                                           {"eight", "8"},
                                           {"nine", "9"} };
                                            

int solution(string s)
{
    int answer = 0;

    for (size_t i = 0; i < StrVector.size(); i++)
    {
        string str;
        str = StrVector[i].first;

        while (string::npos != s.find(str))
        {
            s.replace(s.find(str), str.size(), StrVector[i].second);
        }
    }

    answer = std::stoi(s);
    return answer;
}

int main()
{
    solution("oneone4seveneight");
    return 0;
}