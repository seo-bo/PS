#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int answer = 0;
    vector<string>v(3,string(3,'.'));
    auto cal = [&]
    {
      for(int i =0; i<3;++i)
      {
          if(v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] != '.')
          {
              return true;
          }
          if(v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != '.')
          {
              return true;
          }
          if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.')
          {
            return true;
          }
          if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[1][1] != '.')
          {
                return true;
          }
      }
        return false;
    };
    auto check = [&]
    {
        for(int i =0; i<3;++i)
            {
                for(int j =0; j<3;++j)
                {
                    if(v[i][j] != board[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
    };
    function<bool(int,int)> dfs = [&] (int t, int depth)
    {
        if(check())
        {
            return true;
        }
        if(cal() || depth == 9)
        {
            return false;
        }
        char pivot = (t) ? 'X' : 'O';
        for(int i = 0; i<3;++i)
        {
            for(int j =0; j<3;++j)
            {
                if(v[i][j] != '.')
                {
                    continue;
                }
                v[i][j] = pivot;
                if(dfs((t+1)%2,depth+1))
                {
                    return true;
                }
                v[i][j] = '.';
            }
        }
        return false;
    };
    return dfs(0,0);
}