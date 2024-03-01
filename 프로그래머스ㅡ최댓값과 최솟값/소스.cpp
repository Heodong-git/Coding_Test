#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> Values;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, ' ')) {
        int num = stoi(temp);
        Values.push_back(num);
    }

    sort(Values.begin(), Values.end());

    answer = to_string(Values.front()) + ' ' + to_string(Values.back());

    return answer;
}

int main()
{
  
    std::cout << solution("-1 -1");


    return 0;
}