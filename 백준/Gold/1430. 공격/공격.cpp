#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

class DSU //https://github.com/seo-bo/Algorithm_templates/blob/main/DSU.cpp
{
private:
	int n;
	vector<int>parent, rank;
	int get_path(int root)
	{
		return (parent[root] == root) ? parent[root] : parent[root] = get_path(parent[root]);
	}
	void merger(int root1, int root2)
	{
		int r1 = get_path(root1), r2 = get_path(root2);
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
	}
public:
	DSU(int ok)
	{
		n = ok;
		parent.resize(n + 1, 0);
		rank.resize(n + 1, 0);
		rank[0] = 100;
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int root)
	{
		return get_path(root);
	}
	void merge(int root1, int root2)
	{
		merger(root1, root2);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, r = 0, d = 0, x = 0, y = 0;
	cin >> n >> r >> d >> x >> y;
	vector<pii>rev(n + 1);
	rev[0] = make_pair(x, y);
	DSU par(n);
	auto cal = [&](int a, int b, int c, int d)
		{
			return ((a - c) * (a - c) + (b - d) * (b - d)) <= r * r;
		};
	vector<int>node;
	ld ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		rev[i] = make_pair(a, b);
		if (cal(x, y, a, b))
		{
			par.merge(0, i);
			ans += d;
		}
		else
		{
			node.push_back(i);
		}
	}
	int len = node.size();
	vector<vector<int>>graph(n + 1);
	for (auto& i : node)
	{
		auto [a, b] = rev[i];
		for (int j = 0; j <= n; ++j)
		{
			auto [c, d] = rev[j];
			if (par.find(i) == par.find(j))
			{
				continue;
			}
			if (cal(a, b, c, d))
			{
				graph[par.find(i)].push_back(par.find(j));
				graph[par.find(j)].push_back(par.find(i));
			}
		}
	}
	auto bfs = [&](int st)
		{
			queue<int>q;
			q.push(st);
			vector<int>dist(n + 1, INT_MAX);
			dist[st] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& i : graph[cur])
				{
					if (dist[i] > dist[cur] + 1)
					{
						dist[i] = dist[cur] + 1;
						q.push(i);
					}
				}
			}
			ld pivot = d;
			if (dist[0] == INT_MAX)
			{
				return (ld)0;
			}
			for (int i = 0; i < dist[0]; ++i)
			{
				pivot /= (ld)2;
			}
			return pivot;
		};
	for (auto& i : node)
	{
		ans += bfs(i);
	}
	cout << fixed << setprecision(8) << ans;
	return 0;
}