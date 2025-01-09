#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>id(n + 1, 0), parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r2] = r1;
					rank[r1]++;
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		char a;
		cin >> a;
		if (a == 'M')
		{
			id[i] = 1;
		}
		else
		{
			id[i] = 2;
		}
	}
	vector<ti>graph;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (id[a] != id[b])
		{
			graph.push_back(make_tuple(c, a, b));
		}
	}
	sort(graph.begin(), graph.end());
	int e = 0;
	ll ans = 0;
	int len = graph.size();
	for (int i = 0; i < len && e < n - 1; ++i)
	{
		auto [w, v1, v2] = graph[i];
		int r1 = find(v1), r2 = find(v2);
		if (r1 != r2)
		{
			merge(v1, v2);
			e++;
			ans += w;
		}
	}
	cout << ((e == n - 1) ? ans : -1);
	return 0;
}