#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

class LazySegtree
{
private:
	int n;
	vector<ll>tree, lazy;
	void build(vector<ll>& v, int start, int end, int node)
	{
		if (start == end)
		{
			tree[node] = v[start];
			return;
		}
		int mid = (start + end) / 2;
		build(v, start, mid, node * 2);
		build(v, mid + 1, end, node * 2 + 1);
		tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
	}
	void lazy_update(int start, int end, int node)
	{
		if (lazy[node])
		{
			tree[node] = (tree[node] + (end - start + 1) * lazy[node]) % MOD;
			if (start != end)
			{
				lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
				lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
			}
			lazy[node] = 0;
		}
	}
	void update_(int start, int end, int node, int left, int right, ll value)
	{
		lazy_update(start, end, node);
		if (start > right || end < left)
		{
			return;
		}
		if (left <= start && end <= right)
		{
			tree[node] = (tree[node] + (end - start + 1) * value) % MOD;;
			if (start != end)
			{
				lazy[node * 2] = (lazy[node * 2] + value) % MOD;
				lazy[node * 2 + 1] = (lazy[node * 2 + 1] + value) % MOD;
			}
			return;
		}
		int mid = (start + end) / 2;
		update_(start, mid, node * 2, left, right, value);
		update_(mid + 1, end, node * 2 + 1, left, right, value);
		tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
	}
	ll query_(int start, int end, int node, int left, int right)
	{
		lazy_update(start, end, node);
		if (start > right || end < left)
		{
			return 0LL;
		}
		if (left <= start && end <= right)
		{
			return tree[node];
		}
		int mid = (start + end) / 2;
		return (query_(start, mid, node * 2, left, right) + query_(mid + 1, end, node * 2 + 1, left, right)) % MOD;
	}
public:
	LazySegtree(vector<ll>& v)
	{
		n = v.size();
		tree.resize(4 * n + 3, 0);
		lazy.resize(4 * n + 3, 0);
		build(v, 0, n - 1, 1);
	}
	void update(int left, int right, ll value)
	{
		if (left > right)
		{
			swap(left, right);
		}
		update_(0, n - 1, 1, left, right, value);
	}
	ll query(int left, int right)
	{
		if (left > right)
		{
			swap(left, right);
		}
		return query_(0, n - 1, 1, left, right);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, dir = 0, x = 0;
		cin >> n >> m;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		vector<pii>oper(m);
		for (auto& [a, _] : oper)
		{
			cin >> a;
		}
		for (auto& [_, a] : oper)
		{
			cin >> a;
		}
		LazySegtree tree(v);
		vector<ll>ans;
		auto cal = [&](int check, int left, int right, ll value = 0)
			{
				if (check == 4)
				{
					tree.update(left, right, value);
					return 0LL;
				}
				else
				{
					return tree.query(left, right);
				}
			};
		for (int i = 0; i < m; ++i)
		{
			ll c = 0;
			cin >> c;
			auto [a, b] = oper[i];
			if (a == 1)
			{
				if (dir == 1)
				{
					x = (x - b + n) % n;
				}
				else
				{
					x = (x + b) % n;
				}
			}
			else if (a == 2)
			{
				if (dir == 1)
				{
					x = (x + b) % n;
				}
				else
				{
					x = (x - b + n) % n;
				}
			}
			else if (a == 3)
			{
				dir = (dir + 1) % 2;
			}
			else
			{
				ll tot = 0;
				if (dir == 0)
				{
					int ed = x + b - 1;
					if (ed > n - 1)
					{
						tot += cal(a, x, n - 1, c);
						tot += cal(a, 0, (ed + n) % n, c);
					}
					else
					{
						tot += cal(a, x, ed, c);
					}
				}
				else if (dir == 1)
				{
					int ed = x - b + 1;
					if (x - b + 1 < 0)
					{
						tot += cal(a, x, 0, c);
						tot += cal(a, n - 1, (ed + n) % n, c);
					}
					else
					{
						tot += cal(a, x, ed, c);
					}
				}
				if (a == 5)
				{
					ans.push_back(tot);
				}
			}
		}
		for (auto& i : ans)
		{
			cout << i % MOD << ' ';
		}
		cout << '\n';
	}
	return 0;
}