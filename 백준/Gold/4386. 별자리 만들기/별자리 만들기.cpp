#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

struct cmp
{
	bool operator() (const tuple<double, int, int>& a, const tuple<double, int, int>& b)
	{
		return get<0>(a) > get<0>(b);
	}
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	map<int, pdd>mm; // 정점번호, 좌표
	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, cmp>pq;
	cin >> n;
	vector<int>parent(n + 1, 0);
	vector<int>rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	for (int i = 1; i <= n; ++i)
	{
		double a = 0, b = 0;
		cin >> a >> b;
		mm[i] = make_pair(a, b);
	}
	auto dis = [&](int p1, int p2)
		{
			auto [a, b] = mm[p1];
			auto [c, d] = mm[p2];
			return (a - c) * (a - c) + (b - d) * (b - d);
		};
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
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			double dd = dis(i, j);
			if (mm[i] == mm[j])
			{
				continue;
			}
			pq.push(make_tuple(dd, i, j));
		}
	}
	int e = 0;
	double ans = 0;
	while (e < n - 1 && !pq.empty())
	{
		auto [a, b, c] = pq.top();
		pq.pop();
		int r1 = find(b), r2 = find(c);
		if (r1 != r2)
		{
			merge(r1, r2);
			e++;
			ans += sqrt(a);
		}
	}
	cout << fixed << setprecision(9) << ans;
	return 0;
}