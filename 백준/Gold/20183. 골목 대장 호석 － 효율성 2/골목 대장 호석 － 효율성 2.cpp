#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, A = 0, B = 0, C = 0;
	cin >> n >> m >> A >> B >> C;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	auto dijkstra = [&](ll ok)
		{
			vector<ll>dist(n + 1, LLONG_MAX);
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, A));
			dist[A] = 0;
			while (!pq.empty())
			{
				auto [cost, ver] = pq.top();
				pq.pop();
				if (dist[ver] < cost)
				{
					continue;
				}
				for (auto& [nc, nv] : graph[ver])
				{
					if (nc > ok)
					{
						continue;
					}
					if (dist[nv] > dist[ver] + nc)
					{
						dist[nv] = dist[ver] + nc;
						pq.push(make_pair(dist[nv], nv));
					}
				}
			}
			return dist[B] <= C;
		};
	ll left = 1, right = INT_MAX, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (dijkstra(mid))
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}