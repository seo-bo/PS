#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<pll>s;
	ll n = 0, m = 0, ans = 0;
	cin >> n >> m;
	ans = n * n;
	vector<vector<ll>>dir = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
	for (int i = 0; i < m; ++i)
	{
		ll x = 0, y = 0;
		cin >> x >> y;
		s.insert(make_pair(x, y));
		for (int j = 0; j < 8; ++j)
		{
			int nx = x + dir[j][0];
			int ny = y + dir[j][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				s.insert(make_pair(nx, ny));
			}
		}
	}
	cout << ans - s.size();
	return 0;
}
