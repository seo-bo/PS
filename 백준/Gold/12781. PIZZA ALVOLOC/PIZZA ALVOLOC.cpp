#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pll>A(2), B(2);
	for (auto& [a, b] : A)
	{
		cin >> a >> b;
	}
	for (auto& [a, b] : B)
	{
		cin >> a >> b;
	}
	auto ccw = [&](pll a, pll b, pll c)
		{
			ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
			temp -= a.second * b.first + b.second * c.first + c.second * a.first;
			return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
		};
	ll xy = ccw(A[0], A[1], B[0]) * ccw(A[0], A[1], B[1]);
	ll yx = ccw(B[0], B[1], A[0]) * ccw(B[0], B[1], A[1]);
	cout << (xy < 0 && yx < 0);
	return 0;
}