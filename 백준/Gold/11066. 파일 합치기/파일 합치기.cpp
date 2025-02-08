#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[501][501] = { 0, };
ll cost[501] = { 0, }, prefix[501] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0;
		cin >> num;
		for (int i = 1; i <= num; ++i)
		{
			cin >> cost[i];
			prefix[i] = prefix[i - 1] + cost[i];
		}
		for (int i = 2; i <= num; ++i)
		{
			for (int j = 1; j <= num - i + 1; ++j)
			{
				int k = i + j - 1;
				dp[j][k] = LLONG_MAX;
				for (int z = j; z < k; ++z)
				{
					dp[j][k] = min(dp[j][k], dp[j][z] + dp[z + 1][k] + prefix[k] - prefix[j - 1]);
				}
			}
		}
		cout << dp[1][num] << "\n";
	}
	return 0;
}
