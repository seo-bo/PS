#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>parent(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
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
				if (!r2)
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r2] = r1;
				}
			}
		};
	for (int i = 0; i < k; ++i)
	{
		int temp = 0;
		cin >> temp;
		parent[temp] = 0;
	}
	vector<ti>v(m);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	sort(v.begin(), v.end(), [&](const ti& a, const ti& b)
		{
			return get<2>(a) < get<2>(b);
		});
	int ans = 0, e = 0;
	for (auto& [a, b, c] : v)
	{
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
			ans += c;
			if (++e == n - k)
			{
				break;
			}
		}
	}
	cout << ans;
	return 0;
}