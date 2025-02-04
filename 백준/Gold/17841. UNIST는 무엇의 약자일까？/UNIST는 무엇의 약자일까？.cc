#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	string pivot = "UNIST";
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(6, -1));
	function<ll(int, int)> dfs = [&](int idx, int depth)
		{
			if (depth == 5)
			{
				return 1LL;
			}
			if (idx == n)
			{
				return 0LL;
			}
			if (dp[idx][depth] != -1)
			{
				return dp[idx][depth];
			}
			ll res = 0;
			for (int i = 0; i <= v[idx].size() && depth + i <= 5; ++i)
			{
				if (pivot.substr(depth, i) == v[idx].substr(0, i))
				{
					res = (res + dfs(idx + 1, depth + i)) % MOD;
				}
			}
			return dp[idx][depth] = res;
		};
	cout << dfs(0, 0);
	return 0;
}