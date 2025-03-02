#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size(), m = storage[0].size();
    vector<vector<char>>v(n+2,vector<char>(m+2,'?'));
    for(int i =1; i <=n;++i)
    {
        for(int j = 1; j<=m;++j)
        {
            v[i][j] = storage[i-1][j-1];
        }
    }
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    auto bfs = [&] (vector<vector<bool>>&visited,int x, int y, char pivot)
    {
        visited[x][y] = true;
        queue<pii>q;
        q.push(make_pair(x,y));
        while(!q.empty())
        {
            auto [sx,sy] = q.front();
            q.pop();
            for(int i =0; i<4;++i)
            {
                int nx = sx+dir[i][0];
                int ny = sy + dir[i][1];
                if(nx >=0 && nx <= n+1 && ny >=0 && ny <=m+1 && !visited[nx][ny])
                {
                    if(v[nx][ny] == pivot)
                    {
                        v[nx][ny] = '?';
                        visited[nx][ny] = true;
                    }
                    else if(v[nx][ny] == '?')
                    {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    };
    for(auto & z : requests)
    {
        char p = z[0];
        if(z.size() > 1)
        {
             for(int i =0; i<=n+1;++i)
            {
                for(int j = 0; j <=m+1;++j)
                {
                    if(v[i][j] != p)
                    {
                        continue;
                    }
                    v[i][j] = '?';
                }
            }
        }
        else
        {
            vector<vector<bool>>visited(n+2,vector<bool>(m+2,false));
            for(int i =0; i<=n+1;i += n+1)
            {
                for(int j =0; j<=m+1;j += m + 1)
                {
                    if(!visited[i][j] && v[i][j] == '?')
                    {
                        bfs(visited,i,j,p);
                    }
                }
            }
        }
    }
    for(int i = 0; i<=n+1;++i)
    {
        for(int j =0; j <=m+1;++j)
        {
           if(v[i][j] == '?')
           {
               continue;
           }
            answer++;
        }
    }
    return answer;
}