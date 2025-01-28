#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> info, vector<vector<int>> edges)
{
	int ans = INT_MIN;
	int n = info.size();
    set<int>visited;
    vector<int>v;
	vector<vector<int>>graph(n);
    for(auto & i : edges)
    {
        graph[i[0]].push_back(i[1]);
    }
	function<void(int,int,int,vector<int>&)> dfs = [&] (int sheep, int wolf, int node,vector<int>&v)
    {
        sheep += (info[node] == 0) ? 1 : 0;
        wolf += (info[node] == 1) ? 1 : 0;
        if(wolf >= sheep)
        {
            return;
        }
        ans = max(ans, sheep);
        vector<int>temp = v;
        for(auto & i : graph[node])
        {
            temp.push_back(i);
        }
        for(auto & i : temp)
        {
            if (visited.find(i) != visited.end())
            {
                continue;
            }
            visited.insert(i);
            dfs(sheep, wolf, i,temp);
            visited.erase(i);
        }
    };
    vector<int>temp;
    dfs(0,0,0,temp);
	return ans;
}