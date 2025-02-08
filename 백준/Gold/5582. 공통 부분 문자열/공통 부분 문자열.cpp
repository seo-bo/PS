#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}