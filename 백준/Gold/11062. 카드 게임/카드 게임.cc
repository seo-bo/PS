#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
		function<int(int, int)> dfs = [&](int left, int right)
			{
				if (left > right)
				{
					return 0;
				}
				if (dp[left][right] != -1)
				{
					return dp[left][right];
				}
				int cost = 0;
				cost = max(cost, v[left] + min(dfs(left + 2, right), dfs(left + 1, right - 1)));
				cost = max(cost, v[right] + min(dfs(left, right - 2), dfs(left + 1, right - 1)));
				return dp[left][right] = cost;
			};
		cout << dfs(1, n) << '\n';
	}
	return 0;
}