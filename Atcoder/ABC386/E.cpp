
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	ll cur = 0;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		cur ^= v[i];
	}
	function<ll(int, int, ll)> dfs = [&](int depth, int idx, ll com)
		{
			if (depth == 0)
			{
				return com;
			}
			if (idx > n)
			{
				return 1LL * INT_MIN;
			}
			ll res = INT_MIN;
			return max({ res,dfs(depth - 1,idx + 1,com ^ v[idx]), dfs(depth,idx + 1,com) });
		};
	if (n - k >= k)
	{
		cout << dfs(k, 1, 0);
	}
	else
	{
		cout << dfs(n - k, 1, cur);
	}
	return 0;
}
