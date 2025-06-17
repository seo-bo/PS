#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, temp = 0;
	cin >> n >> k;
	vector<bool>ban(n + 1, false);
	while (cin >> temp)
	{
		ban[temp] = true;
	}
	vector<int>dp(n + 1, -1);
	function<int(int)> dfs = [&](int idx)
		{
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			int res = 0;
			for (int i = idx + 1; i <= min(n, idx + k); ++i)
			{
				if (ban[i])
				{
					continue;
				}
				res |= (dfs(i) ^ 1);
			}
			return dp[idx] = res;
		};
	dfs(0);
	vector<int>ans(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		int ok = -1, p1 = INT_MAX, p2 = INT_MIN;
		for (int j = min(n, i + k); j >= i + 1; --j)
		{
			if (ban[j])
			{
				continue;
			}
			ok = j;
			if (!dp[j])
			{
				p1 = min(p1, ans[j] + 1);
			}
			else
			{
				p2 = max(p2, ans[j] + 1);
			}
		}
		if (ok == -1)
		{
			continue;
		}
		ans[i] = (dp[i]) ? p1 : p2;
	}
	cout << ans[0];
	return 0;
}