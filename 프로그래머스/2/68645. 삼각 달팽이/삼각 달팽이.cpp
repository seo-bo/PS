#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>>dir = {{1,-1},{0,1},{-1,0}};
    vector<vector<int>>v(5005,vector<int>(5005,-1));
    int lim = 1;
    for(int i =2; i<=n;++i)
    {
        lim += i;
    }
    int x = 2500, y = 2500;
    for(int i =1; i<=n;++i)
    {
        v[x][y] = i;
        int nx = x + dir[0][0];
        int ny = y + dir[0][1];
        if(i == n)
        {
            break;
        }
        x = nx;
        y = ny;
    }
    for(int i =n; i<=2*n-1;++i)
    {
        v[x][y] = i;
        int nx = x + dir[1][0];
        int ny = y + dir[1][1];
        if(i == 2*n-1)
        {
            break;
        }
        x = nx;
        y = ny;
    }
    int d = 2;
    for(int i =2*n -1; i<=lim;++i)
    {
        v[x][y] = i;
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if(v[nx][ny] != -1)
        {
            d = (d+1) % 3;
            nx = x + dir[d][0];
            ny = y + dir[d][1];
        }
        x = nx;
        y = ny;
    }
    for(int i =0; i<=5000;++i)
    {
        for(int j =0; j<=5000;++j)
        {
            if(v[i][j] != -1)
            {
                answer.push_back(v[i][j]);
            }
        }
    }
    return answer;
}