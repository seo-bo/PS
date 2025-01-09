#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0, pro = 0;
	cin >> N;
	vector<int>win(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> win[i];
	}
	cin >> M;
	vector<int>lose(M + 1, 0);
	for (int i = 1; i <= M; ++i)
	{
		cin >> lose[i];
	}
	vector<vector<int>>dp(N + 1, vector<int>(M + 1, -1e9)); // 승리 / 패배
	dp[0][0] = 0;
	cin >> pro;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (i > 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + win[i]);
			}
			if (j > 0)
			{
				int mod = 0;
				if (dp[i][j - 1] >= 0) // 양수일때
				{
					mod = (dp[i][j - 1]) % pro;
				}
				else // 음수일때
				{
					mod = (dp[i][j - 1] % pro + pro) % pro;
				}
				if (mod <= 0 || mod >= pro)
				{
					dp[i][j] = max(dp[i][j - 1] - lose[j], dp[i][j]);
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1] - min(lose[j], mod), dp[i][j]);
				}
			}
		}
	}
	cout << dp[N][M];
	return 0;
}