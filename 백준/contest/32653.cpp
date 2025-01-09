#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<bool>check(51, false);
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		ll p = 2LL * temp;
		if (p <= 50)
		{
			check[p] = true;
		}
	}
	vector<ll>v;
	for (int i = 2; i <= 50; i += 2)
	{
		if (check[i])
		{
			v.push_back(i);
		}
	}
	ll ans = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		ans = lcm(ans, v[i]);
	}
	cout << ans;
	return 0;
}
