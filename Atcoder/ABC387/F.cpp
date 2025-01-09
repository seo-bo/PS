#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1, 0), id(n + 1, -1);
	vector<vector<int>>child(n + 1), cnode;
	vector<bool>visited(n + 1, false), in(n + 1, false), cycle(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		child[v[i]].push_back(i);
	}
	function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& path)
		{
			visited[node] = in[node] = true;
			path.push_back(node);
			if (!visited[v[node]])
			{
				dfs(v[node], path);
			}
			else if (in[v[node]])
			{
				vector<int>cn;
				for (int i = path.size() - 1; i >= 0; --i)
				{
					cn.push_back(path[i]);
					if (path[i] == v[node])
					{
						break;
					}
				}
				int len = cnode.size();
				reverse(cn.begin(), cn.end());
				cnode.push_back(cn);
				for (auto& i : cn)
				{
					cycle[i] = true;
					id[i] = len;
				}
			}
			path.pop_back();
			in[node] = false;
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			vector<int>temp;
			dfs(i, temp);
		}
	}
	vector<vector<ll>>mul(n + 1, vector<ll>(m + 1, 0)), prefix(n + 1, vector<ll>(m + 1, 0));
	vector<bool>dp(n + 1, false);
	function<void(int)> dpdp = [&](int node)
		{
			if (dp[node])
			{
				return;
			}
			dp[node] = true;
			for (auto& i : child[node])
			{
				if (!cycle[i] && !dp[i])
				{
					dpdp(i);
				}
			}
			for (int i = 1; i <= m; ++i)
			{
				ll num = 1;
				for (auto& j : child[node])
				{
					if (!cycle[j])
					{
						num = (num * prefix[j][i]) % MOD;
					}
				}
				mul[node][i] = num;
			}
			ll sum = 0;
			for (int i = 1; i <= m; ++i)
			{
				sum = (sum + mul[node][i]) % MOD;
				prefix[node][i] = sum;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!cycle[i] && !dp[i])
		{
			dpdp(i);
		}
	}
	ll ans = 1;
	for (int i = 0; i < cnode.size(); ++i)
	{
		ll res = 0;
		for (int j = 1; j <= m; ++j)
		{
			ll pivot = 1;
			for (auto& k : cnode[i])
			{
				for (auto& z : child[k])
				{
					if (!cycle[z])
					{
						pivot = (pivot * prefix[z][j]) % MOD;
					}
				}
			}
			res = (res + pivot) % MOD;
		}
		ans = (ans * res) % MOD;
	}
	cout << ans;
	return 0;
}
