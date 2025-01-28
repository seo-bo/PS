#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> cookie) 
{
    int n = cookie.size();
    if(n == 1)
    {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i<n-1;++i)
    {
        int l = i, r= i+1;
        int ls = cookie[l], rs = cookie[r];
        while(l >=0 && r < n)
        {
            if(ls == rs)
            {
                ans = max(ans,ls);
            }
            if(ls <= rs && l > 0)
            {
                --l, ls += cookie[l];
            }
            else if (ls > rs && r < n-1)
            {
                ++r, rs += cookie[r];
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}