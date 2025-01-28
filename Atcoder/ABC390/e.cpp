#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<vector<pll>>v(4);
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	vector<vector<ll>>dp(4, vector<ll>(x + 1, 0));
	for (int i = 1; i <= 3; ++i)
	{
		for (auto& [a, b] : v[i])
		{
			for (int j = x; j >= b; --j)
			{
				dp[i][j] = max(dp[i][j], dp[i][j - b] + a);
			}
		}
	}
	ll left = 0, right = LLONG_MAX / 2, ans = 0;
	auto cal = [&](int idx, ll mid)
		{
			for (int i = 0; i <= x; ++i)
			{
				if (dp[idx][i] >= mid)
				{
					return (ll)i;
				}
			}
			return LLONG_MAX;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll f1 = cal(1, mid), f2 = cal(2, mid), f3 = cal(3, mid);
		if (f1 == LLONG_MAX || f2 == LLONG_MAX || f3 == LLONG_MAX)
		{
			right = mid - 1;
			continue;
		}
		if (f1 + f2 + f3 <= x)
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
