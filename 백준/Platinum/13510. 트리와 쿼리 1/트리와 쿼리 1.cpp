#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
	vector<int>tree((n + 1) * 4);
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int delta)
		{
			if (start > idx || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] = delta;
				return;
			}
			int mid = (start + end) >> 1;
			update(start, mid, node * 2, idx, delta);
			update(mid + 1, end, node * 2 + 1, idx, delta);
			tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
		};
	function<int(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (left > end || right < start)
			{
				return -1;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) >> 1;
			return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	vector<pii>e(n);
	for (int i = 1; i <= n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
		e[i] = make_pair(a, b);
	}
	vector<int>sum(n + 1), parent(n + 1), depth(n + 1), chain(n + 1), head(n + 1);
	function<int(int, int, int)> dfs = [&](int par, int node, int d)
		{
			parent[node] = par;
			depth[node] = d;
			int cnt = 1;
			for (auto& [i, _] : graph[node])
			{
				if (par == i)
				{
					continue;
				}
				cnt += dfs(node, i, d + 1);
			}
			return sum[node] = cnt;
		};
	dfs(0, 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const pii& a, const pii& b)
			{
				return sum[a.first] > sum[b.first];
			});
	}
	int ver = 1;
	function<void(int, int)> hld = [&](int par, int node)
		{
			chain[node] = ver++;
			bool flag = true;
			for (auto& [a, b] : graph[node])
			{
				if (par == a)
				{
					continue;
				}
				if (flag)
				{
					head[a] = head[node];
					flag = false;
				}
				else
				{
					head[a] = a;
				}
				hld(node, a);
				update(1, n, 1, chain[a], b);
			}

		};
	head[1] = 1;
	hld(0, 1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			auto [x, y] = e[b];
			if (depth[x] < depth[y])
			{
				swap(x, y);
			}
			update(1, n, 1, chain[x], c);
		}
		else
		{
			int ans = 0;
			while (head[b] != head[c])
			{
				if (depth[head[b]] > depth[head[c]])
				{
					int st = min(chain[head[b]], chain[b]);
					int ed = max(chain[head[b]], chain[b]);
					ans = max(ans, query(1, n, 1, st, ed));
					b = parent[head[b]];
				}
				else
				{
					int st = min(chain[head[c]], chain[c]);
					int ed = max(chain[head[c]], chain[c]);
					ans = max(ans, query(1, n, 1, st, ed));
					c = parent[head[c]];
				}
			}
			if (depth[b] > depth[c])
			{
				swap(b, c);
			}
			if (b != c)
			{
				ans = max(ans, query(1, n, 1, chain[b] + 1, chain[c]));
			}
			cout << ans << '\n';
		}
	}
	return 0;
}