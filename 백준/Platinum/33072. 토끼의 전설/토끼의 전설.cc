#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 0, b = 0, sum = 0;
	cin >> n;
	vector<pll>v(n + 1);
	for (ll i = 1; i <= n; ++i) // 체력
	{
		cin >> v[i].second;
	}
	for (ll i = 1; i <= n; ++i) // 공격력
	{
		cin >> v[i].first;
		sum += v[i].first;
	}
	cin >> a >> b;
	auto cal = [&](ll pa, ll pb)
		{
			return pa * b - pb * a;
		};
	vector<ll>dp(sum + 1, 0);
	for (ll i = 1; i <= n; ++i)
	{
		auto& [pa, pb] = v[i];
		ll cost = cal(pa, pb);
		for (ll j = sum; j >= pa && cost > 0; --j)
		{
			dp[j] = max(dp[j], dp[j - pa] + cal(pa, pb));
		}
	}
	map<ll, ll>per;
	for (ll i = 1; i <= sum; ++i)
	{
		if (dp[i] > 0)
		{
			if (per.find(dp[i]) == per.end())
			{
				per[dp[i]] = i;
			}
			else
			{
				per[dp[i]] = min(per[dp[i]], i);
			}
		}
	}
	ll q = 0;
	cin >> q;
	while (q--)
	{
		ll pa = 0, pb = 0;
		cin >> pb >> pa;
		if (cal(pa, pb) >= 0)
		{
			cout << 0 << '\n';
			continue;
		}
		ll target = -cal(pa, pb);
		auto it = per.lower_bound(target);
		if (it == per.end())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << it->second << '\n';
		}
	}
	return 0;
}