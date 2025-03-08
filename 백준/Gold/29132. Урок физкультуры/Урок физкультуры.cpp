#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>dp(n + 1, -1);
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	auto cal = [&](int a, int b)
		{
			return (a == b) ? 0 : (a < b) ? 1 : -1;
		};
	function<ll(int)> dfs = [&](int idx)
		{
			if (idx > n)
			{
				return 1LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = dfs(idx + 1);
			if (idx + 1 <= n)
			{
				res = (res + dfs(idx + 2)) % MOD;
				int state = cal(v[idx], v[idx + 1]);
				for (int i = idx + 2; i <= n; ++i)
				{
					int temp = cal(v[i - 1], v[i]);
					if (state && temp && state != temp)
					{
						break;
					}
					if (state == 0)
					{
						state = temp;
					}
					res = (res + dfs(i + 1)) % MOD;
				}
			}
			return dp[idx] = res;
		};
	cout << dfs(1);
	return 0;
}