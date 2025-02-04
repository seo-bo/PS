#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<ll>>graph(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}
	for (int z = 0; z < n; ++z)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][z] + graph[z][j]);
			}
		}
	}
	ll ans = LLONG_MAX;
	function<void(int, int, ll)> dfs = [&](int re, int mask, ll sum)
		{
			if ((1 << n) - 1 == mask)
			{
				ans = min(ans, sum);
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				dfs(i, mask | (1 << i), sum + graph[re][i]);
			}
		};
	dfs(k, (1 << k), 0);
	cout << ans;
	return 0;
}