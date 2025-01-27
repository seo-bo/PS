#include<bits/stdc++.h>
using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    for(auto & i :my_string)
    {
        if(i == alp[0])
        {
            answer += toupper(i);
            continue;
        }
        answer += i;
    }
    return answer;
}