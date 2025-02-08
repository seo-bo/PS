#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<bool>dp(1005, false);
	dp[2] = true, dp[4] = true;
	for (int i = 5; i <= n; ++i)
	{
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
		{
			dp[i] = true;
		}
	}
	if (dp[n])
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
	return 0;
}