#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	ll ans = 0;
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			ll p1 = -a.first + a.second;
			ll p2 = -b.first + b.second;
			if (p1 == p2)
			{
				return a.first < b.first;
			}
			return p1 > p2;
		});
	for (int i = 0; i < n; ++i)
	{
		if (i < a)
		{
			ans += v[i].first;
		}
		else
		{
			ans += v[i].second;
		}
	}
	cout << ans;
	return 0;
}