#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>r(3), s(3), t(3);
	ll q = 0, n = 0, a = 0;
	cin >> n >> a;
	if (gcd(n, a) != 1)
	{
		cout << n - a << ' ' << -1;
		return 0;
	}
	r[1] = n, r[2] = a, s[1] = t[2] = 1;
	while (1)
	{
		q = r[1] / r[2];
		r[0] = r[1] - q * r[2], s[0] = s[1] - q * s[2], t[0] = t[1] - q * t[2];
		if (!r[0])
		{
			while (t[2] <= 0)
			{
				t[2] += n;
			}
			cout << n - a << ' ' << t[2];
			return 0;
		}
		r[1] = r[2], r[2] = r[0], s[1] = s[2], s[2] = s[0], t[1] = t[2], t[2] = t[0];
	}
	return 0;
}
