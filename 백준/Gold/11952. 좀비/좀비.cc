#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0, s = 0;
	cin >> n >> m >> k >> s;
	ll p = 0, q = 0;
	cin >> p >> q;
	vector<int>safe(n + 1, INT_MAX);
	vector<vector<int>>graph(n + 1);
	{
		queue<int>q;
		for (int i = 0; i < k; ++i)
		{
			int temp = 0;
			cin >> temp;
			q.push(temp);
			safe[temp] = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto& i : graph[cur])
			{
				int cost = safe[cur] + 1;
				if (safe[i] > cost)
				{
					safe[i] = cost;
					q.push(i);
				}
			}
		}
	}
	vector<ll>dist(n + 1, LLONG_MAX);
	dist[1] = 0;
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [cost, ver] = pq.top();
		pq.pop();
		if (dist[ver] < cost)
		{
			continue;
		}
		for (auto& nv : graph[ver])
		{
			if (safe[nv] == 0)
			{
				continue;
			}
			if (safe[nv] <= s)
			{
				if (dist[nv] > cost + q)
				{
					dist[nv] = cost + q;
					pq.push(make_pair(dist[nv], nv));
				}
			}
			else
			{
				if (dist[nv] > cost + p)
				{
					dist[nv] = cost + p;
					pq.push(make_pair(dist[nv], nv));
				}
			}
		}
	}
	ll ans = LLONG_MAX;
	for (auto& i : graph[n])
	{
		ans = min(ans, dist[i]);
	}
	cout << ans;
	return 0;
}