#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	vector<vector<int>>dp(1 << n, vector<int>(n, -1));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	function<int(int, int)> solve = [&](int mask, int num) ->int
		{
			if (mask == (1 << n) - 1)
			{
				return v[num][0] ? v[num][0] : INF;
			}
			if (dp[mask][num] != -1)
			{
				return dp[mask][num];
			}
			int ans = INF;
			for (int i = 0; i < n; ++i)
			{
				if (!(mask & (1 << i)) && v[num][i])
				{
					int sum = solve(mask | (1 << i), i);
					if (sum != INF)
					{
						ans = min(ans, sum + v[num][i]);
					}
				}
			}
			return dp[mask][num] = ans;
		};
	cout << solve(1, 0);
	return 0;
}