#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<ll>>dp(2501, vector<ll>(2501, -1));
	function<ll(int, int)> dfs = [&](int left, int right)
		{
			if (left == 0 && right == 0)
			{
				return 1LL;
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			ll cost = 0;
			if (left > 0)
			{
				cost = (cost + dfs(left - 1, right)) % MOD;
			}
			if (right > left)
			{
				cost = (cost + dfs(left, right - 1)) % MOD;
			}
			return dp[left][right] = cost;
		};
	vector<ll>ans(1, 0);
	for (int i = 1; i <= 2500; ++i)
	{
		ans.push_back(dfs(i, i));
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		if (n % 2)
		{
			cout << 0 << '\n';
			continue;
		}
		cout << ans[n / 2] << '\n';
	}
	return 0;
}