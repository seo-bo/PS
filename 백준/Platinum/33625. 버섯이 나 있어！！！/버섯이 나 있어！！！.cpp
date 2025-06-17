#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, pivot = 0, zero = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		if (!i)
		{
			zero++;
		}
	}
	if (zero)
	{
		cout << n - zero;
		return 0;
	}
	pivot = v[0];
	for (ll i = 1; i < n; ++i)
	{
		pivot &= v[i];
	}
	if (pivot)
	{
		cout << -1;
		return 0;
	}
	map<ll, ll>mm; // 0이 있나?
	ll left = 0, right = 0;
	ll ans = LLONG_MAX;
	while (left < n)
	{
		while (right < n && mm.size() != 31)
		{
			for (ll i = 0; i < 31; ++i)
			{
				if (!(v[right] & (1LL << i)))
				{
					mm[i]++;
				}
			}
			right++;
		}
		if (mm.size() == 31)
		{
			ans = min(ans, right - left - 1);
		}
		for (ll i = 0; i < 31; ++i)
		{
			if (!(v[left] & (1LL << i)))
			{
				if (--mm[i] == 0)
				{
					mm.erase(i);
				}
			}
		}
		left++;
	}
	cout << ans + n - 1;
	return 0;
}