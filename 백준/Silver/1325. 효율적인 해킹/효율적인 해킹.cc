#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[end].push_back(start);
	}
	vector<pii>ans;
	auto dfs = [&](int start)
		{
			vector<bool> visited(n + 1, false);
			int ans = 0;
			stack<int>s;
			s.push(start);
			visited[start] = true;
			while (!s.empty()) 
			{
				int node = s.top();
				s.pop();
				ans++;
				for (int neighbor : graph[node]) 
				{
					if (!visited[neighbor]) 
					{
						visited[neighbor] = true;
						s.push(neighbor);
					}
				}
			}
			return ans;
		};
	for (int i = 1; i <= n; ++i)
	{
		ans.push_back(make_pair(i, dfs(i)));
	}
	sort(ans.begin(), ans.end(), [&](const pii& a, const pii& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second > b.second;
		});
	int pivot = ans[0].second;
	cout << ans[0].first << ' ';
	for (int i = 1; i < n; ++i)
	{
		if (ans[i].second != pivot)
		{
			break;
		}
		cout << ans[i].first << ' ';
	}
	return 0;
}