#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, t = 0, ans = 0;
	cin >> n >> t;
	vector<vector<int>>dp(n + 1, vector<int>(t + 1, -1));
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
		ans += b;
	}
	function<int(int, int)> dfs = [&](int idx, int day)
		{
			if (idx == n + 1 || day == t + 1)
			{
				return 0;
			}
			if (dp[idx][day] != -1)
			{
				return dp[idx][day];
			}
			int res = dfs(idx + 1, day);
			if (day + v[idx].first - 1 <= t)
			{
				res = max(res, dfs(idx + 1, day + v[idx].first) + v[idx].second);
			}
			return dp[idx][day] = res;
		};
	cout << ans - dfs(1, 1);
	return 0;
}