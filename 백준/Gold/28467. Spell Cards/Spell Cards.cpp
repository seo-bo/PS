#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	vector<vector<ll>>maxi(n + 1, vector<ll>(n + 1, -1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		maxi[i][i] = v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			maxi[i][j] = max(maxi[i][j - 1], v[j]);
		}
	}
	function<ll(int, int)> dfs = [&](int left, int right)
		{
			if (left == right)
			{
				return 0LL;
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			ll res = LLONG_MAX;
			for (int i = left; i < right; ++i)
			{
				res = min(res, dfs(left, i) + dfs(i + 1, right) + maxi[left][i] + maxi[i + 1][right]);
			}
			return dp[left][right] = res;
		};
	cout << dfs(1, n);
	return 0;
}