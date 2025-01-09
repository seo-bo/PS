#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<pii>>graph(n + 1);
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	vector<ll>dis(n + 1, LLONG_MAX);
	dis[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dis[v])
		{
			continue;
		}
		for (auto& [nw, nv] : graph[v])
		{
			if (dis[nv] > dis[v] + nw)
			{
				dis[nv] = dis[v] + nw;
				pq.push(make_pair(dis[nv], nv));
			}
		}
	}
	ll z = 0;
	cin >> z;
	ll cycle = z * k;
	ll ans = LLONG_MAX;
	for (ll i = 0; i < z; ++i)
	{
		ll node = 0;
		cin >> node;
		if (dis[node] == LLONG_MAX)
		{
			continue;
		}
		ll pos = dis[node] % cycle, start = i * k, end = (i + 1) * k;
		if (start <= pos && pos < end) // 열림
		{
			ans = min(ans, dis[node]);
		}
		else if (pos < start) // 아직 안열림
		{
			ans = min(ans, dis[node] + (start - pos));
		}
		else // 한사이클 기다리기
		{
			ans = min(ans, dis[node] + (cycle - pos) + start);
		}
	}
	cout << ans;
	return 0;
}
