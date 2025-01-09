#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pll>a(2), b(2);
	for (auto& [i, j] : a)
	{
		cin >> i >> j;
	}
	for (auto& [i, j] : b)
	{
		cin >> i >> j;
	}
	
	auto ccw = [&](pll& a, pll& b, pll& c)
		{
			ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
			temp -= a.second * b.first + b.second * c.first + c.second * a.first;
			return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
		};
	int xy = ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]);
	int yx = ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]);
	if (!xy && !yx)
	{
		if (a[0] > a[1])
		{
			swap(a[0], a[1]);
		}
		if (b[0] > b[1])
		{
			swap(b[0], b[1]);
		}
		cout << (a[0] <= b[1] && b[0] <= a[1]);
		return 0;
	}
	cout << (xy <= 0 && yx <= 0);
	return 0;
}