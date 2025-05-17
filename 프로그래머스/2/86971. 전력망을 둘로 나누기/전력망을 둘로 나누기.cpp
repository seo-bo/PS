#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    int ver = 0;
    vector<vector<pii>>graph(n+1);
    for(auto & i : wires)
    {
        int pivot = ++ver;
        graph[i[0]].push_back(make_pair(ver,i[1]));
        graph[i[1]].push_back(make_pair(ver,i[0]));
    }
    auto bfs = [&] (int ban)
    {
        vector<bool>visited(n+1,false);
        visited[1] = true;
        queue<int>q;
        q.push(1);
        int cnt = 0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cnt++;
            for(auto & [a,b] : graph[cur])
            {
                if(a == ban)
                {
                    continue;
                }
                if(!visited[b])
                {
                    visited[b] = true;
                    q.push(b);
                }
            }
        }
        return cnt;
    };
    for(int i =1; i<=ver;++i)
    {
        int p = bfs(i);
        answer = min(answer, abs(n -p - p));  
    }
    return answer;
}