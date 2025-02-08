#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ll>dp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int low = v[i], high = v[i];
		for (int j = i; j >= 1; --j)
		{
			low = min(low, v[j]);
			high = max(high, v[j]);
			dp[i] = max(dp[i], dp[j - 1] + high - low);
		}
	}
	cout << dp[n];
	return 0;
}