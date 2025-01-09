#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m =0;
	cin >> n;
	vector<bool>v(n + 1, false);
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp] = true;
	}
	vector<int>dp(n + 1, 0);
	dp[1] = 1; 
	if (n >= 2)
	{
		(v[1] || v[2]) ? dp[2] = 1 : dp[2] = 2;
	}
	/******************************
	1
	1 2 / 2 1
	1 2 3 / 2 1 3 / 1 3 2
	1 2 3 4 / 2 1 3 4 / 1 3 2 4 
	1 2 3 4 5 / 2 1 3 4 5 / 1 3 2 4 5
	*******************************/
	for (int i = 3; i <= n; ++i)
	{
		if (v[i])
		{
			dp[i] = dp[i - 1];
		}
		else if (v[i - 1])
		{
			dp[i] = dp[i - 1];
		}
		else if (v[i - 2])
		{
			dp[i] = dp[i - 1] * 2;
		}
		else if (!v[i - 1] && !v[i - 2])
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	cout << dp[n];
	return 0;
}