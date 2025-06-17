#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, T = 0;
	cin >> n >> m >> T;
	vector<vector<tp>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		graph[a].push_back(make_tuple(b, c, d));
		graph[b].push_back(make_tuple(a, c, d));
	}
	ll left = 0, right = INT_MAX, ans = -1;
	auto dijkstra = [&](ll mid)
		{
			vector<ll>dist(n + 1, LLONG_MAX);
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, 1));
			dist[1] = 0;
			while (!pq.empty())
			{
				auto [co, ver] = pq.top();
				pq.pop();
				if (dist[ver] < co)
				{
					continue;
				}
				for (auto& [nv, nc, pp] : graph[ver])
				{
					if (dist[nv] > dist[ver] + nc + max(0LL, pp - mid))
					{
						dist[nv] = dist[ver] + nc + max(0LL, pp - mid);
						pq.push(make_pair(dist[nv], nv));
					}
				}
			}
			return dist[n] <= T;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (dijkstra(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}