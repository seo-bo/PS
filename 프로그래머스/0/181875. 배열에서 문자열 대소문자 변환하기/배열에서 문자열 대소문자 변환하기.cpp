#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(int i =0; i < (int)strArr.size();++i)
    {
        auto & a = strArr[i];
        if(i%2)
        {
            transform(a.begin(),a.end(),a.begin(),::toupper);
        }
        else
        {
             transform(a.begin(),a.end(),a.begin(), ::tolower);
        }
        answer.push_back(a);
    }
    return answer;
}