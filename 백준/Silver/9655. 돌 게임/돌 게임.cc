#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<bool>dp(n +4, false);
	dp[1] = true, dp[3] = true;
	for (int i = 4; i <= n; ++i)
	{
		if (!dp[i - 1] || !dp[i - 3])
		{
			dp[i] = true;
		}
	}
	dp[n] ? (cout << "SK") : (cout << "CY");
	return 0;
}