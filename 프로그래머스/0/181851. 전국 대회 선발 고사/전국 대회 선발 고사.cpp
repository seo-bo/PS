#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pii>v;
    int n = rank.size();
    for(int i =0; i<n;++i)
    {
        if(attendance[i])
        {
            v.push_back(make_pair(rank[i],i));
        }
    }
    sort(v.begin(),v.end());
    return v[0].second * 10000 + v[1].second * 100 + v[2].second;
}