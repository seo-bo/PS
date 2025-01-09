#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>dp(83);
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 81; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n = 0;
	cin >> n;
	cout << (dp[n-1] + dp[n]) * 2;
	return 0;
}