#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	vector<pii>dis(n + 1, make_pair(INT_MAX, -1));
	dis[1] = make_pair(0, 1);
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [we, ve] = pq.top();
		pq.pop();
		if (dis[ve].first < we)
		{
			continue;
		}
		for (auto& [nw, nv] : graph[ve])
		{
			if (dis[nv].first > we + nw)
			{
				dis[nv].first = we + nw;
				dis[nv].second = ve;
				pq.push(make_pair(dis[nv].first, nv));
			}
		}
	}
	vector<pii>ans;
	for (int i = 2; i <= n; ++i)
	{
		if (dis[i].second != -1)
		{
			ans.push_back(make_pair(i, dis[i].second));
		}
	}
	cout << ans.size() << '\n';
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}