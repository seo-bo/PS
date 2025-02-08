#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<int>match(m + 1, 0);
	vector<bool>visited(m + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		for (int j = 0; j < temp; ++j)
		{
			int k = 0;
			cin >> k;
			graph[i].push_back(k);
		}
	}
	function<bool(int)> dfs = [&](int start) -> bool
		{
			for (auto& i : graph[start])
			{
				if (!visited[i])
				{
					visited[i] = true;
					if (!match[i] || dfs(match[i]))
					{
						match[i] = start;
						return true;
					}
				}
			}
			return false;
		};
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (dfs(i))
			{
				ans++;
			}
			vector<bool>(m + 1, false).swap(visited);
		}
	}
	cout << ans;
	return 0;
}