#include <bits/stdc++.h>
#define MOD 1000000003
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>dp(n, vector<int>(k + 1, -1));
	function<int(int, int, bool)> dfs = [&](int now, int cnt, bool flag)
		{
			if (cnt == k)
			{
				return 1;
			}
			if (now >= n)
			{
				return 0;
			}
			if (dp[now][cnt] != -1)
			{
				return dp[now][cnt];
			}
			ll cost = 0;
			if (!flag || now != n - 1)
			{
				cost = (cost + dfs(now + 2, cnt + 1, flag)) % MOD;
			}
			cost = (cost + dfs(now + 1, cnt, flag)) % MOD;
			return dp[now][cnt] = cost;
		};
	int ans = dfs(1, 0, false);
	vector<vector<int>>(n, vector<int>(k + 1, -1)).swap(dp);
	ans = (ans + dfs(2, 1, true)) % MOD;
	cout << ans;
	return 0;
}