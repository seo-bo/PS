#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<pll>v(n);
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
			{
				return (a.first + a.second) > (b.first + b.second);
			});
		vector<ll>ans(2, 0);
		for (int i = 0; i < n; ++i)
		{
			if (!(i % 2))
			{
				ans[0] += v[i].first;
			}
			else
			{
				ans[1] += v[i].second;
			}
		}
		cout << ans[0] - ans[1] << '\n';
	}
	return 0;
}