#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0, len = info.size();
    vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
    function<int(int,int,int)> dfs = [&] (int idx, int a, int b)
    {
      if(idx == len)
      {
          return dp[idx][a][b] = 1;
      }
        if(dp[idx][a][b] != -1)
        {
            return dp[idx][a][b];
        }
        int res = 0;
        if(a + info[idx][0] < n)
        {
            res |= dfs(idx+1, a + info[idx][0], b);
        }
        if(b + info[idx][1] < m)
        {
            res |= dfs(idx+1, a, b + info[idx][1]);
        }
        return dp[idx][a][b] = res;
    };
    if(!dfs(0,0,0))
    {
        return -1;
    }
    answer = 1e9;
    for(int i =0; i<n;++i)
    {
        for(int j = 0; j<m;++j)
        {
            if(dp[len][i][j] == 1)
            {
                answer = min(answer,i);
            }
        }
    }
    return answer;
}