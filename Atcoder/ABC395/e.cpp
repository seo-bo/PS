#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, x = 0;
	cin >> n >> m >> x;
	vector<vector<ll>>graph(n + 1);
	vector<vector<ll>>rev(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		rev[b].push_back(a);
	}
	ll d = 0;
	vector<vector<ll>>dist(n + 1, vector<ll>(2, LLONG_MAX));
	dist[1][0] = 0;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(0, 1, 0)); // cost,ver, dir
	while (!pq.empty())
	{
		auto [cost, ver, dir] = pq.top();
		pq.pop();
		if (dist[ver][dir] < cost)
		{
			continue;
		}
		ll pp = (dir + 1) % 2;
		if (dist[ver][pp] > dist[ver][dir] + x)
		{
			dist[ver][pp] = dist[ver][dir] + x;
			pq.push(make_tuple(dist[ver][pp], ver, pp));
		}
		if (dir == 0)
		{
			for (auto& i : graph[ver])
			{
				if (dist[i][dir] > dist[ver][dir] + 1)
				{
					dist[i][dir] = dist[ver][dir] + 1;
					pq.push(make_tuple(dist[i][dir], i, dir));
				}
			}
		}
		if (dir == 1)
		{
			for (auto& i : rev[ver])
			{
				if (dist[i][dir] > dist[ver][dir] + 1)
				{
					dist[i][dir] = dist[ver][dir] + 1;
					pq.push(make_tuple(dist[i][dir], i, dir));
				}
			}
		}
	}
	cout << min(dist[n][0], dist[n][1]);
	return 0;
}
