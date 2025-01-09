#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>dp(10001, 0);
	dp[0] = 1;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = i; j <= 10000; ++j)
		{
			dp[j] += dp[j - i];
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}