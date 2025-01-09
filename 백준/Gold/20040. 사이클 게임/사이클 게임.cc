#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n, 0);
	vector<int>rank(n, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root) -> int
		{
			if (parent[root] != root)
			{
				parent[root] = find(parent[root]);
			}
			return parent[root];
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
				return false;
			}
				return true;
		};
	for (int i = 1; i <= m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (merge(a, b))
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}