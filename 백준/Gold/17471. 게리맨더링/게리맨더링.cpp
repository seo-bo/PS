#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int ans = INT_MAX;
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		for (int j = 0; j < temp; ++j)
		{
			int a = 0;
			cin >> a;
			graph[a].push_back(i);
			graph[i].push_back(a);
		}
	}
	auto sv = [&](int pivot)
		{
			set<int>team1, team2;
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < n; ++i)
			{
				if (pivot & (1 << i))
				{
					team1.insert(i + 1);
					sum1 += v[i + 1];
				}
				else
				{
					team2.insert(i + 1);
					sum2 += v[i + 1];
				}
			}
			vector<bool>visited(n + 1, false);
			function<void(set<int>&, int)> dfs = [&](set<int>& team, int node)
				{
					visited[node] = true;
					for (auto& i : graph[node])
					{
						if (team.find(i) != team.end() && !visited[i])
						{
							dfs(team, i);
						}
					}
				};
			if (team1.empty() || team2.empty())
			{
				return INT_MAX;
			}
			dfs(team1, *team1.begin());
			dfs(team2, *team2.begin());
			for (int i = 1; i <= n; ++i)
			{
				if (!visited[i])
				{
					return INT_MAX;
				}
			}
			return abs(sum1 - sum2);
		};
	for (int i = 1; i < (1 << n); ++i)
	{
		ans = min(ans, sv(i));
	}
	if (ans == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}