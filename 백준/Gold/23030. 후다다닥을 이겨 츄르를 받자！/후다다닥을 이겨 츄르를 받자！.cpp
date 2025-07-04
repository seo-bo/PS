#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, len = 0;
	cin >> n;
	vector<vector<vector<pii>>>graph(n + 1);
	vector<int>siz(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> siz[i];
		len = max(len, siz[i]);
		graph[i].resize(siz[i] + 1);
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		graph[a][b].push_back(make_pair(c, d));
		graph[c][d].push_back(make_pair(a, b));
	}
	auto dijkstra = [&](int A, int B, int C, int D, int T)
		{
			vector<vector<int>>dist(n + 1, vector<int>(len + 1, INT_MAX));
			dist[A][B] = 0;
			priority_queue<tp, vector<tp>, greater<tp>>pq;
			pq.push(make_tuple(0, A, B));
			while (!pq.empty())
			{
				auto [co, a, b] = pq.top();
				pq.pop();
				if (dist[a][b] < co)
				{
					continue;
				}
				for (auto& [na, nb] : graph[a][b])
				{
					int nc = dist[a][b] + T;
					if (dist[na][nb] > nc)
					{
						dist[na][nb] = nc;
						pq.push(make_tuple(nc, na, nb));
					}
				}
				if (b - 1 >= 1)
				{
					if (dist[a][b - 1] > dist[a][b] + 1)
					{
						dist[a][b - 1] = dist[a][b] + 1;
						pq.push(make_tuple(dist[a][b - 1], a, b - 1));
					}
				}
				if (b + 1 <= siz[a])
				{
					if (dist[a][b + 1] > dist[a][b] + 1)
					{
						dist[a][b + 1] = dist[a][b] + 1;
						pq.push(make_tuple(dist[a][b + 1], a, b + 1));
					}
				}
			}
			return dist[C][D];
		};
	int k = 0;
	cin >> k;
	while (k--)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		cin >> a >> b >> c >> d >> e;
		cout << dijkstra(b, c, d, e, a) << '\n';
	}
	return 0;
}