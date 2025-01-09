#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		unordered_map<int, char>mm;
		vector<int>cost(n + 1, 0);
		vector<vector<int>>graph(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			char a;
			cin >> a >> cost[i];
			mm[i] = a;
			while (1)
			{
				int temp = 0;
				cin >> temp;
				if (!temp)
				{
					break;
				}
				graph[i].push_back(temp);
			}
		}
		auto bfs = [&]
			{
				vector<vector<bool>>visited(n + 1, vector<bool>(600, false));
				visited[1][0] = true;
				queue<pii>q;
				q.push(make_pair(1, 0));
				while (!q.empty())
				{
					auto [v, w] = q.front();
					q.pop();
					if (mm[v] == 'T')
					{
						if (w < cost[v])
						{
							continue;
						}
						w -= cost[v];
					}
					else if (mm[v] == 'L')
					{
						w = max(w, cost[v]);
					}
					if (v == n)
					{
						return true;
					}
					for (auto& i : graph[v])
					{
						if (!visited[i][w])
						{
							visited[i][w] = true;
							q.push(make_pair(i, w));
						}
					}
				}
				return false;
			};
		cout << ((bfs() ? "Yes" : "No")) << '\n';
	}
	return 0;
}