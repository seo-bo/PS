#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0, q = 0, pivot = 0;
		cin >> n >> m >> q;
		vector<ll>a(n), b(m), temp(n + 1, 0);
		vector<pll>v(q);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			temp[a[i]] = i;
		}
		for (auto& i : b)
		{
			cin >> i;
		}
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		vector<set<ll>>ad(n + 1);
		for (int i = 0; i < m; ++i)
		{
			ad[b[i]].insert(i + 1);
		}
		vector<ll>f(n + 1, m + 1), s(n, 0);
		auto cal = [&](ll k, ll num)
			{
				if (k > 0)
				{
					if (s[k - 1] > s[k])
					{
						pivot--;
					}
				}
				if (k < n - 1)
				{
					if (s[k] > s[k + 1])
					{
						pivot--;
					}
				}
				s[k] = num;
				if (k > 0)
				{
					if (s[k - 1] > s[k])
					{
						pivot++;
					}
				}
				if (k < n - 1)
				{
					if (s[k] > s[k + 1])
					{
						pivot++;
					}
				}
			};
		for (int i = 1; i <= n; ++i)
		{
			if (!ad[i].empty())
			{
				f[i] = *(ad[i].begin());
			}			
		}
		for (int i = 0; i < n; ++i)
		{
			s[i] = f[a[i]];
		}
		for (int i = 0; i < n - 1; ++i)
		{
			if (s[i] > s[i + 1])
			{
				pivot++;
			}
		}
		if (!pivot)
		{
			cout << "YA" << '\n';
		}
		else
		{
			cout << "TIDAK" << '\n';
		}
		for (int i = 0; i < q; ++i)
		{
			auto [aa, bb] = v[i];
			ll old = b[aa - 1], now = bb;
			if (old != now)
			{
				ad[old].erase(aa);
				if (f[old] == aa)
				{
					if (!ad[old].empty())
					{
						ll fst = *(ad[old].begin());
						f[old] = fst;
						ll od = temp[old];
						cal(od, fst);
					}
					else
					{
						f[old] = m + 1;
						ll od = temp[old];
						cal(od, m + 1);
					}
				}
				ad[now].insert(aa);
				if (aa < f[now])
				{
					f[now] = aa;
					ll mr = temp[now];
					cal(mr, aa);
				}
				b[aa - 1] = now;
			}
			if (!pivot)
			{
				cout << "YA" << '\n';
			}
			else
			{
				cout << "TIDAK" << '\n';
			}
		}
	}
	return 0;
}
