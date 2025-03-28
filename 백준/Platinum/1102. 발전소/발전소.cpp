#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>cost(n, vector<int>(n, 0));
	for (auto& i : cost)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	string str;
	cin >> str;
	int mask = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'Y')
		{
			mask |= (1 << i);
		}
	}
	int P = 0;
	cin >> P;
	if (__builtin_popcount(mask) == 0 && P > 0)
	{
		cout << -1;
		return 0;
	}
	if (__builtin_popcount(mask) >= P)
	{
		cout << 0;
		return 0;
	}
	vector<int>dp(1 << n, INT_MAX);
	dp[mask] = 0;
	int ans = INT_MAX;
	for (int i = 0; i < (1 << n); ++i)
	{
		if (__builtin_popcount(i) >= P || dp[i] == INT_MAX)
		{
			continue;
		}
		for (int j = 0; j < n; ++j)
		{
			if (!(i & (1 << j)))
			{
				continue;
			}
			for (int k = 0; k < n; ++k)
			{
				if (i & (1 << k))
				{
					continue;
				}
				int nxt = i | (1 << k);
				dp[nxt] = min(dp[nxt], dp[i] + cost[j][k]);
				if (__builtin_popcount(nxt) >= P)
				{
					ans = min(ans, dp[nxt]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}