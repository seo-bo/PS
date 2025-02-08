#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>dp(n + 1, vector<ll>(2, 0));
	vector<ll>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	dp[1][0] = v[1];
	ll ans = 0;
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + v[i];
		dp[i][1] = dp[i - 1][0] + 1;
		if (i == n)
		{
			ans = max(dp[i][0], dp[i][1]);
		}
	}
	vector<vector<ll>>(n + 1, vector<ll>(2, 0)).swap(dp);
	dp[1][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + v[i];
		dp[i][1] = dp[i - 1][0] + 1;
		if (i == n)
		{
			ans = max(ans, dp[i][0]);
		}
	}
	cout << ans;
	return 0;
}