#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<bool>ok(n + 1);
	vector<ll>cost(n + 1);
	vector<vector<int>>graph(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		char w;
		cin >> w;
		if (w == 'W')
		{
			ok[i] = true;
		}
		int a = 0;
		cin >> cost[i] >> a;
		graph[a].push_back(i);
		graph[i].push_back(a);
	}
	function<ll(int, int)> dfs = [&](int parent, int node)
		{
			ll temp = cost[node];
			if (ok[node])
			{
				temp *= -1;
			}
			for (auto& i : graph[node])
			{
				if (parent == i)
				{
					continue;
				}
				temp += dfs(node, i);
			}
			return max(temp, 0LL);
		};
	cout << dfs(0, 1);
	return 0;
}