#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, t = 0;
	cin >> n >> t;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	ll ans = 0, pivot = LLONG_MIN;
	for (auto& [a, b] : v)
	{
		ll p = 0;
		if (pivot != LLONG_MIN)
		{
			p = min(pivot - t * a, b);
		}
		ans += max(p, 0LL);
		pivot = max(pivot, b + t * a);
	}
	cout << ans;
	return 0;
}