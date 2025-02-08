#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	string p = "?";
	cin >> str;
	p += str;
	vector<ll>dp(n + 1, -1);
	auto check = [&](char a)
		{
			if (a == 'B')
			{
				return 'O';
			}
			if (a == 'O')
			{
				return 'J';
			}
			return 'B';
		};
	function<ll(int)> dfs = [&](int idx)
		{
			if (idx == n)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = INT_MAX;
			char pivot = check(p[idx]);
			for (int i = idx + 1; i <= n; ++i)
			{
				if (p[i] == pivot)
				{
					res = min(res, dfs(i) + (i - idx) * (i - idx));
				}
			}
			return dp[idx] = res;
		};
	cout << ((dfs(1) == INT_MAX) ? -1 : dfs(1));
	return 0;
}