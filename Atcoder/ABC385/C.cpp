#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(3001);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp].push_back(i);
	}
	int ans = 1;
	for (int i = 1; i <= 3000; ++i)
	{
		if (v[i].empty())
		{
			continue;
		}
		int res = 1;
		vector<int>dp(v[i].size() * (n + 1), 0);
		for (int j = 0; j < v[i].size(); ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				int diff = v[i][j] - v[i][k];
				if (diff <= 0 || diff > n)
				{
					continue;
				}
				int kdx = k * (n + 1) + diff;
				int jdx = j * (n + 1) + diff;
				if (dp[kdx] > 0)
				{
					dp[jdx] = dp[kdx] + 1;
				}
				else
				{
					dp[jdx] = 2;
				}
				res = max(dp[jdx], res);
			}
		}
		ans = max(res, ans);
	}
	cout << ans;
	return 0;
}
