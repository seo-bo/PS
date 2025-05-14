#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<pii>v;
    for(auto & i : targets)
    {
        v.push_back(make_pair(i[0],i[1]));
    }
    sort(v.begin(),v.end(), [&] (const pii & a, const pii & b)
         {
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;         
         });
    int B = INT_MAX;
    for(auto & [a,b] : v)
    {
        if(a >= B)
        {
            answer++;
            B = b;
        }
        else
        {
          B = min(b,B);   
        }
    }
    return answer + 1;
}