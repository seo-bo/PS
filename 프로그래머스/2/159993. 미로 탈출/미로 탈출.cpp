#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> tp;
int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int sx =0, sy = 0, ex =0 ,ey = 0;
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(maps[i][j] == 'S')
            {
                sx = i, sy = j;
            }
            if(maps[i][j] == 'E')
            {
                ex = i, ey = j;
            }
        }
    }
    queue<tp>q;
    q.push(make_tuple(sx,sy,0));
    vector<vector<vector<int>>>visited(n,vector<vector<int>>(m,vector<int>(2,INT_MAX)));
    visited[sx][sy][0] = 0;
    while(!q.empty())
    {
        auto [x,y,cnt] = q.front();
        q.pop();
        if(x == ex && y == ey && cnt == 1)
        {
            return visited[x][y][cnt];
        }
        for(int i =0; i<4;++i)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >=0 && nx < n && ny >=0 && ny < m && maps[nx][ny] != 'X')
            {
                int flag = cnt | (maps[nx][ny] == 'L');
                if(visited[nx][ny][flag] > visited[x][y][cnt] + 1)
                {
                    visited[nx][ny][flag] = visited[x][y][cnt] + 1;
                    q.push(make_tuple(nx,ny,flag));
                }
            }
        }
    }
    return -1;
}