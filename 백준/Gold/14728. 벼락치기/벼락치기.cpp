#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n >> t;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<int>>dp(n + 1, vector<int>(t + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (int j = 0; j <= t; ++j)
		{
			if (j >= a)
			{
				dp[i][j] = max({ dp[i][j],dp[i - 1][j], dp[i - 1][j - a] + b });
			}
			else
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][t];
	return 0;
}