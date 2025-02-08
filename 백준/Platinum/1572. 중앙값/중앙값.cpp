#include <bits/stdc++.h>
#define MAX 65537
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>BIT(MAX + 1, 0);
	auto update = [&](ll x, ll delta)
		{
			x++;
			while (x <= MAX)
			{
				BIT[x] += delta;
				x += x & -x;
			}
		};
	auto query = [&](ll x)
		{
			x++;
			ll res = 0;
			while (x > 0)
			{
				res += BIT[x];
				x -= x & -x;
			}
			return res;
		};
	auto find = [&](ll x)
		{
			ll left = 0, right = MAX;
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if (query(mid) >= x)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			return left;
		};
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (ll i = 0; i < k; ++i)
	{
		update(v[i], 1);
	}
	ll mid = (k + 1) / 2;
	ll ans = find(mid);
	for (ll i = k; i < n; ++i)
	{
		update(v[i - k], -1);
		update(v[i], 1);
		ans += find(mid);
	}
	cout << ans;
	return 0;
}
