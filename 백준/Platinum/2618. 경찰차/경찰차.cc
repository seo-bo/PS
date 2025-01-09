#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, w = 0, p1 = 0, p2 = 1;
	cin >> n >> w;
	vector<pll>v(w + 2);
	v[0] = make_pair(1, 1), v[1] = make_pair(n, n);
	for (int i = 2; i <= w + 1; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<ll>> dp(w + 2, vector<ll>(w + 2, 0));
	auto gs = [&](pll a, pll b)->ll
		{
			return abs(a.first - b.first) + abs(a.second - b.second);
		};
	function<ll(int, int, int)> dfs = [&](int p1, int p2, int depth) -> ll
		{
			if (depth == w + 2)
			{
				return 0;
			}
			if (dp[p1][p2] != 0)
			{
				return dp[p1][p2];
			}
			ll d1 = gs(v[p1], v[depth]) + dfs(depth, p2, depth + 1);
			ll d2 = gs(v[p2], v[depth]) + dfs(p1, depth, depth + 1);
			return dp[p1][p2] = min(d1, d2);
		};
	cout << dfs(0, 1, 2) << '\n';
	for (int i = 2; i <= w + 1; ++i)
	{
		ll d1 = gs(v[p1], v[i]) + dp[i][p2];
		ll d2 = gs(v[p2], v[i]) + dp[p1][i];
		if (d1 < d2)
		{
			cout << 1 << '\n';
			p1 = i;
		}
		else
		{
			cout << 2 << '\n';
			p2 = i;
		}
	}
	return 0;
}