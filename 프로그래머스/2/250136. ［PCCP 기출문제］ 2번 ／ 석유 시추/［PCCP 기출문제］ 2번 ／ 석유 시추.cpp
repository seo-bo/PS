#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size(), m = land[0].size();
    vector<vector<int>>v(n,vector<int>(m,0));
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int ver = 1;
    map<int,int>mm;
    auto bfs = [&] (int x, int y)
    {
        v[x][y] = ver;
        queue<pii>q;
        q.push(make_pair(x,y));
        int cnt = 0;
        while(!q.empty())
        {
            auto [xx,yy] = q.front();
            q.pop();
            cnt++;
            for(int i =0; i<4;++i)
            {
                int nx = xx + dir[i][0];
                int ny = yy + dir[i][1];
                if(nx >=0 && nx < n && ny>=0 && ny < m && !v[nx][ny] && land[nx][ny])
                {
                    v[nx][ny] = ver;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        mm[ver++] = cnt;
    };
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(!v[i][j] && land[i][j])
            {
                bfs(i,j);
            }
        }
    }
    for(int j =0; j<m;++j)
    {
        set<int>s;
        for(int i =0; i<n;++i)
        {
            s.insert(v[i][j]);
        }
        int temp = 0;
        for(auto & j : s)
        {
            temp += mm[j];
        }
        answer = max(answer,temp);
    }
    return answer;
}