#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, t = 0, k = 0;
	cin >> n >> k >> t;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		i %= k;
	}
	sort(v.begin(), v.end());
	ll cur = 0;
	while (t--)
	{
		ll temp = 0;
		cin >> temp;
		cur = (cur + temp) % k;
		auto it = upper_bound(v.begin(), v.end(), k - cur - 1);
		if (it == v.begin())
		{
			it = prev(v.end());
		}
		else
		{
			--it;
		}
		cout << (*it + cur) % k << ' ';
	}
	return 0;
}