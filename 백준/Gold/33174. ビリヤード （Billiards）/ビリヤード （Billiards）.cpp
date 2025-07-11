#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<vector<int>>graph(n + 1);
	vector<bool>ok(n + 1);
	vector<ll>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp == -1)
		{
			ok[i] = true;
			continue;
		}
		graph[temp].push_back(i);
	}
	int ans = -1;
	function<void(int, ll)> dfs = [&](int node, ll po)
		{
			ans = max(ans, node);
			for (auto& i : graph[node])
			{
				if (po - cost[i] >= 0)
				{
					dfs(i, po - cost[i]);
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (ok[i] && x - cost[i] >= 0)
		{
			dfs(i, x - cost[i]);
		}
	}
	cout << ans;
	return 0;
}