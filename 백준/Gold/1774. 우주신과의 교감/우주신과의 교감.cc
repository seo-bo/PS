#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, pdd>mm;
	vector<int>parent(n + 1, 0);
	vector<int>rank(n + 1, 0);
	auto cmp = [&](const tuple<double, int, int>& a, const tuple<double, int, int>& b)
		{
			return get<0>(a) > get<0>(b);
		};
	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, decltype(cmp)>pq(cmp);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root) ->int
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
			}
		};
	auto dis = [&](int p1, int p2)
		{
			auto [a, b] = mm[p1];
			auto [c, d] = mm[p2];
			return sqrt((a - c) * (a - c) + (b - d) * (b - d));
		};
	double ans = 0;
	int e = 0;
	for (int i = 1; i <= n; ++i)
	{
		double a = 0, b = 0;
		cin >> a >> b;
		mm[i] = make_pair(a, b);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			auto d = dis(i, j);
			pq.push(make_tuple(d, i, j));
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
			e++;
		}
	}
	while (e < n - 1 && !pq.empty())
	{
		auto [a, b, c] = pq.top();
		pq.pop();
		int r1 = find(b), r2 = find(c);
		if (r1 != r2)
		{
			merge(b, c);
			e++;
			ans += a;
		}
	}
	cout << fixed << setprecision(2) << round(ans * 100) / 100;
	return 0;
}