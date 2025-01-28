#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(vector<vector<int>> v) 
{
    int ans = 0;
    sort(v.begin(), v.end(), [&] (const vector<int>&a, const vector<int>&b)
         {
            return a[1] < b[1]; 
         });
    int pre = -30001;
    for(auto & i : v)
    {
        if(pre < i[0])
        {
            ans++;
            pre = i[1];
        }
    }
    return ans;
}