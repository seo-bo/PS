#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m1 = 0, m2 = 0;
		cin >> n >> m1 >> m2;
		vector<vector<ll>>graph(n + 1);
		vector<pll>v(m1);
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		for (ll i = 0; i < m2; ++i)
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		ll cnt = 1;
		auto bfs = [&]
			{
				vector<ll>id(n + 1, -1);
				queue<ll>q;
				for (ll i = 1; i <= n; ++i)
				{
					if (id[i] == -1)
					{
						id[i] = cnt;
						q.push(i);
						while (!q.empty())
						{
							ll cur = q.front();
							q.pop();
							for (auto& j : graph[cur])
							{
								if (id[j] != -1)
								{
									continue;
								}
								id[j] = cnt;
								q.push(j);
							}
						}
						cnt++;
					}
				}
				return id;
			};
		vector<ll>id = bfs();
		vector<ll>parent(n + 1, 0), rank(n + 1, 0);
		iota(parent.begin(), parent.end(), 0);
		function<ll(ll)> find = [&](ll root)
			{
				return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
			};
		auto merge = [&](ll a, ll b)
			{
				ll r1 = find(a), r2 = find(b);
				if (r1 != r2)
				{
					if (rank[r1] > rank[r2])
					{
						parent[r2] = r1;
					}
					else
					{
						parent[r1] = r2;
						if (rank[r1] == rank[r2])
						{
							rank[r2]++;
						}
					}
				}
			};
		ll ans = 0;
		for (auto& [a, b] : v)
		{
			if (id[a] != id[b])
			{
				ans++;
			}
			else
			{
				if (find(a) != find(b))
				{
					merge(a, b);
				}
			}
		}
		vector<set<ll>>temp(cnt + 2);
		for (ll i = 1; i <= n; ++i)
		{
			temp[id[i]].insert(find(i));
		}
		for (ll i = 1; i <= cnt; ++i)
		{
			if (!temp[i].empty())
			{
				ans += (ll)temp[i].size() - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
