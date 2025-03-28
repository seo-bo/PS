#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	auto sv = [&](vector<pll>& A, vector<pll>& B)
		{
			auto ccw = [&](pll a, pll b, pll c)
				{
					ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
					temp -= a.second * b.first + b.second * c.first + c.second * a.first;
					return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
				};
			ll xy = ccw(A[0], A[1], B[0]) * ccw(A[0], A[1], B[1]);
			ll yx = ccw(B[0], B[1], A[0]) * ccw(B[0], B[1], A[1]);
			if (!xy && !yx)
			{
				if (A[0] > A[1])
				{
					swap(A[0], A[1]);
				}
				else if (B[0] > B[1])
				{
					swap(B[0], B[1]);
				}
				return !(A[0] <= B[1] && A[1] >= B[0]);
			}
			return !(xy <= 0 && yx <= 0);
		};
	auto dist = [&](pll a, pll b)
		{
			return (ld)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
		};
	while (1)
	{
		vector<pll>A(2), B(2);
		int cnt = 0;
		for (auto& [a, b] : A)
		{
			cin >> a >> b;
			if (a == 0 && b == 0)
			{
				cnt++;
			}
		}
		if (cnt == 2)
		{
			break;
		}
		for (auto& [a, b] : B)
		{
			cin >> a >> b;
		}
		ld ans = 0;
		if (sv(A, B))
		{
			ans = dist(A[0], A[1]);
		}
		else
		{
			ld a = dist(A[0], B[0]) + dist(A[1], B[0]);
			ld b = dist(A[0], B[1]) + dist(A[1], B[1]);
			ans = min(a, b);
		}
		cout << format("Case {}: {:.3f}\n", t++, ans / (ld)2.0);
	}
	return 0;
}