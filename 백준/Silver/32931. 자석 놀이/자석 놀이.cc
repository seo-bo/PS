#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>v(3, vector<ll>(n + 1, 0));
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<ll>dp(3, LLONG_MIN);
	dp[1] = max(v[1][1], v[1][1] + v[2][1]);
	dp[2] = v[1][1] + v[2][1];
	for (int i = 2; i <= n; ++i)
	{
		vector<ll>temp(3, LLONG_MIN);
		ll cost = v[1][i] + v[2][i];
		temp[1] = max({ temp[1], dp[1] + v[1][i], dp[1] + cost, dp[2] + cost });
		temp[2] = max({ temp[2], dp[2] + v[2][i], dp[1] + cost, dp[2] + cost });
		dp = move(temp);
	}
	cout << dp[2];
	return 0;
}