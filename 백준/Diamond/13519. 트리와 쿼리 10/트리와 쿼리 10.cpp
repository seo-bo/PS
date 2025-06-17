#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	ll sum, prefix, suffix, maxi, num;
	bool lazy;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	Node base = { 0,0,0,0,0,false };
	vector<Node>tree(4 * (n + 3), base);
	auto comb = [&](Node left, Node right)
		{
			Node res;
			res.sum = left.sum + right.sum;
			res.prefix = max({ 0LL,left.prefix, left.sum + right.prefix });
			res.suffix = max({ 0LL,right.suffix, right.sum + left.suffix });
			res.maxi = max({ 0LL,left.maxi, right.maxi, left.suffix + right.prefix });
			res.num = 0;
			res.lazy = false;
			return res;
		};
	auto cal = [&](int start, int end, int node, ll delta)
		{
			ll cost = (end - start + 1) * delta;
			tree[node].sum = cost;
			tree[node].prefix = max(0LL, cost);
			tree[node].suffix = max(0LL, cost);
			tree[node].maxi = max(0LL, cost);
			tree[node].num = delta;
			tree[node].lazy = true;
		};
	auto lazy_update = [&](int start, int end, int node)
		{
			if (tree[node].lazy)
			{
				int mid = (start + end) >> 1;
				cal(start, mid, node * 2, tree[node].num);
				cal(mid + 1, end, node * 2 + 1, tree[node].num);
				tree[node].lazy = false;
			}
		};
	function<void(int, int, int, int, int, ll)> update = [&](int start, int end, int node, int left, int right, ll delta)
		{
			if (left > end || right < start)
			{
				return;
			}
			if (left <= start && end <= right)
			{
				cal(start, end, node, delta);
				return;
			}
			lazy_update(start, end, node);
			int mid = (start + end) >> 1;
			update(start, mid, node * 2, left, right, delta);
			update(mid + 1, end, node * 2 + 1, left, right, delta);
			tree[node] = comb(tree[node * 2], tree[node * 2 + 1]);
		};
	function<Node(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (left > end || right < start)
			{
				return base;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			lazy_update(start, end, node);
			int mid = (start + end) >> 1;
			return comb(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	vector<ll>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>sum(n + 1), depth(n + 1), chain(n + 1), parent(n + 1), head(n + 1);
	function<int(int, int, int)> dfs = [&](int par, int node, int d)
		{
			depth[node] = d;
			parent[node] = par;
			sum[node] = 1;
			for (auto& i : graph[node])
			{
				if (i == par)
				{
					continue;
				}
				sum[node] += dfs(node, i, d + 1);
			}
			return sum[node];
		};
	dfs(0, 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		if (!graph[i].empty())
		{
			sort(graph[i].begin(), graph[i].end(), [&](const int& a, const int& b)
				{
					return sum[a] > sum[b];
				});
		}
	}
	int ver = 1;
	head[1] = 1;
	function<void(int, int)> hld = [&](int par, int node)
		{
			chain[node] = ver++;
			bool flag = false;
			for (auto& i : graph[node])
			{
				if (i == par)
				{
					continue;
				}
				if (!flag)
				{
					flag = true;
					head[i] = head[node];
				}
				else
				{
					head[i] = i;
				}
				hld(node, i);
			}
			update(1, n, 1, chain[node], chain[node], cost[node]);
		};
	hld(0, 1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		ll d = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Node left = base, right = base;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					left = comb(query(1, n, 1, chain[head[b]], chain[b]), left);
					b = parent[head[b]];
				}
				else
				{
					right = comb(query(1, n, 1, chain[head[c]], chain[c]), right);
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				left = comb(query(1, n, 1, chain[c], chain[b]), left);
			}
			else
			{
				right = comb(query(1, n, 1, chain[b], chain[c]), right);
			}
			swap(left.prefix, left.suffix);
			cout << comb(left, right).maxi << '\n';
		}
		else
		{
			cin >> d;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					update(1, n, 1, chain[head[b]], chain[b], d);
					b = parent[head[b]];
				}
				else
				{
					update(1, n, 1, chain[head[c]], chain[c], d);
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				swap(b, c);
			}
			update(1, n, 1, chain[b], chain[c], d);
		}
	}
	return 0;
}