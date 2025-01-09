#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tl;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<tl>v(m);
	vector<ll>parent(n + 2, 0), rank(n + 2, 0), cnta(n + 2, 0), cntb(n + 2, 0);
	iota(parent.begin(), parent.end(), 0);
	for (auto& [a, b, c] : v)
	{
		cin >> b >> c >> a;
	}
	vector<ll>A(k), B(k);
	for (auto& i : A)
	{
		cin >> i;
		cnta[i]++;
	}
	for (auto& i : B)
	{
		cin >> i;
		cntb[i]++;
	}
	sort(v.begin(), v.end());
	function<ll(ll)> find = [&](ll root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	ll ans = 0;
	auto merge = [&](ll root1, ll root2, ll w)
		{
			ll r1 = find(root1);
			ll r2 = find(root2);
			ll a = min(cnta[r1], cntb[r2]);
			ll b = min(cntb[r1], cnta[r2]);
			ans += (a + b) * w;
			if (rank[r1] < rank[r2])
			{
				parent[r1] = r2;
				ll aa = cnta[r1] - a + cnta[r2] - b;
				ll bb = cntb[r1] - b + cntb[r2] - a;
				cnta[r2] = aa;
				cntb[r2] = bb;
			}
			else
			{
				parent[r2] = r1;
				ll aa = cnta[r1] - a + cnta[r2] - b;
				ll bb = cntb[r1] - b + cntb[r2] - a;
				cnta[r1] = aa;
				cntb[r1] = bb;
				if (rank[r1] == rank[r2])
				{
					rank[r1]++;
				}
			}
		};
	for (auto& [w, a, b] : v)
	{
		ll r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b, w);
		}
	}
	cout << ans;
	return 0;
}
