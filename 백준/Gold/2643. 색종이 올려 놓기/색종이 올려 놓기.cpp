#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}
	}
	sort(v.begin() + 1, v.end());
	vector<int>dp(n + 1, -1);
	function<int(int)> dfs = [&](int idx)
		{
			if (idx == n + 1)
			{
				return 0;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			int res = 0;
			auto [a, b] = v[idx];
			for (int i = idx + 1; i <= n; ++i)
			{
				auto [c, d] = v[i];
				if (c >= a && d >= b)
				{
					res = max(res, dfs(i) + 1);
				}
			}
			return dp[idx] = res;
		};
	cout << dfs(0);
	return 0;
}