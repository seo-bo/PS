#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string a, b, c;
	cin >> a >> b >> c;
	ll alen = a.size(), len = b.size();
	vector<vector<vector<ll>>>dp(alen, vector<vector<ll>>(len, vector<ll>(3, -1)));
	function<ll(ll, ll, ll)> dfs = [&](ll aidx, ll idx, ll turn)
		{
			if (aidx >= alen)
			{
				return 1LL;
			}
			if (idx >= len)
			{
				return 0LL;
			}
			if (dp[aidx][idx][turn] != -1)
			{
				return dp[aidx][idx][turn];
			}
			ll res = 0;
			if (turn != 2)
			{
				for (int i = idx; i < len; ++i)
				{
					if (b[i] == a[aidx])
					{
						res += dfs(aidx + 1, i + 1, 2);
					}
				}
			}
			if (turn != 1)
			{
				for (int i = idx; i < len; ++i)
				{
					if (c[i] == a[aidx])
					{
						res += dfs(aidx + 1, i + 1, 1);
					}
				}
			}
			return dp[aidx][idx][turn] = res;
		};
	cout << dfs(0, 0, 0);
	return 0;
}