#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, t = 0, s = 0, g = 0, h = 0;
		cin >> n >> m >> t >> s >> g >> h;
		vector<vector<pii>>graph(n + 1);
		vector<int>dest(t);
		vector<int>mindis(n + 1, INF);
		vector<int>disdis1(n + 1, INF);
		vector<int>disdis2(n + 1, INF);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(c, b));
			graph[b].push_back(make_pair(c, a));
		}
		for (int i = 0; i < t; ++i)
		{
			cin >> dest[i];
		}
		sort(dest.begin(), dest.end());
		auto dijkstra = [&](int start, vector<int>& dis)
			{
				priority_queue<pii, vector<pii>, greater<>>pq;
				dis[start] = 0;
				pq.push(make_pair(0, start));
				while (!pq.empty())
				{
					auto [a, b] = pq.top();
					pq.pop();
					if (dis[b] < a)
					{
						continue;
					}
					for (auto& i : graph[b])
					{
						auto [c, d] = i;
						if (dis[d] > dis[b] + c)
						{
							dis[d] = dis[b] + c;
							pq.push(make_pair(dis[d], d));
						}
					}
				}
			};
		dijkstra(s, mindis);
		int pivot1 = INF, pivot2 = INF;
		for (auto& i : graph[g])
		{
			if (i.second == h)
			{
				pivot1 = i.first;
				break;
			}
		}
		for (auto& i : graph[h])
		{
			if (i.second == g)
			{
				pivot2 = i.first;
				break;
			}
		}
		dijkstra(h, disdis1);
		dijkstra(g, disdis2);
		for (auto& i : dest)
		{
			if (mindis[i] == INF)
			{
				continue;
			}
			if (mindis[g] + pivot1 + disdis1[i] == mindis[i] || mindis[h] + pivot2 + disdis2[i] == mindis[i])
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}