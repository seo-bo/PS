#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size(), m = b.size();
		vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
		function<ll(int, int)> dfs = [&](int i, int j)
			{
				if (!i && !j)
				{
					return 0LL;
				}
				if (dp[i][j] != -1)
				{
					return dp[i][j];
				}
				ll res = INT_MAX;
				if (i > 0)
				{
					res = min(res, dfs(i - 1, j) + ((a[i - 1] != c[i + j - 1]) ? 1LL : 0LL));
				}
				if (j > 0)
				{
					res = min(res, dfs(i, j - 1) + ((b[j - 1] != c[i + j - 1]) ? 1LL : 0LL));
				}
				return dp[i][j] = res;
			};
		cout << dfs(n, m) << '\n';
	}
}
