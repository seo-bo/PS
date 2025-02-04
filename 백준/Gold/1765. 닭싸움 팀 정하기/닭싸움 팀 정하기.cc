#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>no(n + 1);
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return ((parent[root] == root) ? parent[root] : parent[root] = find(parent[root]));
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a);
			int r2 = find(b);
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
	for (int i = 0; i < m; ++i)
	{
		char a;
		int b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 'E')
		{
			no[b].push_back(c);
			no[c].push_back(b);
		}
		else
		{
			merge(b, c);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (no[i].empty())
		{
			continue;
		}
		int pivot = no[i].front();
		for (int j = 1; j < no[i].size(); ++j)
		{
			merge(pivot, no[i][j]);
		}
	}
	unordered_set<int>s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(find(i));
	}
	cout << s.size();
	return 0;
}