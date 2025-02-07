#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) // ????
{
    int sx = INT_MAX, sy = INT_MAX, ex = INT_MIN, ey = INT_MIN;
    int n = wallpaper.size(), m = wallpaper[0].size();
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(wallpaper[i][j] == '#')
            {
                sx = min(sx,i);
                sy = min(sy,j);
                ex = max(ex,i + 1);
                ey = max(ey,min(j+1,m));
            }
        }
    }
    vector<int>answer = {sx,sy,ex,ey};
    return answer;
}