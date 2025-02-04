#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, ll>mm;
	vector<string>tile;
	for (ll i = 1; i <= 9; ++i)
	{
		tile.push_back(to_string(i) + "m");
	}
	for (ll i = 1; i <= 9; ++i)
	{
		tile.push_back(to_string(i) + "p");
	}
	for (ll i = 1; i <= 9; ++i)
	{
		tile.push_back(to_string(i) + "s");
	}
	for (ll i = 1; i <= 7; ++i)
	{
		tile.push_back(to_string(i) + "z");
	}
	for (ll i = 0; i < tile.size(); ++i)
	{
		mm[tile[i]] = i;
	}
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		string str;
		cin >> str;
		i = mm[str];
	}
	vector<vector<ll>>pos(34);
	for (ll i = 0; i < n; ++i)
	{
		pos[v[i]].push_back(i);
	}
	ll ans = LLONG_MAX;
	for (ll i = 0; i < 34; ++i)
	{
		if (pos[i].size() < 5)
		{
			continue;
		}
		for (ll j = 0; j + 4 < pos[i].size(); ++j)
		{
			ans = min(ans, pos[i][j + 4] - pos[i][j] + 1LL);
		}
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}