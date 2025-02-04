#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n >> q;
	vector<ll>row(n + 1, 0), rowt(n + 1, 0), col(n + 1, 0), colt(n + 1, 0);
	auto add = [&](vector<ll>& tree, ll idx, ll delta)
		{
			while (idx <= q)
			{
				tree[idx] += delta;
				idx += idx & -idx;
			}
		};
	auto query = [&](vector<ll>& tree, ll idx)
		{
			ll res = 0;
			while (idx > 0)
			{
				res += tree[idx];
				idx -= idx & -idx;
			}
			return res;
		};
	vector<ll>srow(q + 1, 0), scol(q + 1, 0), frow(q + 1, 0), fcol(q + 1, 0);
	for (int i = 1; i <= q; ++i)
	{
		ll _ = 0, a = 0, b = 0;
		cin >> _;
		switch (_)
		{
			case 1:
			{
				cin >> a >> b;
				if (rowt[a])
				{
					add(srow, rowt[a], -row[a]);
					add(frow, rowt[a], -1);
				}
				rowt[a] = i;
				row[a] = b;
				add(srow, i, b);
				add(frow, i, 1);
				break;
			}
			case 2:
			{
				cin >> a >> b;
				if (colt[a])
				{
					add(scol, colt[a], -col[a]);
					add(fcol, colt[a], -1);
				}
				colt[a] = i;
				col[a] = b;
				add(scol, i, b);
				add(fcol, i, 1);
				break;
			}
			case 3:
			{
				cin >> a;
				ll s1 = query(fcol, i) - query(fcol, rowt[a]);
				ll s2 = query(scol, i) - query(scol, rowt[a]);
				cout << row[a] * (n - s1) + s2 << '\n';
				break;
			}
			case 4:
			{
				cin >> a;
				ll s1 = query(frow, i) - query(frow, colt[a]);
				ll s2 = query(srow, i) - query(srow, colt[a]);
				cout << col[a] * (n - s1) + s2 << '\n';
				break;
			}
		}
	}
	return 0;
}