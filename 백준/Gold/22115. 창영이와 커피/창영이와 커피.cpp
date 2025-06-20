#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>dp(k + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		for (int j = k; j >= temp; --j)
		{
			if (dp[j - temp] != INT_MAX)
			{
				dp[j] = min(dp[j], dp[j - temp] + 1);
			}
		}
	}
	cout << ((dp[k] == INT_MAX) ? -1 : dp[k]);
	return 0;
}