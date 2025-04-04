#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
	vector<int>per(n, 0);
	iota(per.begin(), per.end(), 0);
	ld ans = numeric_limits<ld>::max();
	auto dist = [&](pll a, pll b)
		{
			return (ld)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
		};
	auto cal = [&]()
		{
			int x = per[0];
			ld temp = 0;
			for (int i = 1; i < n; ++i)
			{
				temp += dist(v[x], v[per[i]]);
				x = per[i];
			}
			temp += dist(v[x], v[per[0]]);
			ans = min(ans, temp);
		};
	do
	{
		cal();
	} while (next_permutation(per.begin(), per.end()));
	if (ans == numeric_limits<ld>::max())
	{
		cout << "-1";
		return 0;
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}