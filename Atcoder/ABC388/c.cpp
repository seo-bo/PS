#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll target = v[i] * 2;
		auto it = lower_bound(v.begin() + i + 1, v.end(), target);
		ans += distance(it, v.end());
	}
	cout << ans;
	return 0;
}
