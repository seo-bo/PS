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
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	auto bfs = [&](int node, int target)
		{
			vector<bool>visited(n + 1, false);
			visited[node] = true;
			queue<pii>q;
			q.push(make_pair(node, 0));
			while (!q.empty())
			{
				auto [v, w] = q.front();
				q.pop();
				if (v == target)
				{
					return w;
				}
				for (auto& [i, j] : graph[v])
				{
					if (!visited[i])
					{
						visited[i] = true;
						q.push(make_pair(i, w + j));
					}
				}
			}
			return 0;
		};
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return 0;
}