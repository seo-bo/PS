#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> ti;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, c = 0, k = 0;
	cin >> x >> c >> k;
	vector<ti>v(k);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	sort(v.begin(), v.end());
	vector<ll>se(x + 1, 0), ow(c + 1, 0);
	for (auto& [a, b, c] : v)
	{
		if (ow[b])
		{
			if (ow[b] != c)
			{
				continue;
			}
		}
		if (se[c])
		{
			ow[se[c]] = 0;
		}
		se[c] = b;
		ow[b] = c;
	}
	vector<pii>ans;
	for (ll i = 1; i <= x; ++i)
	{
		if (se[i])
		{
			ans.push_back(make_pair(i, se[i]));
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}