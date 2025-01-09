#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<vector<int>>graph(n + 1), temp(n + 1);
	vector<ll>dp(n + 1, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		temp[a].push_back(b);
		temp[b].push_back(a);
	}
	vector<bool>visited(n + 1, false);
	visited[1] = true;
	function<void(int)> mg = [&](int node)
		{
			for (auto& i : temp[node])
			{
				if (!visited[i])
				{
					visited[i] = true;
					graph[node].push_back(i);
					mg(i);
				}
			}
		};
	mg(1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> dp[i];
	}
	function<void(int, ll)> dfs = [&](int node, ll sum)
		{
			if (dp[node] >= sum)
			{
				dp[node] += sum;
				return;
			}
			else
			{
				sum -= dp[node];
				dp[node] *= 2;
			}
			if (graph[node].empty())
			{
				return;
			}
			ll pivot = sum / graph[node].size();
			if (!pivot)
			{
				return;
			}
			for (auto& i : graph[node])
			{
				dfs(i, pivot);
			}
		};
	while (q--)
	{
		ll k = 0, u = 0, x = 0;
		cin >> k;
		if (k == 1)
		{
			cin >> u >> x;
			dfs(u, x);
		}
		else
		{
			cin >> u;
			cout << dp[u] << '\n';
		}
	}
	return 0;
}