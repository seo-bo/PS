#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>dp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a > dp[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = a;
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
	return 0;
}