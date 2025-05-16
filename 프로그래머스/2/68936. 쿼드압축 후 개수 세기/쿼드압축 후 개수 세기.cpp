#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    int n = arr.size(), m = n;
    auto check = [&] (int x, int y, int siz)
    {
        set<int>s;
        for(int i = x; i < x+ siz;++i)
        {
            for(int j =y; j < y + siz;++j)
            {
                s.insert(arr[i][j]);
            }
        }
        return (s.size() == 1);
    };
    function<void(int,int,int)> dfs = [&] (int x, int y, int siz)
    {
        if(siz == 1)
        {
            answer[arr[x][y]]++;
            return;
        }
        if(check(x,y,siz))
        {
            answer[arr[x][y]]++;
            return;
        }
        int ns = siz/2;
        dfs(x,y,ns);
        dfs(x+ns,y,ns);
        dfs(x+ns,y+ns,ns);
        dfs(x,y+ns,ns);
    };
    dfs(0,0,n);
    return answer;
}