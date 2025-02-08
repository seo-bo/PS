#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, A = 0, B = 0, C = 0;
	cin >> n >> m >> A >> B >> C;
	vector<vector<ll>>senpai(n + 1);
	vector<vector<pll>>go(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		senpai[a].push_back(b);
		senpai[b].push_back(a);
		go[a].push_back(make_pair(c, b));
		go[b].push_back(make_pair(c, a));
	}
	auto bfs = [&](ll start)
		{
			vector<ll>visited(n + 1, LLONG_MAX);
			queue<ll>q;
			q.push(start);
			visited[start] = 0;
			while (!q.empty())
			{
				auto ver = q.front();
				q.pop();
				for (auto& i : senpai[ver])
				{
					if (visited[i] > visited[ver] + 1)
					{
						visited[i] = visited[ver] + 1;
						q.push(i);
					}
				}
			}
			return visited;
		};
	vector<ll>d1 = bfs(B);
	vector<ll>d2 = bfs(C);
	vector<ll>path;
	path.push_back(B);
	ll x = B, distance = d1[C];
	while (x != C)
	{
		ll cnt = path.size(), pivot = -1, num = -1;
		for (auto& i : senpai[x])
		{
			ll siz = senpai[i].size();
			if (d1[i] == cnt && d1[i] + d2[i] == distance)
			{
				if (num < siz)
				{
					pivot = i;
					num = senpai[i].size();
				}
				else if (num == siz)
				{
					pivot = max(i, pivot);
				}
			}
		}
		x = pivot;
		path.push_back(x);
	}
	auto dijkstra = [&]
		{
			vector<ll>dist(n + 1, LLONG_MAX);
			dist[A] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push(make_pair(0, A));
			while (!pq.empty())
			{
				auto [cnt, ver] = pq.top();
				pq.pop();
				if (dist[ver] < cnt)
				{
					continue;
				}
				for (auto& [nc, nv] : go[ver])
				{
					ll cost = dist[ver] + nc;
					if (dist[nv] > cost)
					{
						dist[nv] = cost;
						pq.push(make_pair(dist[nv], nv));
					}
				}
			}
			ll ans = LLONG_MAX, pivot = LLONG_MAX;
			for (auto& i : path)
			{
				if (dist[i] < pivot)
				{
					ans = i;
				}
				else if (dist[i] == pivot)
				{
					ans = min(ans, i);
				}
				pivot = min(pivot, dist[i]);
			}
			return ans;
		};
	cout << dijkstra();
	return 0;
}