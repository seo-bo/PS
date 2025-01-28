#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solution(string number, int k) 
{
    string answer = "";
    for(auto & i : number)
    {
        while(!answer.empty() && k && answer.back() < i)
        {
            answer.pop_back();
            k--;
        }
        answer +=i;
    }
    if(k)
    {
        answer = answer.substr(0,answer.size() - k);
    }
    return answer;
}