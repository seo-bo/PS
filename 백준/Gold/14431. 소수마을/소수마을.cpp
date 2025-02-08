#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<bool>prime(10001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(10000); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	auto dis = [&](int xx, int yy, int nx, int ny)
		{
			return sqrt((xx - nx) * (xx - nx) + (yy - ny) * (yy - ny));
		};
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, n = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	map<pii, vector<pair<int, pii>>>graph;
	map<pii, int>mindis;
	vector<pii>v(n + 2);
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>>pq;
	v[0] = { x1, y1 };
	v[1] = { x2, y2 };
	for (int i = 2; i < n + 2; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < n + 2; ++i)
	{
		auto [a, b] = v[i];
		mindis[v[i]] = INF;
		for (int j = i + 1; j < n + 2; ++j)
		{
			auto [c, d] = v[j];
			int f = dis(a, b, c, d);
			if (prime[f])
			{
				graph[v[i]].push_back(make_pair(f, v[j]));
				graph[v[j]].push_back(make_pair(f, v[i]));
			}
		}
	}
	mindis[v[0]] = 0;
	pq.push(make_pair(0, v[0]));
	while (!pq.empty())
	{
		auto [a, b] = pq.top();
		pq.pop();
		if (a > mindis[b])
		{
			continue;
		}
		for (auto& [c, d] : graph[b])
		{
			int ne = a + c;
			if (ne < mindis[d])
			{
				mindis[d] = ne;
				pq.push(make_pair(ne, d));
			}
		}
	}
	int ans = mindis[{x2, y2}];
	(ans == INF || !ans) ? (cout << -1) : (cout << ans);
	return 0;
}