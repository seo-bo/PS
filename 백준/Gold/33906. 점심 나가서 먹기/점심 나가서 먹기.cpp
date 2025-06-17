#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	vector<ll>c1(n + 1), c2(n + 1);
	unordered_set<ll>v1, v2;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c1[i];
		if (!c1[i])
		{
			c1[i] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> c2[i];
		if (!c2[i])
		{
			c2[i] = INT_MAX;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	{
		queue<int>q;
		vector<bool>visited(n + 1, false);
		q.push(1);
		visited[1] = true;
		ll a = LLONG_MAX, b = LLONG_MAX;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			a = min(a, c1[cur]);
			b = min(b, c2[cur]);
			for (auto& [i, _] : graph[cur])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i])
			{
				if (c1[i] == a)
				{
					v1.insert(i);
				}
				if (c2[i] == b)
				{
					v2.insert(i);
				}
			}
		}
	}
	vector<vector<ll>>dist(4, vector<ll>(n + 1, LLONG_MAX));
	dist[0][1] = 0;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(0, 0, 1));
	while (!pq.empty())
	{
		auto [cost, flag, ver] = pq.top();
		pq.pop();
		if (dist[flag][ver] < cost)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			ll nf = flag;
			if (v1.find(nv) != v1.end())
			{
				nf |= 1;
			}
			if (v2.find(nv) != v2.end())
			{
				nf |= 2;
			}
			if (dist[nf][nv] > dist[flag][ver] + nc)
			{
				dist[nf][nv] = dist[flag][ver] + nc;
				pq.push(make_tuple(dist[nf][nv], nf, nv));
			}
		}
	}
	cout << dist[3][1];
	return 0;
}