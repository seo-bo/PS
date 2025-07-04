#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
	vector<pii>cost(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		auto& [a, b] = cost[i];
		cin >> a >> b;
	}
	function<ll(ll, ll)> dfs = [&](ll idx, ll div)
		{
			if (idx == n + 1)
			{
				if (div != m)
				{
					return (ll)INT_MIN;
				}
				return 0LL;
			}
			if (div == m)
			{
				return (ll)INT_MIN;
			}
			if (dp[idx][div] != -1)
			{
				return dp[idx][div];
			}
			ll res = 0, pivot = 0, power = 0;
			for (ll i = idx; i <= n; ++i)
			{
				auto [a, b] = cost[i];
				if (a > pivot)
				{
					pivot = a;
					power = b;
				}
				else if (a == pivot)
				{
					power += b;
				}
				res = max(res, dfs(i + 1, div + 1) + power);
			}
			return dp[idx][div] = res;
		};
	cout << dfs(1LL, 0LL);
	return 0;
}