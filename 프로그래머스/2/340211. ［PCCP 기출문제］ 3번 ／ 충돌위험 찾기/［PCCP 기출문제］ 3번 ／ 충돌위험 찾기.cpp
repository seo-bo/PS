#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<int>> pos, vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<vector<deque<int>>>>v(105,vector<vector<deque<int>>>(105));
    for(auto & i : routes)
    {
        deque<int> t;
        for(auto & j : i)
        {
            t.push_back(j-1);
        }
        int x = pos[t[0]][0];
        int y = pos[t[0]][1];
        t.pop_front();
        v[x][y].push_back(t);
    }
    auto check1 = [&]
    {
          int cnt = 0;
          for(int i =0 ;i<=100;++i)
          {
              for(int j =0; j<=100;++j)
              {
                  if(v[i][j].size() > 1)
                  {
                      cnt++;
                  }
              }
          }
        return cnt;
    };
    auto check2 = [&]
    {
          int cnt = 0;
          for(int i =0 ;i<=100;++i)
          {
              for(int j =0; j<=100;++j)
              {
                  if(!v[i][j].empty())
                  {
                      return false;
                  }
              }
          }
        return true;
    };
    answer += check1();
    while(!check2())
    {
        vector<vector<vector<deque<int>>>>temp(105,vector<vector<deque<int>>>(105));
        for(int i =0; i<=100;++i)
        {
            for(int j=0; j<=100;++j)
            {
                for(auto & k : v[i][j])
                {
                    if(pos[k[0]][0] == i && pos[k[0]][1] == j)
                    {
                        k.pop_front();
                    }
                    if(k.empty())
                    {
                        continue;
                    }
                    int a = pos[k[0]][0];
                    int b = pos[k[0]][1];
                    if(a != i)
                    {
                        if(i > a)
                        {
                            temp[i-1][j].push_back(k);
                        }
                        else
                        {
                            temp[i+1][j].push_back(k);
                        }
                    }
                    else
                    {
                        if(j > b)
                        {
                            temp[i][j-1].push_back(k);
                        }
                        else
                        {
                            temp[i][j+1].push_back(k);
                        }
                    }
                }
            }
        }
        v = move(temp);
        answer += check1();
    }
    return answer;
}