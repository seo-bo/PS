#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, a = 0, b = 0, c = 0;
	cin >> n >> m >> a >> b >> c;
	vector<vector<ll>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	auto bfs = [&](ll st)
		{
			vector<ll>dist(n + 1, -1);
			queue<ll>q;
			q.push(st);
			dist[st] = 0;
			while (!q.empty())
			{
				ll a = q.front();
				q.pop();
				for (auto& i : graph[a])
				{
					if (dist[i] == -1)
					{
						dist[i] = dist[a] + 1;
						q.push(i);
					}
				}
			}
			return dist;
		};
	vector<ll>dis1 = bfs(1);
	vector<ll>dis2 = bfs(b);
	if (dis1[a] != -1 && dis2[a] != -1 && dis2[n] != -1 && dis2[a] < c)
	{
		cout << "-inf";
		return 0;
	}
	if (dis1[n] == -1 && (dis1[a] == -1 || dis2[n] == -1))
	{
		cout << "x";
		return 0;
	}
	ll ans = LLONG_MAX;
	if (dis1[n] != -1)
	{
		ans = min(ans, dis1[n]);
	}
	if (dis1[a] != -1 && dis2[n] != -1)
	{
		ans = min(ans, dis1[a] - c + dis2[n]);
	}
	cout << ((ans == LLONG_MAX) ? "x" : to_string(ans));
	return 0;
}