#include <bits/stdc++.h>
#define INF 2 * 1e9 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct boat
{
	int v, t, h;
};
struct cmp
{
	bool operator()(const boat& a, const boat& b)
	{
		if (a.t == b.t)
		{
			return a.h > b.h;
		}
		return a.t > b.t;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k = 0, n = 0, m = 0;
	cin >> k >> n >> m;
	vector<vector<int>>mindis(m + 1, vector<int>(k + 1, INF));
	vector<vector<boat>>graph(m + 1);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0, t = 0, h = 0;
		cin >> start >> end >> t >> h;
		if (h >= k)
		{
			continue;
		}
		graph[start].push_back({ end,t,h });
		graph[end].push_back({ start,t,h });
	}
	int start = 0, end = 0;
	cin >> start >> end;
	auto dijkstra = [&](int start)
		{
			priority_queue<boat, vector<boat>, cmp>pq;
			pq.push({ start,0, k });
			mindis[start][k] = 0;
			while (!pq.empty())
			{
				boat cur = pq.top();
				pq.pop();
				if (mindis[cur.v][cur.h] < cur.t)
				{
					continue;
				}
				for (auto& i : graph[cur.v])
				{
					if (cur.h - i.h <= 0)
					{
						continue;
					}
					int hp = cur.h - i.h;
					if (mindis[i.v][hp] > cur.t + i.t)
					{
						mindis[i.v][hp] = cur.t + i.t;
						pq.push({ i.v,mindis[i.v][hp],hp });
					}
				}
			}
		};
	dijkstra(start);
	int ans = INF;
	for (int i = 1; i <= k; ++i)
	{
		ans = min(mindis[end][i], ans);
	}
	cout << ((ans == INF) ? -1 : ans);
	return 0;
}