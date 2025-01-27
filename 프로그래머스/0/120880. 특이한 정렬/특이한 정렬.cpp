#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pii>v;
    for(auto & i : numlist)
    {
       v.push_back(make_pair(abs(i-n),i));
    }
    sort(v.begin(),v.end(), [&] (const pii & a, const pii & b)
         {
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
             return a.first < b.first;
         });
    for(auto & [_,a] : v)
    {
        answer.push_back(a);
    }
    return answer;
}