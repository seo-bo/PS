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
		int a = 0, b = 0;
		cin >> a >> b;
		vector<vector<vector<int>>>dp(11, vector<vector<int>>(101, vector<int>(101, -1)));
		function<int(int, int, int)> dfs = [&](int idx, int left, int right)
			{
				if (idx == 0)
				{
					return (int)1e7;
				}
				if (idx == 1)
				{
					return right * (right + 1) / 2 - left * (left + 1) / 2;
				}
				if (left == right)
				{
					return 0;
				}
				if (dp[idx][left][right] != -1)
				{
					return dp[idx][left][right];
				}
				int res = 1e7;
				for (int i = left; i < right; ++i)
				{
					res = min(res, i + 1 + max(dfs(idx - 1, left, i), dfs(idx, i + 1, right)));
				}
				return dp[idx][left][right] = res;
			};
		cout << dfs(a, 0, b) << '\n';
	}
	return 0;
}