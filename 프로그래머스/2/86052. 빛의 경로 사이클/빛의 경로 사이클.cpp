#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(5,false)));
    auto cal = [&] (int sx, int sy, int nd)
    {
        int x = sx, y = sy, d = nd;
        int pivot = 0;
        while(!visited[x][y][d])
        {
            visited[x][y][d] = true;
            pivot++;
            if(grid[x][y] == 'L')
            {
                d = (d -1 + 4) % 4;
            }
            else if(grid[x][y] == 'R')
            {
                d = (d + 1) % 4;
            }
            x = (x + dir[d][0] + n) % n;
            y = (y + dir[d][1] + m) % m;
        }
        if(sx == x && sy == y && nd == d)
        {
            answer.push_back(pivot);
        }
    };
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            for(int k =0; k<4;++k)
            {
                if(!visited[i][j][k])
                {
                    cal(i,j,k);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}