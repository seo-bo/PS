#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int solution(int n, vector<vector<int>> costs) 
{
    int ans = 0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    vector<int>parent(n+1,0);
    vector<int>rank(n+1,0);
    iota(parent.begin(),parent.end(),0);
    function<int(int)> find = [&] (int root) ->int
    {
        if(root == parent[root])
        {
            return parent[root];
        }
        return parent[root] = find(parent[root]);
    };
    auto merge = [&] (int root1, int root2)
    {
        int r1 = find(root1);
        int r2 = find(root2);
        if(r1 != r2)
        {
            if(rank[r1] < rank[r2])
            {
                parent[r1] = r2;
            }
            else if (rank[r1] > rank[r2])
            {
                parent[r2] = r1;
            }
            else
            {
                parent[r2] = r1;
                rank[r1]++;
            }
        }
    };
    for(auto & i : costs)
    {
        pq.push(make_tuple(i[2],i[0],i[1]));
    }
    int e = n-1;
    while(!pq.empty() && e)
    {
        auto [a,b,c] = pq.top();
        pq.pop();
        int r1 = find(b), r2 = find(c);
        if(r1 != r2)
        {
            merge(b,c);
            ans += a;
            e--;
        }
    }
    return ans;
}