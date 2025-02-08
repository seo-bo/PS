#include <bits/stdc++.h>
#include <format>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 1;
	while (1)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		bool flag = true;
		if (!n && !m)
		{
			break;
		}
		vector<int>parent(n + 1, 0);
		vector<bool>check(n + 1, false), res(n + 1, false);
		iota(parent.begin(), parent.end(), 0);
		function<int(int)> find = [&](int root) -> int
			{
				if (parent[root] != root)
				{
					return parent[root] = find(parent[root]);
				}
				return parent[root];
			};
		auto merge = [&](int root1, int root2)
			{
				int r1 = find(root1);
				int r2 = find(root2);
				if (r1 != r2)
				{
					if (check[r1] || check[r2])
					{
						check[r1] = check[r2] = true;
					}
					else
					{
						parent[r2] = r1;
					}
				}
				else
				{
					check[r1] = check[r2] = true;
				}
			};
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			merge(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int target = find(i);
			if (!check[target] && !res[target])
			{
				res[target] = true;
				ans++;
			}
		}
		cout << format("Case {}: ", cnt++);
		if (!ans)
		{
			cout << format("No trees.\n");
		}
		else if (ans == 1)
		{
			cout << format("There is one tree.\n");
		}
		else
		{
			cout << format("A forest of {} trees.\n", ans);
		}
	}
	return 0;
}
