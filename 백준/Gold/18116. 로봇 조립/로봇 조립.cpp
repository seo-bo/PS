#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>parent(1e6 + 1, 0), rank(1e6 + 1, 1);
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
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
					rank[r1] += rank[r2];
				}
				else
				{
					parent[r1] = r2;
					rank[r2] += rank[r1];
				}
			}
		};
	while (n--)
	{
		char a;
		int b = 0, c = 0;
		cin >> a >> b;
		if (a == 'I')
		{
			cin >> c;
			if (find(b) != find(c))
			{
				merge(b, c);
			}
		}
		else
		{
			cout << rank[find(b)] << '\n';
		}
	}
	return 0;
}