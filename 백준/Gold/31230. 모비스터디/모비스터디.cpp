#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, A = 0, B = 0;
	cin >> n >> m >> A >> B;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	auto dijkstra = [&](int start)
		{
			vector<ll>dist(n + 1, LLONG_MAX);
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, start));
			dist[start] = 0;
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
					if (dist[nv] > dist[ver] + nc)
					{
						dist[nv] = dist[ver] + nc;
						pq.push(make_pair(dist[nv], nv));
					}
				}
			}
			return dist;
		};
	vector<ll> d1 = dijkstra(A);
	vector<ll> d2 = dijkstra(B);
	if (d1[A] == LLONG_MAX || d2[A] == LLONG_MAX)
	{
		cout << 0;
		return 0;
	}
	ll pivot = d1[A] + d2[A];
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX)
		{
			continue;
		}
		if (d1[i] + d2[i] == pivot)
		{
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}