#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	map<tp, ll>ok;
	for (ll i = 1; i <= m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		ok[make_tuple(a, b, c)] = i;
	}
	vector<vector<ll>>dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
	auto dijkstra = [&](ll start)
		{
			dist[start][start] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, start));
			while (!pq.empty())
			{
				auto [co, ver] = pq.top();
				pq.pop();
				if (dist[start][ver] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ver])
				{
					if (dist[start][nv] > nc + co)
					{
						dist[start][nv] = nc + co;
						pq.push(make_pair(dist[start][nv], nv));
					}
				}
			}
		};
	vector<ll>dp(n + 1, 1), res(m + 1, 0);
	function<ll(ll, ll, ll)> dfs = [&](ll parent, ll node, ll pivot)
		{
			for (auto& [nv, nc] : graph[node])
			{
				if (parent == nv || dist[pivot][nv] != dist[pivot][node] + nc)
				{
					continue;
				}
				ll cost = dfs(node, nv, pivot);
				dp[node] += cost;
				res[ok[make_tuple(node, nv, nc)]] += cost;
			}
			return dp[node];
		};
	for (ll i = 1; i <= n; ++i)
	{
		dijkstra(i);
		dfs(0, i, i);
		vector<ll>(n + 1, 1).swap(dp);
	}
	ll cnt = *max_element(res.begin() + 1, res.end());
	vector<ll>ans;
	for (ll i = 1; i <= m; ++i)
	{
		if (cnt == res[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}