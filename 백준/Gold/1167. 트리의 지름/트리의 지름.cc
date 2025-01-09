#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ns = 0, pivot = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int v = 0;
		cin >> v;
		while (1)
		{
			int t = 0, w = 0;
			cin >> t;
			if (t == -1)
			{
				break;
			}
			cin >> w;
			graph[v].push_back(make_pair(t, w));
			graph[t].push_back(make_pair(v, w));
		}
	}
	auto bfs = [&](int start)
		{
			vector<bool>visited(n + 1);
			visited[start] = true;
			queue<pii>q;
			q.push(make_pair(start, 0));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (auto& [c, d] : graph[a])
				{
					if (!visited[c])
					{
						visited[c] = true;
						if (b + d > pivot)
						{
							pivot = b + d;
							ns = c;
						}
						q.push(make_pair(c, b + d));
					}
				}
			}
		};
	bfs(1);
	pivot = 0;
	bfs(ns);
	cout << pivot;
	return 0;
}