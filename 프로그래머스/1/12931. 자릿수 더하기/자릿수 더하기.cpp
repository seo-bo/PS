#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string str = to_string(n);
    for(auto & i : str)
    {
        answer += i - '0';
    }
    return answer;
}