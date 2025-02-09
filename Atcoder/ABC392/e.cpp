#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return ((parent[root] == root) ? parent[root] : parent[root] = find(parent[root]));
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
	vector<tp>v;
	for (int i = 1; i <= m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
		}
		else
		{
			v.push_back(make_tuple(i, a, b));
		}
	}
	set<int>s;
	for (int i = 1; i <= n; ++i)
	{
		s.insert(find(i));
	}
	int len = v.size();
	vector<tp>ans;
	for (int i = 0; i < len && s.size() > 1; ++i)
	{
		auto [idx, st, ed] = v[i];
		int pivot = -1;
		for (auto& j : s)
		{
			if (find(st) != find(j))
			{
				pivot = j;
				break;
			}
		}
		if (pivot == -1)
		{
			break;
		}
		ans.push_back(make_tuple(idx, st, pivot));
		s.erase(find(pivot));
		merge(st, pivot);
	}
	cout << ans.size() << '\n';
	for (auto& [a, b, c] : ans)
	{
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	return 0;
}
