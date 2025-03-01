#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, sum = 0;
	cin >> n >> x;
	vector<pll>v(n);
	ll right = LLONG_MAX;
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		sum += a + b;
		right = min(right, a + b);
	}
	auto cal = [&](ll mid)
		{
			ll a = max(1LL, mid - v[0].second), b = max(mid - 1LL, v[0].first);
			for (int i = 1; i < n && a <= b; ++i)
			{
				a = max(a - x, max(1LL, mid - v[i].second));
				b = min(b + x, min(mid - 1LL, v[i].first));
			}
			return (a <= b);
		};
	ll left = 2, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << sum - ans * n;
	return 0;
}
