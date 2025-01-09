#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>cost(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	int st = 0, ed = 0;
	cin >> st >> ed;
	vector<vector<pll>>graph(n + 1), rgraph(n + 1);
	vector<ll>dist(n + 1, LLONG_MAX), rdist(n + 1, LLONG_MAX);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		rgraph[b].push_back(make_pair(a, c));
	}
	auto dijkstra = [&](int start, vector<vector<pll>>& gg, vector<ll>& dis)
		{
			dis[start] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, start));
			while (!pq.empty())
			{
				auto [w, v] = pq.top();
				pq.pop();
				if (dis[v] < w)
				{
					continue;
				}
				for (auto& [nv, nw] : gg[v])
				{
					if (dis[nv] > dis[v] + nw)
					{
						dis[nv] = dis[v] + nw;
						pq.push(make_pair(dis[nv], nv));
					}
				}
			}
			return dis;
		};
	dijkstra(st, graph, dist);
	if (dist[ed] == LLONG_MAX)
	{
		cout << -1;
		return 0;
	}
	dijkstra(ed, rgraph, rdist);
	vector<bool>check(n + 1, false);
	vector<int>vt;
	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] + rdist[i] == dist[ed])
		{
			check[i] = true;
			vt.push_back(i);
		}
	}
	sort(vt.begin(), vt.end(), [&](const int& a, const int& b)
		{
			return dist[a] < dist[b];
		});
	vector<ll>pivot(n + 1, LLONG_MAX);
	for (auto& i : vt)
	{
		for (auto& [v, w] : graph[i])
		{
			if (check[v] && dist[i] + w + rdist[v] == dist[ed])
			{
				pivot[v] = min({ pivot[v], pivot[i], cost[i] });
			}
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		if (check[i] && pivot[i] != LLONG_MAX)
		{
			ans = min(ans, pivot[i] + cost[i]);
		}
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans);
	return 0;
}