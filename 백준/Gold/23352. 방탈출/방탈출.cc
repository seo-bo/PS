#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>>v(n,vector<int>(m,0));
  vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
  for(auto & i: v)
  {
    for(auto & j : i)
    {
       cin >> j;
    }
  }
  int ans = INT_MIN, pivot = 0;
  auto bfs = [&] (int x, int y)
  {
      vector<vector<int>>visited(n,vector<int>(m,1e8));
      queue<pii>q;
      q.push(make_pair(x,y));
      visited[x][y] = 0;
      int cnt = 0;
      while(!q.empty())
      {
        auto [xx,yy] = q.front();
        q.pop();
        for(int i = 0; i<4;++i)
        {
          int nx = xx + dir[i][0];
          int ny = yy + dir[i][1];
          if(nx >=0 && nx < n && ny >=0 && ny < m && visited[nx][ny] > visited[xx][yy] + 1 && v[nx][ny])
          {
            visited[nx][ny] = visited[xx][yy] + 1;
            cnt = max(cnt, visited[nx][ny]);
            q.push(make_pair(nx,ny));
          }
        }
      }
      if(cnt < pivot)
      {
        return;
      }
      int p = 0;
      for(int i =0; i<n;++i)
      {
        for(int j =0; j<m;++j)
        {
          if(visited[i][j] == cnt)
          {
            p = max(p, v[i][j] + v[x][y]);
          }
        }
      }
      if(cnt > pivot)
      {
        pivot = cnt;
        ans = p;
      }
      else if(cnt == pivot)
      {
        ans = max(ans,p);
      }
  };
  for(int i =0; i<n;++i)
  {
    for(int j =0; j<m;++j)
    {
      if(v[i][j])
      {
      bfs(i,j);
      }
    }
  }
  cout << ans;
  return 0;
}