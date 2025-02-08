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
	vector<int>parent(n + 1, 0);
	vector<int>tour(m);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)->int
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
				parent[r2] = r1;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 1)
			{
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> tour[i];
	}
	int pivot = find(tour[0]);
	for (int i = 1; i < m; ++i)
	{
		if (find(tour[i]) != pivot)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}