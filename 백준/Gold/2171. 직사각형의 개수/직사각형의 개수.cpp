#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	unordered_map<ll, unordered_set<ll>>pos;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		pos[a].insert(b);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			auto [ax, ay] = v[i];
			auto [bx, by] = v[j];
			if (ax == bx || ay == by)
			{
				continue;
			}
			ll cx = bx, cy = ay;
			ll dx = ax, dy = by;
			if (pos[cx].find(cy) != pos[cx].end() && pos[dx].find(dy) != pos[dx].end())
			{
				ans++;
			}
		}
	}
	cout << ans / 2;
	return 0;
}