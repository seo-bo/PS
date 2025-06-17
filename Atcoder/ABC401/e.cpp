#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	vector<ll>parent(n + 1, 0), rank(n + 1, 1);
	iota(parent.begin(), parent.end(), 0);
	function<ll(ll)> find = [&](ll root)
		{
			return (parent[root] == root) ? root : parent[root] = find(parent[root]);
		};
	auto merge = [&](ll a, ll b)
		{
			ll r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
					rank[r1] += rank[r2];
					rank[r2] = 0;
				}
				else
				{
					parent[r1] = r2;
					rank[r2] += rank[r1];
					rank[r1] = 0;
				}
			}
		};
	vector<ll>mini(n + 1, LLONG_MAX), prefix(n + 3, 0);
	mini[1] = 0;
	for (ll i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[b].push_back(a);
		mini[b] = min(mini[b], a);
	}
	for (ll i = 2; i <= n; ++i)
	{
		if (mini[i] != LLONG_MAX)
		{
			prefix[mini[i]]++;
			prefix[i]--;
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i] + prefix[i - 1];
	}
	vector<bool>visited(n + 1, false);
	visited[1] = true;
	for (ll i = 2; i <= n; ++i)
	{
		for (auto& j : graph[i])
		{
			merge(i, j);
		}
		if (rank[find(1)] == i)
		{
			visited[i] = true;
		}
	}
	for (ll i = 1; i <= n; ++i)
	{
		cout << ((visited[i]) ? prefix[i] : -1) << '\n';
	}
	return 0;
}
