#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

ll dp[1 << 14][15];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, v = 0, e = 0;
	cin >> n >> v >> e;
	n++;
	vector<int>cost(v + 1), ve(n + 2), ok(v + 1, -1);
	for (int i = 1; i <= v; ++i)
	{
		cin >> cost[i];
	}
	// ve : 신규 인덱스 -> 정점 , ok : 정점 -> 신규 인덱스
	for (int i = 2; i <= n; ++i)
	{
		cin >> ve[i];
		ok[ve[i]] = i;
	}
	vector<vector<pll>> graph(v + 1);
	for (int i = 0; i < e; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	const ll inf = LLONG_MAX / 8;
	vector<vector<vector<ll>>>dist(n + 2, vector<vector<ll>>(n + 2, vector<ll>(v + 2, inf)));
	auto dijkstra = [&](int cd)
		{
			dist[cd][1][1] = 0;
			priority_queue<tp, vector<tp>, greater<tp>>pq;
			pq.push(make_tuple(0, 1, 1)); // cost, base, now
			while (!pq.empty())
			{
				auto [co, base, now] = pq.top();
				pq.pop();
				if (dist[cd][base][now] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[now])
				{
					if (cd < cost[nv])
					{
						continue;
					}
					if (dist[cd][base][nv] > dist[cd][base][now] + nc)
					{
						dist[cd][base][nv] = dist[cd][base][now] + nc;
						pq.push(make_tuple(dist[cd][base][nv], base, nv));
						if (ok[nv] != -1 && dist[cd][ok[nv]][nv] == inf)
						{
							dist[cd][ok[nv]][nv] = 0;
							pq.push(make_tuple(0, ok[nv], nv));
						}
					}
				}
			}
		};
	for (int i = 0; i <= n; ++i)
	{
		dijkstra(i);
	}
	memset(dp, -1, sizeof(dp));
	function<ll(int, int)> dfs = [&](int mask, int node)
		{
			if (__builtin_popcount(mask) == n - 1)
			{
				return 0LL;
			}
			if (dp[mask][node] != -1)
			{
				return dp[mask][node];
			}
			ll res = inf;
			for (int i = 2; i <= n; ++i)
			{
				if (mask & (1 << (i - 2)))
				{
					continue;
				}
				int now = __builtin_popcount(mask);
				ll wei = dist[now][node][ve[i]];
				if (wei != inf)
				{
					res = min(res, dfs(mask | (1 << (i - 2)), i) + wei);
				}
			}
			return dp[mask][node] = res;
		};
	ll ans = inf;
	for (int i = 2; i <= n; ++i)
	{
		if (dist[0][1][ve[i]] != inf)
		{
			ans = min(ans, dfs((1 << (i - 2)), i) + dist[0][1][ve[i]]);
		}
	}
	cout << ((ans == inf) ? -1 : ans);
	return 0;
}