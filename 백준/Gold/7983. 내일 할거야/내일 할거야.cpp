#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
	}
	sort(v.begin(), v.end());
	auto sv = [&](ll mid)
		{
			ll now = mid;
			for (auto& [a, b] : v)
			{
				now += b;
				if (now > a)
				{
					return false;
				}
			}
			return true;
		};
	ll left = 0, right = INT_MAX, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (sv(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}