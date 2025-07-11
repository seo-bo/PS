#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
		b = min(b, n);
	}
	vector<tp>dp(n + 1, make_tuple(LLONG_MAX, LLONG_MAX, 0));
	// 누적 금액, 직전 음식, cnt
	dp[0] = make_tuple(0, 0, 0);
	for (int i = 1; i <= m; ++i)
	{
		auto [a, b] = v[i];
		for (int k = n; k >= 1; --k)
		{
			for (int j = 1; j <= b && k - j >= 0; ++j)
			{
				auto [pa, pb, pc] = dp[k];
				if (get<0>(dp[k - j]) == LLONG_MAX)
				{
					continue;
				}
				ll cost = ((pa == LLONG_MAX) ? pa : pa * pc);
				ll sum = get<0>(dp[k - j]) + a * j, cnt = get<2>(dp[k - j]);
				if (get<1>(dp[k - j]) != i)
				{
					cnt++;
				}
				if (cost > sum * cnt)
				{
					dp[k] = make_tuple(sum, i, cnt);
				}
			}
		}
	}
	cout << get<0>(dp[n]) * get<2>(dp[n]);
	return 0;
}