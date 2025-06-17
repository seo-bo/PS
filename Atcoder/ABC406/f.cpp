#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void) // https://www.acmicpc.net/source/93750619
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<vector<ll>>graph(n + 1);
	vector<pll>ok = { {0,0} };
	for (ll i = 1; i <= n - 1; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		ok.push_back(make_pair(a, b));
	}
	vector<ll>tree((n + 1) * 4);
	function<void(ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll node, ll idx, ll delta)
		{
			if (start > idx || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] += delta;
				return;
			}
			ll mid = (start + end) >> 1;
			update(start, mid, node * 2, idx, delta);
			update(mid + 1, end, node * 2 + 1, idx, delta);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<ll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll node, ll left, ll right)
		{
			if (left > end || right < start)
			{
				return 0LL;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			ll mid = (start + end) >> 1;
			return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
		};
	vector<ll>sum(n + 1), parent(n + 1), depth(n + 1), chain(n + 1), head(n + 1);
	function<ll(ll, ll, ll)> dfs = [&](ll par, ll node, ll d)
		{
			parent[node] = par;
			depth[node] = d;
			ll cnt = 1;
			for (auto& i : graph[node])
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
	for (ll i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const ll& a, const ll& b)
			{
				return sum[a] > sum[b];
			});
	}
	ll ver = 1;
	function<void(ll, ll)> hld = [&](ll par, ll node)
		{
			chain[node] = ver++;
			update(1, n, 1, chain[node], 1);
			bool flag = true;
			for (auto& i : graph[node])
			{
				if (par == i)
				{
					continue;
				}
				if (flag)
				{
					head[i] = head[node];
					flag = false;
				}
				else
				{
					head[i] = i;
				}
				hld(node, i);

			}
		};
	head[1] = 1;
	hld(0, 1);
	ll ans = n, q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			ll c = 0;
			cin >> c;
			update(1, n, 1, chain[b], c);
			ans += c;
		}
		else
		{
			auto& [aa, bb] = ok[b];
			ll pivot = bb;
			if (parent[aa] == bb)
			{
				pivot = aa;
			}
			ll res = query(1, n, 1, chain[pivot], chain[pivot] + sum[pivot] - 1);
			cout << llabs(ans - 2 * res) << '\n';
		}
	}
	return 0;
}
