#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) // 세그? pq? 맵? 뭐지?
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<priority_queue<pll>>x(n + 1);
	vector<priority_queue<pll>>y(m + 1);
	vector<ll>xx(n + 1, 0), yy(m + 1, 0);
	map<ll, ll>now;
	auto sv = [&](ll a, ll b)
		{
			return a * m + b;
		};
	ll A = 0, B = 0, C = 0;
	while (q--)
	{
		string str;
		cin >> str;
		if (str == "STACK")
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			ll pos = sv(a, b), cost = ++now[pos];
			if (cost == 1) // 새로 들어온놈
			{
				C++;
			}
			x[a].push(make_pair(cost, b));
			y[b].push(make_pair(cost, a));
			if (cost > yy[b])
			{
				A += cost - yy[b];
				yy[b] = cost;
			}
			if (cost > xx[a])
			{
				B += cost - xx[a];
				xx[a] = cost;
			}
		}
		else if (str == "REMOVE")
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			ll pos = sv(a, b);
			if (now[pos] == 0)
			{
				continue;
			}
			ll cost = --now[pos];
			if (!cost)
			{
				C--;
			}
			x[a].push(make_pair(cost, b));
			y[b].push(make_pair(cost, a));
			if (cost + 1 == yy[b])
			{
				while (!y[b].empty())
				{
					auto [pa, pb] = y[b].top();
					ll pos = sv(pb, b);
					if (now[pos] == pa)
					{
						break;
					}
					y[b].pop();
				}
				ll ok = 0;
				if (!y[b].empty())
				{
					ok = y[b].top().first;
				}
				A += ok - yy[b];
				yy[b] = ok;
			}
			if (cost + 1 == xx[a])
			{
				while (!x[a].empty())
				{
					auto [pa, pb] = x[a].top();
					ll pos = sv(a, pb);
					if (now[pos] == pa)
					{
						break;
					}
					x[a].pop();
				}
				ll ok = 0;
				if (!x[a].empty())
				{
					ok = x[a].top().first;
				}
				B += ok - xx[a];
				xx[a] = ok;
			}
		}
		else if (str == "FRONT")
		{
			cout << B << '\n';
		}
		else if (str == "SIDE")
		{
			cout << A << '\n';
		}
		else
		{
			cout << C << '\n';
		}
	}
	return 0;
}