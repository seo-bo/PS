#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<tp>v(m);
	vector<int>parent(n + 1), rank(n + 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r2] > rank[r1])
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r2] = r1;
					if (rank[r1] == rank[r2])
					{
						rank[r1]++;
					}
				}
			}
		};
	ll ans = 0, e = 0;
	for (auto& [a, b, c] : v)
	{
		cin >> b >> c >> a;
		ans += a;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m && e < n - 1; ++i)
	{
		auto [a, b, c] = v[i];
		if (find(b) != find(c))
		{
			merge(b, c);
			e++;
			ans -= a;
		}
	}
	cout << ((e < n - 1) ? -1 : ans);
	return 0;
}