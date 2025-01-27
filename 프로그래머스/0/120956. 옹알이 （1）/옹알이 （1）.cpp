#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string>v = {"aya","ye","woo","ma"};
    set<string>ss = {"aya","ye","woo","ma"};
    function<void(string,int, int)> dfs = [&] (string str, int ed, int mask)
    {
        if(__builtin_popcount(mask) == ed)
        {
            ss.insert(str);
            return;
        }
        for(int i =0; i<4;++i)
        {
            if(mask & (1<<i))
            {
                continue;
            }
            dfs(str + v[i], ed, mask | (1<<i));
        }
    };
    for(int i=2; i<=4;++i)
    {
        dfs("",i,0);
    }
    for(auto & i : babbling)
    {
        if(ss.find(i) != ss.end())
        {
            answer++;
        }
    }
    return answer;
}