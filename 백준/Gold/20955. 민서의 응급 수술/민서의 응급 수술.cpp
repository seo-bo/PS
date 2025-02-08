#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
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
				if (rank[r1] < rank[r2])
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
	int e = 0, ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			e++;
			merge(a, b);
		}
		else
		{
			ans++;
		}
	}
	cout << ans + n - 1 - e;
	return 0;
}