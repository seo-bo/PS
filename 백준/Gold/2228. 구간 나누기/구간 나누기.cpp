#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
	function<ll(int, int)> dfs = [&](int idx, int div)
		{
			if (div == 0)
			{
				return 0LL;
			}
			if (idx > n)
			{
				return (ll)-1e9;
			}
			if (dp[idx][div] != -1)
			{
				return dp[idx][div];
			}
			ll cost = dfs(idx + 1, div);
			for (int i = idx; i <= n; ++i)
			{
				cost = max({ cost, prefix[i] - prefix[idx - 1] + dfs(i + 2, div - 1) });
			}
			return dp[idx][div] = cost;
		};
	cout << dfs(1, m);
	return 0;
}
