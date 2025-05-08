#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    int n = 0;
    vector<int>in(MAX+2,0),out(MAX+2,0);
    for(auto & i : edges)
    {
        out[i[0]]++;
        in[i[1]]++;
        n = max({n,i[0],i[1]});
    }
    int ban = -1;
    for(int i =1; i<=n;++i)
    {
        if(out[i] >= 2 && !in[i])
        {
            answer[0] = i;
            continue;
        }
        if(out[i] >=2 && in[i] >= 2)
        {
            answer[3]++;
        }
        else if(!out[i] && in[i])
        {
            answer[2]++;
        }
    }
    answer[1] = out[answer[0]] - answer[2] - answer[3];
    return answer;
}