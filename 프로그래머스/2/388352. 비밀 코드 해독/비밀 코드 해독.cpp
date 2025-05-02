#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int len = ans.size();
    function<void(int,int, int)> dfs = [&] (int mask, int depth, int pre)
        {
            if(depth == 5)
            {
                for(int i =0; i<len;++i)
                {
                    int temp = 0;
                    for(auto & j : q[i])
                    {
                        if(mask & (1<<j))
                        {
                            temp++;
                        }
                    }
                    if(ans[i] != temp)
                    {
                        return;
                    }
                }
                answer++;
                return;
            }
            for(int i=pre+1; i<=n;++i)
            {
                if(mask & (1<<i))
                {
                    continue;
                }
                dfs(mask | (1<<i), depth + 1,i);
            }
        };
    dfs(0,0,0);
    return answer;
}