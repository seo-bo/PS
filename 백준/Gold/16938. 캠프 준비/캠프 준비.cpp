#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0, r = 0, x = 0;
	cin >> n >> l >> r >> x;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		ll mini = LLONG_MAX, maxi = LLONG_MIN, cost = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				cost += v[j];
				mini = min(mini, v[j]);
				maxi = max(maxi, v[j]);
			}
		}
		if (l <= cost && cost <= r && maxi - mini >= x)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}