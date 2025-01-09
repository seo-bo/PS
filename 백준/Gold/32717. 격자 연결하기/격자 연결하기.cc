#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int ans = INT_MIN;
	vector<vector<int>>v(n + 2, vector<int>(m + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
			ans = max(ans, v[i][j]);
		}
	}
	vector<vector<int>>dp1(n + 2, vector<int>(m + 2, -2e5));
	vector<vector<int>>dp2(n + 2, vector<int>(m + 2, -2e5));
	vector<vector<int>>dp3(n + 2, vector<int>(m + 2, -2e5));
	vector<vector<int>>dp4(n + 2, vector<int>(m + 2, -2e5));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int k = m + 1 - j;
			int z = n + 1 - i;
			dp1[i][j] = max({ v[i][j],dp1[i - 1][j] + v[i][j], dp1[i][j - 1] + v[i][j] });
			dp2[i][k] = max({ v[i][k],dp2[i - 1][k] + v[i][k], dp2[i][k + 1] + v[i][k] });
			dp3[z][j] = max({ v[z][j],dp3[z + 1][j] + v[z][j], dp3[z][j - 1] + v[z][j] });
			dp4[z][k] = max({ v[z][k],dp4[z + 1][k] + v[z][k], dp4[z][k + 1] + v[z][k] });
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			ans = max({ ans,dp1[i][j] + dp4[i][j] - v[i][j], dp2[i][j] + dp3[i][j] - v[i][j] });
		}
	}
	cout << ans;
	return 0;
}