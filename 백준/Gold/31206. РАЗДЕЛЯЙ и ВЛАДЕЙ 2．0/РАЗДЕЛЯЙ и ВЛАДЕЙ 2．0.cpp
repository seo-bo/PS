#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>v(n + 1, 0), pos(MAX + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		pos[v[i]] = i;
	}
	vector<vector<ll>> mul(MAX + 1), div(MAX + 1);
	for (int i = 1; i <= MAX; ++i)
	{
		for (int j = i; j <= MAX; j += i)
		{
			if (pos[j])
			{
				mul[i].push_back(pos[j]);
			}
			if (pos[i])
			{
				div[j].push_back(pos[i]);
			}
		}
	}
	for (int i = 1; i <= MAX; ++i)
	{
		if (!mul.empty())
		{
			sort(mul[i].begin(), mul[i].end());
		}
		if (!div.empty())
		{
			sort(div[i].begin(), div[i].end());
		}
	}
	while (q--)
	{
		ll l = 0, r = 0, d = 0;
		cin >> l >> r >> d;
		ll ans = 0;
		if (!mul[d].empty())
		{
			ll left = lower_bound(mul[d].begin(), mul[d].end(), l) - mul[d].begin();
			ll right = upper_bound(mul[d].begin(), mul[d].end(), r) - mul[d].begin();
			ans += right - left;
		}
		if (!div[d].empty())
		{
			ll left = lower_bound(div[d].begin(), div[d].end(), l) - div[d].begin();
			ll right = upper_bound(div[d].begin(), div[d].end(), r) - div[d].begin();
			ans += right - left;
		}
		if (l <= pos[d] && pos[d] <= r)
		{
			ans--;
		}
		cout << ans << '\n';
	}
	return 0;
}