#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    function<void(int,int,int,int)> dfs = [&] (int depth, int a, int b, int c)
    {
      if(depth == 1)
      {
          vector<int>temp = {a,c};
          answer.push_back(temp);
          return;
      }
        dfs(depth-1,a,c,b);
        vector<int>temp = {a,c};
        answer.push_back(temp);
        dfs(depth-1,b,a,c);
    };
    dfs(n,1,2,3);
    return answer;
}