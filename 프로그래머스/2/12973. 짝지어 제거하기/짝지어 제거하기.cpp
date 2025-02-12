#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string ss)
{
    int answer = -1;
    vector<int>s;
    for(auto & i : ss)
    {
        s.push_back(i);
        while(s.size() >=2 && s.back() == s[s.size()-2])
        {
            s.pop_back();
            s.pop_back();
        }
    }
    return s.empty();
}