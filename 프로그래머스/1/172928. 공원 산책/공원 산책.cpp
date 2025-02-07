#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    map<char,int>mm = {{'E',3},{'W',2},{'N',0},{'S',1}};
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int n = park.size(), m = park[0].size();
    int x = 0, y = 0;
    auto sv = [&]
    {    
        for(int i =0; i<n;++i)
        {
            for(int j =0; j<m;++j)
            {
                if(park[i][j] == 'S')
                {
                    x = i, y = j;
                    return;
                }
            }
        }
    };
    sv();
    for(auto & i : routes)
    {
        stringstream ss(i);
        string str;
        vector<string>ok;
        while(ss >> str)
        {
            ok.push_back(str);
        }
        int d = mm[ok[0][0]];
        int k = stoi(ok[1]);
        bool flag = true;
        int nx = x;
        int ny = y;
        while(k--)
        {
            nx = nx + dir[d][0];
            ny = ny + dir[d][1];
            if(nx >=0 && nx < n && ny >=0 && ny < m && park[nx][ny] != 'X')
            {
                continue;
            }
            flag = false;
            break;
        }     
        if(flag)
        {
            x = nx;
            y = ny;
        }
    }
    vector<int>answer = {x,y};
    return answer;
}