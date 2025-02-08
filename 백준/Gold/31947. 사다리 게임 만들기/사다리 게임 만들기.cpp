#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, m = 0, s = 0, e = 0;
	cin >> N >> m >> s >> e;
	vector<vector<lb>>dp(N + 1, vector<lb>(m + 1, 0));
	dp[e][0] = 1;
	for (int i = 1; i <= m; ++i) // 가로선
	{
		for (int j = 1; j <= N; ++j) // 시작점
		{
			lb n = lb(N);
			if (j == 1)
			{
				dp[j][i] = (1 / (n - 1)) * dp[j + 1][i - 1] + ((n - 2) / (n - 1)) * dp[j][i - 1];
			}
			else if (j == n)
			{
				dp[j][i] = (1 / (n - 1)) * dp[j - 1][i - 1] + ((n - 2) / (n - 1)) * dp[j][i - 1];
			}
			else
			{
				dp[j][i] = (1 / (n - 1)) * dp[j - 1][i - 1] + (1 / (n - 1)) * dp[j + 1][i - 1]
				+ ((n - 3) / (n - 1)) * dp[j][i - 1];
			}
		}
	}
	cout << fixed << setprecision(12) << dp[s][m];
	return 0;
}
