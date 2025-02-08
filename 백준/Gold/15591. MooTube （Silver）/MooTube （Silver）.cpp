#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, T = 0;
	cin >> n >> T;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	auto bfs = [&](int st, int we)
		{
			int cnt = 0;
			vector<bool>visited(n + 1, false);
			visited[st] = true;
			queue<int>q;
			q.push(st);
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				for (auto& [v, w] : graph[a])
				{
					if (!visited[v] && w >= we)
					{
						visited[v] = true;
						q.push(v);
						cnt++;
					}
				}
			}
			return cnt;
		};
	while (T--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << bfs(b, a) << '\n';
	}
	return 0;
}