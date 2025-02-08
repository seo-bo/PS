#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll Q = 0;
	cin >> Q;
	vector<ll>depth(Q + 3, 0), dist(Q + 3, 0);
	vector<vector<ll>>up(Q + 3, vector<ll>(20, 0));
	function<ll(ll, ll)> dfs = [&](ll a, ll b)
		{
			if (depth[a] > depth[b])
			{
				swap(a, b);
			}
			ll diff = depth[b] - depth[a];
			for (ll i = 0; i < 20; ++i)
			{
				if (diff & (1LL << i))
				{
					b = up[b][i];
				}
			}
			if (a == b)
			{
				return a;
			}
			for (ll i = 19; i >= 0; --i)
			{
				if (up[a][i] != up[b][i])
				{
					a = up[a][i];
					b = up[b][i];
				}
			}
			return up[a][0];
		};
	for (ll i = 0; i < 20; ++i)
	{
		up[1][i] = 1;
	}
	auto cal = [&](ll a, ll b)
		{
			return dist[a] + dist[b] - 2LL * dist[dfs(a, b)];
		};
	ll a = 1, b = 1, ans = 0, node = 2;
	while (Q--)
	{
		ll q = 0, w = 0;
		cin >> q >> w;
		up[node][0] = q;
		depth[node] = depth[q] + 1;
		dist[node] = dist[q] + w;
		for (ll i = 1; i < 20; ++i)
		{
			up[node][i] = up[up[node][i - 1]][i - 1];
		}
		ll p1 = cal(a, node), p2 = cal(b, node);
		ll oa = a, ob = b;
		if (p1 > ans)
		{
			ans = p1;
			a = oa;
			b = node;
		}
		if (p2 > ans)
		{
			ans = p2;
			a = ob;
			b = node;
		}
		cout << ans << '\n';
		node++;
	}
	return 0;
}