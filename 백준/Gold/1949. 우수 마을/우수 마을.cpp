#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ns = 0;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(2, 0));
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		cin >> dp[i][1];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	function<void(int)> leaf = [&](int start)
		{
			bool check = false;
			for (auto& i : graph[start])
			{
				if (!visited[i])
				{
					visited[i] = true;
					check = true;
					leaf(i);
				}
			}
			if (!check)
			{
				ns = start;
			}
		};
	visited[1] = true;
	leaf(1);
	vector<bool>(n + 1, false).swap(visited);
	function<void(int)> dfs = [&](int start)
		{
			for (auto& i : graph[start])
			{
				if(!visited[i])
				{
					visited[i] = true;
					dfs(i);
					dp[start][0] += max(dp[i][0], dp[i][1]);
					dp[start][1] += dp[i][0];
				}
			}
		};
	visited[ns] = true;
	dfs(ns);
	cout << max(dp[ns][0], dp[ns][1]);
	return 0;
}