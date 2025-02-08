#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0, tx = 0, ty = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>dir = { {0,1},{1,0} };
	int cnt = 1;
	bool check = true;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = cnt;
			if (k == v[i][j])
			{
				tx = i, ty = j;
				check = false;
			}
			cnt++;
		}
	}
	if (check)
	{
		tx = n, ty = m;
	}
	dp[1][1] = 1;
	for (int i = 1; i <= tx; ++i)
	{
		for (int j = 1; j <= ty; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx <= tx && ny <= ty)
				{
					dp[nx][ny] += dp[i][j];
				}
			}
		}
	}
	for (int i = tx; i <= n; ++i)
	{
		for (int j = ty; j <= m; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx <= n && ny <= m)
				{
					dp[nx][ny] += dp[i][j];
				}
			}
		}
	}
	cout << dp[n][m];
	return 0;
}