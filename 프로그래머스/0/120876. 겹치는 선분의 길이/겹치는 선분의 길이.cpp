#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

int solution(vector<vector<int>> lines) {
    vector<pii>v;
    for(auto & i : lines)
    {
        v.push_back(make_pair(i[0],1));
        v.push_back(make_pair(i[1],-1));
    }
    sort(v.begin(),v.end());
    int x = v[0].first;
    int ans = 0, cnt = 0;
    for (auto & [a,b] : v)
    {
        if(cnt >=2)
        {
            ans += a - x;
        }
        cnt += b;
        x = a;
    }
    return ans;
}