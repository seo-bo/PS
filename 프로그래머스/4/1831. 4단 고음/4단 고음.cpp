#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n) 
{
    int ans = 0;
    function<void(int,int)> dfs = [&] (int now, int cnt)
    {
        if(now < 3 || log(now) / log(3) < (cnt+1) >> 1)
        {
            return;
        }
        if(now == 3)
        {
            if(cnt == 2)
            {
                ans++;
            }
            return;
        }
        if(!(now % 3) && cnt >= 2)
        {
            dfs(now /3, cnt - 2);    
        }
        dfs(now -1, cnt+1);
    };
    dfs(n-2,2);
    return ans;
}