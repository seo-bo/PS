#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>s1(n + 2, 0), s2(n + 2, 0);
	s1[n] = 1, s2[n] = 1;
	for (int i = n - 1; i >= 1; --i)
	{
		if (v[i] == v[i + 1])
		{
			s1[i] = s1[i + 1] + 1;
		}
		else
		{
			s1[i] = 1;
		}
	}
	for (int i = n - 1; i >= 1; --i)
	{
		s2[i] = max(s1[i], s2[i + 1]);
	}
	ll ans = 1, cur = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (v[i] == v[i - 1])
		{
			ans = max(ans, ++cur);
		}
		else
		{
			cur = 1;
		}
	}
	vector<int>p1(n + 1, 0), p2(n + 1, 0);
	int pre = -1;
	for (int i = 1; i <= n; ++i)
	{
		int rev = 1 - v[i];
		if (i == 1)
		{
			p1[i] = 1;
		}
		else
		{
			if (rev == pre)
			{
				p1[i] = p1[i - 1] + 1;
			}
			else
			{
				p1[i] = 1;
			}
		}
		pre = rev;
		if (i == 1)
		{
			p2[i] = p1[i];
		}
		else
		{
			p2[i] = max(p2[i - 1], p1[i]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		ll f1 = p2[i], f2 = 0, f3 = 0;
		if (i < n)
		{
			f2 = s2[i + 1];
			ll tt = 1 - v[i];
			if (tt == v[i + 1])
			{
				f3 = p1[i] + s1[i + 1];
			}
		}
		ans = max({ ans,f1,f2,f3 });
	}
	cout << ans;
	return 0;
}
