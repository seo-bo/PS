#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(22, -1));
	function<ll(int, int)> dfs = [&](int idx, int sum)->ll
		{
			if (idx == n)
			{
				return sum == v[n] ? 1LL : 0LL;
			}
			if (sum < 0 || sum > 20)
			{
				return 0LL;
			}
			if (dp[idx][sum] != -1)
			{
				return dp[idx][sum];
			}
			return dp[idx][sum] = dfs(idx + 1, sum + v[idx]) + dfs(idx + 1, sum - v[idx]);
		};
	cout << dfs(2, v[1]);
	return 0;
}