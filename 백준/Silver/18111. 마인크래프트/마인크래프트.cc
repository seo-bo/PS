#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, b = 0;
	cin >> n >> m >> b;
	ll anst = LLONG_MAX;
	ll ansh = LLONG_MAX;
	int start = INT_MAX;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			start = min(start, v[i][j]);
		}
	}
	for (int i = start; i <= 256; ++i) // target
	{
		int make = 0, era = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				int h = v[j][k] - i;
				(h > 0) ? era += h : make -= h;
			}
		}
		if (era + b >= make)
		{
			int t = era * 2 + make;
			if (anst >= t)
			{
				anst = t;
				ansh = i;
			}
		}
	}
	cout << anst << ' ' << ansh;
	return 0;
}