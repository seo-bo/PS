#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0, k = 0;
	cin >> n >> q >> k;
	vector<ll>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	auto print = [&](ll a, ll b)
		{
			cout << min(a, b) << ' ' << max(a, b);
			exit(0);
		};
	auto part = [&](ll left, ll right)
		{
			ll x = v[right];
			ll l = left - 1;
			for (ll i = left; i < right; ++i)
			{
				if (v[i] <= x)
				{
					if (!(--k))
					{
						print(v[l + 1], v[i]);
					}
					swap(v[++l], v[i]);

				}
			}
			if (l + 1 != right)
			{
				if (!(--k))
				{
					print(v[l + 1], v[right]);
				}
				swap(v[l + 1], v[right]);
			}
			return l + 1;
		};
	function<ll(ll, ll, ll)> select = [&](ll left, ll right, ll qq)
		{
			if (left == right)
			{
				return v[left];
			}
			ll pp = part(left, right);
			ll pivot = pp - left + 1;
			if (qq < pivot)
			{
				if (pp - 1 >= left && pp - 1 < v.size())
				{
					return select(left, pp - 1, qq);
				}
			}
			else if (qq > pivot)
			{
				if (pp + 1 >= 0 && pp + 1 <= right)
				{
					return select(pp + 1, right, qq - pivot);
				}
			}
			else
			{
				if (pp >= 0 && pp < v.size())
				{
					return v[pp];
				}
			}
		};
	select(0, n - 1, q);
	cout << -1;
	return 0;
}