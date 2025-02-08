#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i < (1 << n); ++i)
	{
		ll sour = 1, bitter = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				sour *= v[j].first;
				bitter += v[j].second;
			}
		}
		ans = min(ans, llabs(sour - bitter));
	}
	cout << ans;
	return 0;
}