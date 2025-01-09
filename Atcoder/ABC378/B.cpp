#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		auto [x, y] = v[a - 1];
		if (b % x == y)
		{
			cout << b << '\n';
		}
		else
		{
			cout << b + (y - b % x + x) % x << '\n';
		}
	}
	return 0;
}
