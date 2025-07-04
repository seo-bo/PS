#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<ll>>v(n, vector<ll>(m));
	vector<ll>sum;
	for (auto& i : v)
	{
		ll s = 0;
		for (auto& j : i)
		{
			cin >> j;
			s += j;
		}
		sum.push_back(s);
	}
	ll pivot = LLONG_MAX, idx = -1;
	for (ll i = 0; i < n; ++i)
	{
		ll temp = k;
		ll cnt = temp / sum[i];
		temp -= cnt * sum[i];
		cnt *= m;
		for (ll j = 0; j < m && temp > 0; ++j)
		{
			temp -= v[i][j];
			cnt++;
		}
		if (cnt < pivot)
		{
			pivot = cnt;
			idx = i + 1;
		}
	}
	cout << idx << ' ' << pivot;
	return 0;
}