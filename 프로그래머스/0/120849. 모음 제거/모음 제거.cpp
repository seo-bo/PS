#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    string answer = "";
    set<char>s = {'a','i','o','e','u'};
    for(auto & i : my_string)
    {
        if(s.find(i) != s.end())
        {
            continue;
        }
        answer += i;
    }
    return answer;
}