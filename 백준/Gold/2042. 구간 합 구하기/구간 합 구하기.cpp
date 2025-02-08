#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>BIT(n + 2, 0);
	auto update = [&](int idx, ll delta)
		{
			while (idx <= n)
			{
				BIT[idx] += delta;
				idx += (idx) & (-idx);
			}
		};
	auto query = [&](int idx)
		{
			ll res = 0;
			while (idx > 0)
			{
				res += BIT[idx];
				idx -= (idx) & (-idx);
			}
			return res;
		};
	auto sum = [&](int left, int right)
		{
			return query(right) - query(left - 1);
		};
	vector<ll>temp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp[i];
		update(i, temp[i]);
	}
	int q = m + k;
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b, -temp[b]);
			temp[b] = c;
			update(b, temp[b]);
		}
		else
		{
			cout << sum(b, c) << '\n';
		}
	}
	return 0;
}