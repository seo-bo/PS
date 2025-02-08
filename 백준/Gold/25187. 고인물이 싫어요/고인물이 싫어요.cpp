#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<int>parent(n + 1, 0), rank(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		c[i] = temp;
		d[i] = (temp + 1) % 2;
	}
	function<int(int)> find = [&](int root)
		{
			return ((parent[root] == root) ? parent[root] : parent[root] = find(parent[root]));
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
					c[r1] += c[r2];
					d[r1] += d[r2];
					c[r2] = d[r2] = 0;
				}
				else
				{
					parent[r1] = r2;
					c[r2] += c[r1];
					d[r2] += d[r1];
					c[r1] = d[r1] = 0;
					if (rank[r1] == rank[r2])
					{
						rank[r2]++;
					}
				}
			}
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
		}
	}
	while (q--)
	{
		int a = 0;
		cin >> a;
		a = find(a);
		cout << (c[a] > d[a]) << '\n';
	}
	return 0;
}