#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;

struct Node
{
	ll sum, mul, add;
	bool lazy;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<Node>tree(4 * (n + 3), { 0U,1U,0U, false });
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	auto cal_add = [&](int start, int end, int node, ll delta)
		{
			ll pivot = (end - start + 1) * delta;
			tree[node].sum = tree[node].sum + pivot;
			tree[node].add = tree[node].add + delta;
			tree[node].lazy = true;
		};
	auto cal_mul = [&](int start, int end, int node, ll delta)
		{
			tree[node].sum = tree[node].sum * delta;
			tree[node].mul = tree[node].mul * delta;
			tree[node].add = tree[node].add * delta;
			tree[node].lazy = true;
		};
	auto lazy_update = [&](int start, int end, int node)
		{
			if (tree[node].lazy)
			{
				if (start != end)
				{
					int mid = (start + end) >> 1;
					cal_mul(start, mid, node * 2, tree[node].mul);
					cal_mul(mid + 1, end, node * 2 + 1, tree[node].mul);
					cal_add(start, mid, node * 2, tree[node].add);
					cal_add(mid + 1, end, node * 2 + 1, tree[node].add);
				}
				tree[node].mul = 1U;
				tree[node].add = 0U;
				tree[node].lazy = false;
			}
		};
	function<void(int, int, int, int, int, int)> add_update = [&](int start, int end, int node, int left, int right, ll delta)
		{
			lazy_update(start, end, node);
			if (right < start || end < left)
			{
				return;
			}
			if (left <= start && end <= right)
			{
				cal_add(start, end, node, delta);
				return;
			}
			int mid = (start + end) >> 1;
			add_update(start, mid, node * 2, left, right, delta);
			add_update(mid + 1, end, node * 2 + 1, left, right, delta);
			tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
		};
	function<void(int, int, int, int, int, int)> mul_update = [&](int start, int end, int node, int left, int right, ll delta)
		{
			lazy_update(start, end, node);
			if (right < start || end < left)
			{
				return;
			}
			if (left <= start && end <= right)
			{
				cal_mul(start, end, node, delta);
				return;
			}
			int mid = (start + end) >> 1;
			mul_update(start, mid, node * 2, left, right, delta);
			mul_update(mid + 1, end, node * 2 + 1, left, right, delta);
			tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
		};
	function<ll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			lazy_update(start, end, node);
			if (right < start || end < left)
			{
				return 0U;
			}
			if (left <= start && end <= right)
			{
				return tree[node].sum;
			}
			int mid = (start + end) >> 1;
			return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
		};
	vector<int>siz(n + 1), depth(n + 1), parent(n + 1), chain(n + 1), head(n + 1);
	function<int(int, int, int)> dfs = [&](int par, int node, int d)
		{
			parent[node] = par;
			depth[node] = d;
			int cnt = 1;
			for (auto& i : graph[node])
			{
				if (i == par)
				{
					continue;
				}
				cnt += dfs(node, i, d + 1);
			}
			return siz[node] = cnt;
		};
	dfs(0, 1, 1);
	head[1] = 1;
	int ver = 1;
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const int& a, const int& b)
			{
				return siz[a] > siz[b];
			});
	}
	function<void(int, int)> hld = [&](int par, int node)
		{
			chain[node] = ver++;
			bool flag = true;
			for (auto& i : graph[node])
			{
				if (par == i)
				{
					continue;
				}
				if (flag)
				{
					flag = false;
					head[i] = head[node];
				}
				else
				{
					head[i] = i;
				}
				hld(node, i);
			}
		};
	hld(0, 1);
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			ll c = 0;
			cin >> c;
			int st = chain[b], ed = chain[b] + siz[b] - 1;
			add_update(1, n, 1, st, ed, c);
		}
		else if (a == 2)
		{
			int c = 0;
			ll d = 0;
			cin >> c >> d;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					int st = min(chain[head[b]], chain[b]);
					int ed = max(chain[head[b]], chain[b]);
					add_update(1, n, 1, st, ed, d);
					b = parent[head[b]];
				}
				else
				{
					int st = min(chain[head[c]], chain[c]);
					int ed = max(chain[head[c]], chain[c]);
					add_update(1, n, 1, st, ed, d);
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				swap(b, c);
			}
			add_update(1, n, 1, chain[b], chain[c], d);
		}
		else if (a == 3)
		{
			ll c = 0;
			cin >> c;
			int st = chain[b], ed = chain[b] + siz[b] - 1;
			mul_update(1, n, 1, st, ed, c);
		}
		else if (a == 4)
		{
			int c = 0;
			ll d = 0;
			cin >> c >> d;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					int st = min(chain[head[b]], chain[b]);
					int ed = max(chain[head[b]], chain[b]);
					mul_update(1, n, 1, st, ed, d);
					b = parent[head[b]];
				}
				else
				{
					int st = min(chain[head[c]], chain[c]);
					int ed = max(chain[head[c]], chain[c]);
					mul_update(1, n, 1, st, ed, d);
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				swap(b, c);
			}
			mul_update(1, n, 1, chain[b], chain[c], d);
		}
		else if (a == 5)
		{
			int st = chain[b], ed = chain[b] + siz[b] - 1;
			ll ans = query(1, n, 1, st, ed);
			cout << ans << '\n';
		}
		else
		{
			int c = 0;
			cin >> c;
			ll ans = 0;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					int st = min(chain[head[b]], chain[b]);
					int ed = max(chain[head[b]], chain[b]);
					ans = ans + query(1, n, 1, st, ed);
					b = parent[head[b]];
				}
				else
				{
					int st = min(chain[head[c]], chain[c]);
					int ed = max(chain[head[c]], chain[c]);
					ans = ans + query(1, n, 1, st, ed);
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				swap(b, c);
			}
			ans = ans + query(1, n, 1, chain[b], chain[c]);
			cout << ans << '\n';
		}
	}
	return 0;
}