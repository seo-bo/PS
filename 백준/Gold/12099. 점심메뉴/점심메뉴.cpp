#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<pll>menu(n);
	for (auto& [i, j] : menu)
	{
		cin >> i >> j;
	}
	sort(menu.begin(), menu.end());
	while (q--)
	{
		ll u = 0, v = 0, x = 0, y = 0, ans = 0;
		cin >> u >> v >> x >> y;
		auto left = lower_bound(menu.begin(), menu.end(), make_pair(u, LLONG_MIN));
		auto right = upper_bound(menu.begin(), menu.end(), make_pair(v, LLONG_MAX));
		for (auto it = left; it != right; ++it)
		{
			if (x <= it->second && it->second <= y)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}