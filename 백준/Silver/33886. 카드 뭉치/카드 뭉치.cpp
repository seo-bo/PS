#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 4, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>dp(n + 4, -1);
	function<int(int)> dfs = [&](int idx)
		{
			if (idx > n)
			{
				return 0;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			int res = (1 << 20), p = min(n, idx + v[idx] - 1);
			for (int i = idx; i <= p; ++i)
			{
				res = min(res, dfs(i + 1));
			}
			return dp[idx] = res + 1;
		};
	cout << dfs(1);
	return 0;
}