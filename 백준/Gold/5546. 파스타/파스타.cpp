#include <bits/stdc++.h>
#define MOD 10000
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v(n + 1, -1);
	for (int i = 0; i < k; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a] = b;
	}
	vector<int>dp(7, 0);
	if (v[1] == 1 || v[1] == -1)
	{
		dp[1] = 1;
	}
	if (v[1] == 2 || v[1] == -1)
	{
		dp[2] = 1;
	}
	if (v[1] == 3 || v[1] == -1)
	{
		dp[3] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		vector<int>temp(7, 0);
		if (v[i] == 1 || v[i] == -1)
		{
			temp[1] = (dp[2] + dp[3] + dp[5] + dp[6]) % MOD;
			temp[4] = dp[1];
		}
		if (v[i] == 2 || v[i] == -1)
		{
			temp[2] = (dp[1] + dp[3] + dp[4] + dp[6]) % MOD;
			temp[5] = dp[2];
		}
		if (v[i] == 3 || v[i] == -1)
		{
			temp[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % MOD;
			temp[6] = dp[3];
		}
		dp = move(temp);
	}
	int ans = 0;
	for (int i = 1; i <= 6; ++i)
	{
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans;
	return 0;
}