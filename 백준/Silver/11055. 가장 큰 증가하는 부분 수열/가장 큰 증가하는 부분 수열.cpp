#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>dp(n + 1);
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		dp[i] = v[i];
	}
	int ans = v[1];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (v[i] < v[j])
			{
				dp[j] = max(dp[j], dp[i] + v[j]);
			}
			ans = max(dp[j], ans);
		}
	}
	cout << ans;
	return 0;
}