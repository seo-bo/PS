#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>prefix(n + 3);
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	vector<ll>dp(n + 3, -1);
	function<ll(int)> dfs = [&](int i)
		{
			if (i == n + 1)
			{
				return 0LL;
			}
			if (dp[i] != -1)
			{
				return dp[i];
			}
			ll res = LLONG_MAX / 8;
			for (int a = i; a <= n; ++a)
			{
				ll cost = prefix[a] - prefix[i - 1] + (a - i);
				if (cost > m)
				{
					break;
				}
				cost = (m - cost) * (m - cost);
				if (a == n)
				{
					cost = 0;
				}
				res = min(res, dfs(a + 1) + cost);
			}
			return dp[i] = res;
		};
	cout << dfs(1);
	return 0;
}