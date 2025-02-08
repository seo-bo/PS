#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;
typedef pair<lb, lb>plb;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<plb>a(2), b(2);
	for (auto& [i, j] : a)
	{
		cin >> i >> j;
	}
	for (auto& [i, j] : b)
	{
		cin >> i >> j;
	}
	auto ccw = [&](plb& a, plb& b, plb& c)
		{
			lb temp = a.first * b.second + b.first * c.second + c.first * a.second;
			temp -= a.second * b.first + b.second * c.first + c.second * a.first;
			return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
		};
	int xy = ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]);
	int yx = ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]);
	auto incc = [&]()
		{
			auto [x1, y1] = a[0];
			auto [x2, y2] = a[1];
			auto [x3, y3] = b[0];
			auto [x4, y4] = b[1];
			lb xpos = (x1 * y2 - y1 * x2) * (x3 - x4) - (x3 * y4 - y3 * x4) * (x1 - x2);
			lb ypos = (x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2);
			lb div = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (div == 0) // (1,1) (5,5) (5,5) (9,1) 
			{
				if (a[1] == b[0] && a[0] <= b[0]) // A (B == C) D
				{
					cout << x3 << ' ' << y3;
				}
				else if (a[0] == b[1] && b[0] <= a[0]) // C (D == A) B
				{
					cout << x4 << ' ' << y4;
				}
			}
			else
			{
				xpos /= div;
				ypos /= div;
				if (abs(xpos) < 1e-9)  // 부동 소숫점 오차 너무 싫어요..................
				{
					xpos = 0;
				}
				if (abs(ypos) < 1e-9)
				{
					ypos = 0;
				}
				cout << fixed << setprecision(15) << xpos << ' ' << ypos;
			}

		};
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
		if (a[0] <= b[1] && b[0] <= a[1])
		{
			cout << 1 << '\n';
			incc();
		}
		else
		{
			cout << 0;
		}
	}
	else if (xy <= 0 && yx <= 0)
	{
		cout << 1 << '\n';
		incc();
	}
	else
	{
		cout << 0 << '\n';
	}
	return 0;
}