#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>dp(n + 2, 0);
	vector<pii>v(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	ll ans = 0;
	for (int i = 1; i <= n + 1; ++i)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + v[i].first <= n + 1)
		{
			dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
		}
	}
	cout << dp[n + 1];
	return 0;
}