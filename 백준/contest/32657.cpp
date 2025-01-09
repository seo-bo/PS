#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	bool a1 = false, a2 = true;
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<bool>>dp(n + 1, vector<bool>(101, true));
	dp[1][0] = false;
	for (int i = 1; i <= 99; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			auto [l, r] = v[j];
			if (j == 1)
			{
				dp[j][i] = dp[l][i - 1] || dp[r][i - 1];
			}
			else
			{
				dp[j][i] = dp[l][i - 1] && dp[r][i - 1];
			}
		}
	}
	for (int i = 10; i <= 99; ++i)
	{
		if (dp[1][i])
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
