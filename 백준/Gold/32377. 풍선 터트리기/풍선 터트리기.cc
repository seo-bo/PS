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
	ll n = 0, x = 0, y = 0, z = 0;
	cin >> n >> x >> y >> z;
	ll left = 1, right = (1LL << 62);
	ll pivot = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = mid / x + mid / y + mid / z;
		if (cnt >= n)
		{
			pivot = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	ll aa = (pivot - 1) / x, bb = (pivot - 1) / y, cc = (pivot - 1) / z;
	ll atime = aa * x, btime = bb * y, ctime = cc * z;
	n -= aa + bb + cc;
	vector<pll>v = { {atime,x}, {btime,y}, {ctime,z} };
	ll ans = -1;
	while (n)
	{
		ll idx = -1, p = LLONG_MAX;
		for (int i = 0; i < 3; ++i)
		{
			if (p > v[i].first + v[i].second)
			{
				p = v[i].first + v[i].second;
				idx = i;
			}
		}
		v[idx].first += v[idx].second;
		n--;
		ans = idx;
	}
	cout << (char)('A' + ans) << " win";
	return 0;
}