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
	vector<int>v(n + 1, 0);
	vector<int>dp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = v[i];
		for (int j = 1; j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n];
	return 0;
}