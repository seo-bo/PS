#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, maxi = -1;
	cin >> n >> k;
	vector<ll>A(n), B(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i] >> B[i];
		maxi = max(maxi, B[i]);
	}
	ll left = 1, right = maxi, res = 0;
	auto sv = [&](ll mid)
		{
			ll cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				if (B[i] >= mid)
				{
					ll temp = (B[i] - mid) / A[i] + 1;
					cnt += temp;
					if (cnt >= k)
					{
						return cnt;
					}
				}
			}
			return cnt;
		};
	auto cal = [&](ll a, ll b, ll c)
		{
			return c * a - b * ((c * (c - 1)) / 2);
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = sv(mid);
		if (cnt >= k)
		{
			left = mid + 1;
			res = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	ll p1 = 0, p2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (B[i] >= res + 1)
		{
			ll temp = (B[i] - res - 1) / A[i] + 1;
			if (temp > 0)
			{
				p1 += temp;
				p2 += cal(B[i], A[i], temp);
			}
		}
	}
	cout << p2 + (k - p1) * res;
	return 0;
}