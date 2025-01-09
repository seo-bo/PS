#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<bool>ok(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		ok[temp] = true;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(100, -1));
	function<ll(int, int)> dfs = [&](int day, int pon)
		{
			if (day > n)
			{
				return 0LL;
			}
			if (dp[day][pon] != -1)
			{
				return dp[day][pon];
			}
			ll res = INT_MAX;
			if (ok[day])
			{
				res = min(res, dfs(day + 1, pon));
			}
			else
			{
				if (pon >= 3)
				{
					res = min(res, dfs(day + 1, pon - 3));
				}
				res = min({ res, dfs(day + 1, pon) + 10000, dfs(day + 3,pon + 1) + 25000, dfs(day + 5,pon + 2) + 37000 });
			}
			return dp[day][pon] = res;
		};
	cout << dfs(1, 0);
	return 0;
}
