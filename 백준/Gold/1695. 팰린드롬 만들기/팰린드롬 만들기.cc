#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	function<int(int, int)> dfs = [&](int left, int right)
		{
			if (left >= right)
			{
				return 0;
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			int res = 0;
			if (v[left] == v[right])
			{
				res = dfs(left + 1, right - 1);
			}
			else
			{
				res = 1 + min(dfs(left + 1, right), dfs(left, right - 1));
			}
			return dp[left][right] = res;
		};
	cout << dfs(1, n);
	return 0;
}