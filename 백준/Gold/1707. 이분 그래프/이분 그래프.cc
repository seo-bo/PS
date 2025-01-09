#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int v = 0, e = 0, cnt = 0;
		bool check = true;
		cin >> v >> e;
		vector<vector<int>>graph(v + 1);
		vector<int>visited(v + 1, -1);
		for (int i = 0; i < e; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		auto bfs = [&](int start)
			{
				queue<int>q;
				q.push(start);
				visited[start] = 0;
				while (!q.empty() && check)
				{
					auto a = q.front();
					q.pop();
					for (auto& i : graph[a])
					{
						if (visited[i] == -1)
						{
							visited[i] = 1 - visited[a];
							q.push(i);
						}
						else if (visited[i] == visited[a])
						{
							check = false;
							return;
						}
					}
				}
			};
		for (int i = 1; i <= v; ++i)
		{
			if (visited[i] == -1)
			{
				bfs(i);
			}
			if (!check)
			{
				break;
			}
		}
		cout << (check ? "YES" : "NO") << '\n';
	}
	return 0;
}