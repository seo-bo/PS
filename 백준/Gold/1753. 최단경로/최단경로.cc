#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, st = 0;
	cin >> n >> m >> st;
	vector<vector<pii>>graph(n + 1);
	vector<ll>dis(n + 1, INT_MAX);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
	}
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(make_pair(0, st));
	while (!pq.empty())
	{
		auto [x, y] = pq.top();
		pq.pop();
		if (dis[y] < x)
		{
			continue;
		}
		for (auto& [nw, nv] : graph[y])
		{
			if (dis[nv] > x + nw)
			{
				dis[nv] = x + nw;
				pq.push(make_pair(dis[nv], nv));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (dis[i] == INT_MAX)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << dis[i] << '\n';
		}
	}
	return 0;
}