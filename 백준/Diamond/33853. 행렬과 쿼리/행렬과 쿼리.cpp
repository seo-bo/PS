#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
 
struct Matrix
{
	ll ary[3][3];
	int r, c;
};
 
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	Matrix base;
	vector<Matrix>v(n + 1);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			base.ary[i][j] = 1;
			base.c = base.r = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		v[i].r = v[i].c = 3;
		memset(v[i].ary, 0, sizeof(v[i].ary));
	}
	vector<Matrix>tree((n + 2) * 4);
	auto sv = [&](Matrix a, Matrix b)
		{
			Matrix res;
			if (!a.c)
			{
				return b;
			}
			if (!b.c)
			{
				return a;
			}
			memset(res.ary, 0, sizeof(res.ary));
			res.r = res.c = 3;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					ll temp = 0;
					for (int k = 0; k < 3; ++k)
					{
						temp = (temp + a.ary[i][k] * b.ary[k][j] + MOD) % MOD;
					}
					res.ary[i][j] = temp;
				}
			}
			return res;
		};
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				tree[node] = v[start];
				return;
			}
			int mid = (start + end) >> 1;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = sv(tree[node * 2], tree[node * 2 + 1]);
		};
	function<void(int, int, int, int, int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int i, int j, int delta, int ok, int cnt)
		{
			if (idx < start || end < idx)
			{
				return;
			}
			if (start == end)
			{
				if (i >= 0)
				{
					tree[node].ary[i][j] = delta;
				}
				if (cnt == -1)
				{
					if (ok == 1)
					{
						for (int i = 0; i < 3; ++i)
						{
							tree[node].ary[i][2] = 0;
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							tree[node].ary[2][i] = 0;
						}
					}
				}
				return;
			}
			int mid = (start + end) >> 1;
			update(start, mid, node * 2, idx, i, j, delta, ok, cnt);
			update(mid + 1, end, node * 2 + 1, idx, i, j, delta, ok, cnt);
			tree[node] = sv(tree[node * 2], tree[node * 2 + 1]);
		};
	function<Matrix(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (right < start || end < left)
			{
				return base;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) >> 1;
			Matrix L = query(start, mid, node * 2, left, right);
			Matrix R = query(mid + 1, end, node * 2 + 1, left, right);
			return sv(L, R);
		};
	init(1, n, 1);
	for (int i = 1; i <= n; ++i)
	{
		v[i].r = v[i].c = 2;
	}
	int q = 0;
	cin >> q;
	set<int>visited;
	auto check = [&](int idx)
		{
			auto tt = [&](Matrix& a, Matrix& b)
				{
					if (a.c != b.r)
					{
						return false;
					}
					return true;
				};
			vector<int>d = { idx - 1,idx };
			for (auto& i : d)
			{
				if (!(i >= 1 && i <= n))
				{
					continue;
				}
				if (tt(v[i], v[i + 1]))
				{
					visited.erase(i);
				}
				else
				{
					visited.insert(i);
				}
			}
		};
	while (q--)
	{
		int ty = 0;
		cin >> ty;
		if (ty == 1)
		{
			int l = 0, r = 0, i = 0, j = 0;
			cin >> l >> r >> i >> j;
			auto it = visited.lower_bound(l);
			if (it != visited.end() && *it < r)
			{
				cout << -1 << '\n';
				continue;
			}
			cout << query(1, n, 1, l, r).ary[i - 1][j - 1] << '\n';
		}
		else if (ty == 6) // 값추가
		{
			int idx = 0, j = 0, k = 0, delta = 0;
			cin >> idx >> j >> k >> delta;
			update(1, n, 1, idx, j - 1, k - 1, delta, 0, 0);
		}
		else if (ty == 2) // 행추가
		{
			int idx = 0;
			cin >> idx;
			v[idx].r++;
			check(idx);
		}
		else if (ty == 3) // 행삭제
		{
			int idx = 0;
			cin >> idx;
			v[idx].r--;
			update(1, n, 1, idx, -1, -1, 0, 2, -1);
			check(idx);
		}
		else if (ty == 4) // 열추가
		{
			int idx = 0;
			cin >> idx;
			v[idx].c++;
			check(idx);
		}
		else // 열삭제
		{
			int idx = 0;
			cin >> idx;
			v[idx].c--;
			update(1, n, 1, idx, -1, -1, 0, 1, -1);
			check(idx);
		}
	}
	return 0;
}