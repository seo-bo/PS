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
	vector<pll>x(2), y(2);
	for (auto& [a, b] : x)
	{
		cin >> a >> b;
	}
	for (auto& [a, b] : y)
	{
		cin >> a >> b;
	}
	auto ccw = [&](pll& a, pll& b, pll& c)
		{
			ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
			temp -= a.second * b.first + b.second * c.first + c.second * a.first;
			return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
		};
	ll xy = ccw(x[0], x[1], y[0]) * ccw(x[0], x[1], y[1]);
	ll yx = ccw(y[0], y[1], x[0]) * ccw(y[0], y[1], x[1]);
	if (!xy && !yx)
	{
		if (x[0] > x[1])
		{
			swap(x[0], x[1]);
		}
		if (y[0] > y[1])
		{
			swap(y[0], y[1]);
		}
		cout << (y[0] <= x[1] && x[0] <= y[1]);
		return 0;
	}
	cout << (xy <= 0 && yx <= 0);
	return 0;
}