#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll, ll>ti;
typedef tuple<ll, ll, ll>tp;
typedef pair<ll, ll>pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ti>>graph(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_tuple(b, c, 1, i));
		graph[a].push_back(make_tuple(b, c * 2, 0, i));
		graph[b].push_back(make_tuple(a, c * 2, 0, i));
	}
	vector<tp>dist(n + 1, make_tuple(LLONG_MAX, -1, -1));
	dist[1] = make_tuple(0, 0, 0);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [co, ve] = pq.top();
		pq.pop();
		if (get<0>(dist[ve]) < co)
		{
			continue;
		}
		for (auto& [nv, nc, nt, cnt] : graph[ve])
		{
			if (get<0>(dist[nv]) > get<0>(dist[ve]) + nc)
			{
				dist[nv] = make_tuple(get<0>(dist[ve]) + nc, nt, cnt);
				pq.push(make_pair(get<0>(dist[nv]), nv));
			}
		}
	}
	ll ans = 0;
	vector<int>res(m + 1);
	for (int i = 2; i <= n; ++i)
	{
		ans += get<0>(dist[i]);
		if (get<1>(dist[i]) == 1)
		{
			res[get<2>(dist[i])] = 1;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= m; ++i)
	{
		cout << res[i] << ' ';
	}
	return 0;
}