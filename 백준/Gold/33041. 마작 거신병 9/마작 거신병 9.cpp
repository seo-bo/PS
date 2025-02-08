#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll h = 0, c = 0, d = 0;
	cin >> h;
	vector<ll>v(h, 0), a(h, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> c >> d;
	for (int i = 1; i < h; ++i)
	{
		ll pre = v[i - 1] + 8 * a[i - 1];
		ll nd = pre + 1;
		ll diff = nd - v[i];
		ll num = ((diff <= 0) ? 0 : (diff + 7) / 8);
		if (num > v[i])
		{
			cout << -1;
			return 0;
		}
		a[i] = num;
	}
	ll sum = 0;
	for (auto& i : a)
	{
		sum += i;
	}
	if (sum > d)
	{
		cout << -1;
		return 0;
	}
	ll ov = d - sum;
	for (int i = h - 1; i >= 0; --i)
	{
		if (i == h - 1)
		{
			ll pivot = v[i] - a[i];
			a[i] += min(pivot, ov);
			ov -= min(pivot, ov);
		}
		else
		{
			ll nxt = v[i + 1] + 8 * a[i + 1];
			ll cur = v[i] + 8 * a[i];
			ll pp = nxt - cur;
			ll pivot = ((pp <= 1) ? 0 : (pp - 1) / 8);
			ll num = min({ ov,pivot,v[i] - a[i] });
			if (num > 0)
			{
				a[i] += num;
				ov -= num;
			}
		}
	}
	if (ov)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i + 1 < h; ++i)
	{
		ll aa = v[i] + 8 * a[i];
		ll bb = v[i + 1] + 8 * a[i + 1];
		if (aa >= bb)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < a[i]; ++j)
		{
			cout << 9 << ' ';
		}
		for (int j = 0; j < v[i] - a[i]; ++j)
		{
			cout << 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}