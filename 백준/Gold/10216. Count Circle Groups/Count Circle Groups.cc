#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>parent(n + 1, 0);
		iota(parent.begin(), parent.end(), 0);
		vector<int>rank(n + 1, 0);
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
		auto cal = [&](int x1, int x2, int y1, int y2)
			{
				return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			};
		vector<ti>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			auto& [a, b, c] = v[i];
			cin >> a >> b >> c;
		}
		for (int i = 1; i <= n; ++i)
		{
			int r1 = find(i);
			auto [x1, y1, l1] = v[i];
			for (int j = i + 1; j <= n; ++j)
			{
				int r2 = find(j);
				if (r1 != r2)
				{
					auto [x2, y2, l2] = v[j];
					int dis = cal(x1, x2, y1, y2);
					int p = (l1 + l2) * (l1 + l2);
					if (dis <= p)
					{
						merge(i, j);
					}
				}
			}
		}
		unordered_set<int>ans;
		for (int i = 1; i <= n; ++i)
		{
			ans.insert(find(i));
		}
		cout << ans.size() << '\n';
	}
	return 0;
}