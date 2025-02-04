#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, _ = 0, __ = 0, m = 0, s = 0, ans = LLONG_MAX;
	cin >> n >> _ >> __ >> m >> s;
	ll p1 = min(_, __);
	ll p2 = max(_, __);
	ll a = llabs(m - p1) % 2, b = (m - p2) % 2;
	if (!a && !b)
	{
		cout << -1;
		return 0;
	}
	if (p2 < m) // 반죽이 전부 왼쪽에
	{
		if (b)
		{
			if (s != 1)
			{
				ans = llabs(p2 - m);
				if (s > m)
				{
					ans += llabs(s - m);
				}
				else if (s < m)
				{
					if (p1 >= s)
					{
						ans += llabs(p1 - s) + 1;
					}
					ans += llabs(s - m);
				}
			}
		}
		else if (a)
		{
			if (m != n && s != n)
			{
				ans = llabs(p1 - m) + llabs(p2 - m) + 1;
				if (s > m)
				{
					ans += 2 * llabs(s - m);
				}
				else if (s < m)
				{
					ans += llabs(s - m);
				}
			}
		}
	}
	else if (p1 > m) // 반죽이 전부 오른쪽에
	{
		if (a)
		{
			if (s != n)
			{
				ans = llabs(p1 - m);
				if (s > m)
				{
					if (p2 <= s)
					{
						ans += llabs(s - p2) + 1;
					}
					ans += llabs(m - s);
				}
				else if (s < m)
				{
					ans += llabs(s - m);
				}
			}
		}
		else if (b)
		{
			if (m != 1 && s != 1)
			{
				ans = llabs(p1 - m) + llabs(p2 - m) + 1;
				if (s > m)
				{
					ans += llabs(m - s);
				}
				else if (s < m)
				{
					ans += 2 * llabs(m - s);
				}
			}
		}
	}
	else
	{
		ll res1 = LLONG_MAX, res2 = LLONG_MAX;
		if (a)
		{
			if ((s < m || (s > m && s != n) || s == m) && m != n)
			{
				res1 = llabs(p1 - m);
				if (s < m)
				{
					res1 += llabs(s - m);
				}
				else if (s > m)
				{
					if (p2 <= s)
					{
						res1 += llabs(s - p2) + 1;
					}
					res1 += llabs(s - m);
				}
			}
		}
		if (b)
		{
			if ((s > m || (s < m && s != 1) || s == m) && m != 1)
			{
				res2 = llabs(p2 - m);
				if (s < m)
				{
					if (p1 >= s)
					{
						res2 += llabs(s - p1) + 1;
					}
					res2 += llabs(s - m);
				}
				else if (s > m)
				{
					res2 += llabs(s - m);
				}
			}
		}
		ans = min(res1, res2);
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}