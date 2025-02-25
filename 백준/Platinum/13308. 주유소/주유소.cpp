#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>cost(n + 1);
	ll _ = 0;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		_ = max(_, cost[i]);
	}
	vector<vector<pii>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	vector<vector<ll>>dist(n + 1, vector<ll>(_ + 1, LLONG_MAX));
	dist[1][cost[1]] = 0;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(0, cost[1], 1));
	while (!pq.empty())
	{
		auto [co, ed, ve] = pq.top();
		pq.pop();
		if (dist[ve][ed] < co)
		{
			continue;
		}
		for (auto& [nc, nv] : graph[ve])
		{
			ll temp = min(cost[nv], ed);
			if (dist[nv][temp] > dist[ve][ed] + nc * ed)
			{
				dist[nv][temp] = dist[ve][ed] + nc * ed;
				pq.push(make_tuple(dist[nv][temp], temp, nv));
			}
		}
	}
	ll ans = LLONG_MAX;
	for (ll i = 0; i <= _; ++i)
	{
		ans = min(ans, dist[n][i]);
	}
	cout << ans;
	return 0;
}