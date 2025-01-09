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
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	vector<bool>visited(n + 1, false);
	auto bfs = [&](int start) -> ll
		{
			ll sum = 0;
			visited[start] = true;
			queue<pii>q;
			q.push(make_pair(start, 0));
			while (!q.empty())
			{
				pii cur = q.front();
				q.pop();
				for (auto& i : graph[cur.first])
				{
					if (!visited[i])
					{
						visited[i] = true;
						q.push(make_pair(i, cur.second + 1));
						sum += cur.second + 1;
					}
				}
			}
			return sum;
		};
	int ans = 0;
	ll value = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ll v = bfs(i);
		if (v < value)
		{
			ans = i;
			value = v;
		}
		vector<bool>(n + 1, false).swap(visited);
	}
	cout << ans;
	return 0;
}