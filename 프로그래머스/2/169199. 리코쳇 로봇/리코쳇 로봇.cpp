#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> tp;

int solution(vector<string> board) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<vector<int>>>visited(n,vector<vector<int>>(m,vector<int>(5,INT_MAX)));
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(board[i][j] == 'R')
            {
                sx =i, sy = j;   
            }
            if(board[i][j] == 'G')
            {
                ex =i, ey = j;
            }
        }
    }
    visited[sx][sy][0] = 0;
    queue<tp>q;
    q.push(make_tuple(sx,sy,0));
    auto cal = [&] (int xx, int yy)
    {
      return (xx >=0 && xx < n && yy >=0 && yy < m && board[xx][yy] != 'D');  
    };
    while(!q.empty())
    {
        auto [x,y,d] = q.front();
        q.pop();
        for(int i =0; i<4;++i)
        {
            int nx = x, ny = y;
            while(1)
            {
                int mx = nx + dir[i][0];
                int my = ny + dir[i][1];
                if(!cal(mx,my))
                {
                    break;
                }
                nx = mx;
                ny = my;
            }
            if(visited[nx][ny][i] > visited[x][y][d] + 1)
            {
                visited[nx][ny][i] = visited[x][y][d] + 1;
                q.push(make_tuple(nx,ny,i));
            }
        }
    }
    int ans = INT_MAX;
    for(int i =0; i<4;++i)
    {
        ans = min(ans,visited[ex][ey][i]);
    }
    return (ans == INT_MAX) ? -1 : ans;
}