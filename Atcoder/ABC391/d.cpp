#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, w = 0, q = 0;
	cin >> n >> w;
	vector<vector<pll>>v(w + 1);
	for (ll i = 1; i <= n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		v[a].push_back(make_pair(b, i));
	}
	ll len = INT_MAX;
	for (ll i = 1; i <= w; ++i)
	{
		sort(v[i].begin(), v[i].end());
		len = min(len, (ll)v[i].size());
	}
	cin >> q;
	if (!len)
	{
		while (q--)
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			cout << "Yes" << '\n';
		}
		return 0;
	}
	ll pre = 0;
	vector<ll>die(n + 1, LLONG_MAX);
	for (ll i = 0; i < len; ++i)
	{
		ll temp = LLONG_MIN;
		for (ll j = 1; j <= w; ++j)
		{
			temp = max({ temp, v[j][i].first, pre + 1 });
		}
		for (int j = 1; j <= w; ++j)
		{
			die[v[j][i].second] = temp;
		}
		pre = temp;
	}
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a >= die[b])
		{
			cout << "No" << '\n';
		}
		else
		{
			cout << "Yes" << '\n';
		}
	}
	return 0;
}
