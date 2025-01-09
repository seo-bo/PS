
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, sx = 0, sy = 0;
	cin >> n >> m >> sx >> sy;
	vector<ti>v(n);
	ll idx = 0;
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b;
		c = idx++;
	}
	vector<ti>x = v, y = v;
	sort(x.begin(), x.end(), [&](const ti& a, const ti& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<1>(a) < get<1>(b);
			}
			return get<0>(a) < get<0>(b);
		});
	sort(y.begin(), y.end(), [&](const ti& a, const ti& b)
		{
			if (get<1>(a) == get<1>(b))
			{
				return get<0>(a) < get<0>(b);
			}
			return get<1>(a) < get<1>(b);
		});
	vector<bool> visited(n, false);
	for (ll i = 0; i < m; ++i)
	{
		char d;
		ll df = 0, nx = sx, ny = sy;
		cin >> d >> df;
		if (d == 'U')
		{
			ny += df;
		}
		else if (d == 'D')
		{
			ny -= df;
		}
		else if (d == 'L')
		{
			nx -= df;
		}
		else
		{
			nx += df;
		}
		if (nx == sx)
		{
			ll pre = min(ny, sy);
			ll nxt = max(ny, sy);
			ti aa = make_tuple(nx, pre, -1);
			ti bb = make_tuple(nx, nxt, LLONG_MAX);
			auto low = lower_bound(x.begin(), x.end(), aa, [&](const ti& a, const ti& b)
				{
					if (get<0>(a) == get<0>(b))
					{
						return get<1>(a) < get<1>(b);
					}
					return get<0>(a) < get<0>(b);
				});
			auto high = upper_bound(x.begin(), x.end(), bb, [&](const ti& a, const ti& b)
				{
					if (get<0>(a) == get<0>(b))
					{
						return get<1>(a) < get<1>(b);
					}
					return get<0>(a) < get<0>(b);
				});
			for (auto it = low; it != high; ++it)
			{
				auto [_, __, id] = *it;
				visited[id] = true;
			}
		}
		else
		{
			ll pre = min(nx, sx);
			ll nxt = max(nx, sx);
			ti aa = make_tuple(pre, ny, -1);
			ti bb = make_tuple(nxt, ny, LLONG_MAX);
			auto low = lower_bound(y.begin(), y.end(), aa, [&](const ti& a, const ti& b)
				{
					if (get<1>(a) == get<1>(b))
					{
						return get<0>(a) < get<0>(b);
					}
					return get<1>(a) < get<1>(b);
				});
			auto high = upper_bound(y.begin(), y.end(), bb, [&](const ti& a, const ti& b)
				{
					if (get<1>(a) == get<1>(b))
					{
						return get<0>(a) < get<0>(b);
					}
					return get<1>(a) < get<1>(b);
				});
			for (auto it = low; it != high; ++it)
			{
				auto [_, __, id] = *it;
				visited[id] = true;
			}
		}
		sx = nx;
		sy = ny;
	}
	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		if (visited[i])
		{
			ans++;
		}
	}
	cout << sx << ' ' << sy << ' ' << ans;
	return 0;
}
