#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n + 2, vector<int>(m + 2, 0));
	vector<vector<int>>up(n + 2, vector<int>(m + 2, 0));
	vector<vector<int>>down(n + 2, vector<int>(m + 2, 0));
	vector<vector<int>>right(n + 2, vector<int>(m + 2, 0));
	vector<vector<int>>left(n + 2, vector<int>(m + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j])
			{
				left[i][j] = left[i][j - 1] + 1;
				up[i][j] = up[i - 1][j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (v[i][j])
			{
				right[i][j] = right[i][j + 1] + 1;
				down[i][j] = down[i + 1][j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = k + 1; i <= n - k; ++i)
	{
		for (int j = k + 1; j <= m - k; ++j)
		{
			if (v[i][j] && min({ left[i][j], right[i][j], up[i][j], down[i][j] }) >= k + 1)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}