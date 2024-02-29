#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    string ValueStr = to_string(n);

    sort(ValueStr.begin(), ValueStr.end(), greater<>());

    answer = stoll(ValueStr);

    return answer;
}

int main()
{
    std::cout << solution(194643);
    return 0;
}