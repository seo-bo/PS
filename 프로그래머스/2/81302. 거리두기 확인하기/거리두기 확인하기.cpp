#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int n = 5, m = 5;
    auto bfs = [&] (int a, int xx, int yy)
    {
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        visited[xx][yy] = 0;
        queue<pii>q;
        q.push(make_pair(xx,yy));
        int cnt = 0;
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            if(places[a][x][y] == 'P')
            {
                cnt++;
            }
            if(visited[x][y] == 2)
            {
                continue;
            }
            for(int i = 0; i<4;++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >=0 && nx < n && ny >=0 && ny < m && places[a][nx][ny] != 'X')
                {
                    if(visited[nx][ny] >visited[x][y] + 1)
                    {
                        visited[nx][ny] = visited[x][y] +1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        return cnt;
    };
    for(int z =0; z<5;++z)
    {
        int flag = 1;
        for(int i =0; i<5;++i)
        {
            for(int j = 0; j<5;++j)
            {
                if(places[z][i][j] == 'P')
                {
                    if(bfs(z,i,j) >= 2)
                    {
                        flag = 0;
                    }
                }
            }
        }
        answer.push_back(flag);
    }
    return answer;
}