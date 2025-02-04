#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll h = 0, w = 0, c = 0, d = 0;
	cin >> h >> w >> c >> d;
	if (h > w + 1)
	{
		cout << -1;
		return 0;
	}
	ll mini = h * (h - 1) / 2;
	ll maxi = h * w - mini;
	if (d < mini || d > maxi)
	{
		cout << -1;
		return 0;
	}
	vector<ll>v(h);
	iota(v.begin(), v.end(), 0);
	ll ov = d - mini;
	for (int i = h - 1; i >= 0; --i)
	{
		ll up = 0;
		if (i == h - 1)
		{
			up = w;
		}
		else
		{
			up = v[i + 1] - 1;
		}
		ll pivot = up - v[i];
		v[i] += min(pivot, ov);
		ov -= min(pivot, ov);
	}
	if (ov)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < v[i]; ++j)
		{
			cout << 9 << ' ';
		}
		for (int j = 0; j < w - v[i]; ++j)
		{
			cout << 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}