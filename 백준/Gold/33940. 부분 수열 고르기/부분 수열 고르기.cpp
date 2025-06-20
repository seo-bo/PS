#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 0, d = 0, m = 0;
	cin >> n >> a >> d >> m;
	vector<ll>prefix(n + 1, 0);
	prefix[1] = a;
	for (int i = 2; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + d;
	}
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] += prefix[i - 1];
	}
	for (int i = n; i >= 1; --i)
	{
		ll left = prefix[i], right = prefix[n] - prefix[n - i];
		if (left <= m && m <= right && (m - left) % d == 0)
		{
			cout << i << '\n';
			vector<ll>ans;
			ll pivot = (m - left) / d, ed = n;
			for (int j = i; j >= 1; --j)
			{
				if (pivot)
				{
					ll p = min(pivot, ed - j);
					pivot -= p;
					ans.push_back(a + (j + p - 1) * d);
					ed = j + p - 1;
				}
				else
				{
					ans.push_back(a + (j - 1) * d);
				}
			}
			for (int j = i - 1; j >= 0; --j)
			{
				cout << ans[j] << ' ';
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}