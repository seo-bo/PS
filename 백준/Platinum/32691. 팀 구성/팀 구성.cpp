#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin() + 1, v.end()); // f 목표등수, s 실력
	vector<ll>dp(n + 1, -1);
	function<ll(int)> dfs = [&](int idx)
		{
			if (idx > n)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = dfs(idx + 1);
			for (int i = idx; i <= min(idx + 4, n); ++i)
			{
				for (int j = i + 1; j <= min(idx + 4, n); ++j)
				{
					for (int z = j + 1; z <= min(idx + 4, n); ++z)
					{
						if (llabs(v[i].first - v[z].first) > k)
						{
							continue;
						}
						res = max(res, dfs(z + 1) + v[i].second + v[j].second + v[z].second);
					}
				}
			}
			return dp[idx] = res;
		};
	cout << dfs(1);
	return 0;
}