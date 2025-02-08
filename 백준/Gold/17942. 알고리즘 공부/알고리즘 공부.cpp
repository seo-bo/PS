#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, set<int>>ss;
	vector<int>cost(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		ss[cost[i]].insert(i);
		v[i] = cost[i];
	}
	int q = 0;
	cin >> q;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < q; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
	}
	ll ans = 0;
	while (m--)
	{
		auto it = ss.begin()->first;
		auto jt = ss[it].begin();
		int pivot = *jt;
		ans = max(ans, (ll)cost[pivot]);
		ss[it].erase(jt);
		cost[pivot] = -1;
		if (ss[it].empty())
		{
			ss.erase(it);
		}
		for (auto& [a, b] : graph[pivot])
		{
			if (cost[b] == -1)
			{
				continue;
			}
			ss[cost[b]].erase(b);
			if (ss[cost[b]].empty())
			{
				ss.erase(cost[b]);
			}
			cost[b] = max(0, cost[b] - a);
			ss[cost[b]].insert(b);
		}

	}
	cout << ans;
	return 0;
}