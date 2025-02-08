#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, T = 0;
	cin >> n >> T;
	vector<vector<ll>>cost(4, vector<ll>(n + 1, 0));
	vector<vector<pll>>pivot(4, vector<pll>(1, make_pair(0, 0)));
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <= 3; ++i)
	{
		ll sum = 0, t = 0;
		for (int j = 1; j <= n; ++j)
		{
			ll temp = 0;
			cin >> temp;
			sum += cost[i][j], t += temp;
			if (pivot[i].back().first < sum)
			{
				pivot[i].push_back(make_pair(sum, t));
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < pivot[1].size(); ++i)
	{
		ll sum = pivot[1][i].first, t1 = pivot[1][i].second;
		if (t1 > T)
		{
			continue;
		}
		ll re = T - t1;
		int left = 0, right = pivot[3].size() - 1;
		while (left < pivot[2].size() && right >= 0)
		{
			ll tt = pivot[2][left].second + pivot[3][right].second;
			if (tt > re)
			{
				right--;
			}
			else
			{
				ans = max(ans, sum + pivot[2][left].first + pivot[3][right].first);
				left++;
			}
		}
	}
	cout << ans;
	return 0;
}