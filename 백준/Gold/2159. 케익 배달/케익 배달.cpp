#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	map<pii, ll>dp;
	dp[make_pair(x, y)] = 0;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1}, {0,0} };
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		map<pii, ll>temp;
		for (auto& [pos, w] : dp)
		{
			auto [x, y] = pos;
			for (int j = 0; j < 5; ++j)
			{
				ll nx = a + dir[j][0];
				ll ny = b + dir[j][1];
				if (nx >= 1 && nx <= MAX && ny >= 1 && ny <= MAX)
				{
					ll dist = llabs(x - nx) + llabs(y - ny);
					pii p = make_pair(nx, ny);
					if (temp.find(p) == temp.end() || temp[p] > dp[make_pair(x, y)] + dist)
					{
						temp[p] = dp[make_pair(x, y)] + dist;
					}
				}
			}
		}
		dp = move(temp);
	}
	ll ans = LLONG_MAX;
	for (auto& [p, w] : dp)
	{
		ans = min(ans, w);
	}
	cout << ans;
	return 0;
}