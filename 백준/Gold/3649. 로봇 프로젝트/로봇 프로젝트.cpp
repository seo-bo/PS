#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll s = 0;
	while (cin >> s)
	{
		ll x = s * 10000000LL, n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		ll pre = -1;
		pii ans = make_pair(-1LL, -1LL);
		for (int i = 0; i < n; ++i)
		{
			if (v[i] > x / 2)
			{
				break;
			}
			if (v[i] == pre)
			{
				continue;
			}
			pre = v[i];
			ll pivot = llabs(x - v[i]);
			if (binary_search(v.begin() + i + 1, v.end(), pivot))
			{
				ans = make_pair(v[i], pivot);
				break;
			}
		}
		if (ans.first != -1)
		{
			cout << "yes" << ' ' << ans.first << ' ' << ans.second << '\n';
		}
		else
		{
			cout << "danger" << '\n';
		}
	}
	return 0;
}