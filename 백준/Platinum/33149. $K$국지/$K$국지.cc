#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, u = 0;
	cin >> n;
	vector<ll>c(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> u;
	vector<vector<ll>>dp(n + 1, vector<ll>(u + 1, INT_MAX));
	auto cal = [&](ll a, ll b)
		{
			return (a - b) * (a - b);
		};
	for (int i = 1; i <= n; ++i)
	{
		dp[i][c[i]] = cal(u, c[i]);
	}
	function<void(int, int)> dfs = [&](int parent, int node)
		{
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(node, i);
				vector<ll>temp(u + 1, INT_MAX);
				for (int j = 0; j <= u; ++j)
				{
					for (int k = 0; k <= u; ++k)
					{
						if (j + k <= u)
						{
							temp[j + k] = min(temp[j + k], dp[node][j] + dp[i][k] - cal(u, j) - cal(u, k) + cal(u, j + k));
						}
						temp[j] = min(temp[j], dp[node][j] + dp[i][k]);
					}
				}
				dp[node] = temp;
			}
		};
	dfs(-1, 1);
	ll ans = LLONG_MAX;
	for (int i = 1; i <= u; ++i)
	{
		ans = min(ans, dp[1][i]);
	}
	cout << ans;
	return 0;
}