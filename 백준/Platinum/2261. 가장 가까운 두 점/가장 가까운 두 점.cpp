#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end());
	function<ll(ll, ll)> dfs = [&](ll left, ll right)
		{
			if (right - left == 1)
			{
				return (ll)INT_MAX;
			}
			ll mid = (left + right) >> 1;
			ll mx = v[mid].first;
			ll res = min(dfs(left, mid), dfs(mid, right));
			sort(v.begin() + left, v.begin() + right, [&](const pll& a, const pll& b)
				{
					return a.second < b.second;
				});
			vector<pll>temp;
			for (ll i = left; i < right; ++i)
			{
				auto [x, y] = v[i];
				if ((x - mx) * (x - mx) < res)
				{
					for (ll j = (ll)temp.size() - 1; j >= 0; --j)
					{
						ll xx = temp[j].first - x;
						ll yy = temp[j].second - y;
						if (yy * yy >= res)
						{
							break;
						}
						res = min(res, xx * xx + yy * yy);
					}
					temp.push_back(v[i]);
				}
			}
			return res;
		};
	cout << dfs(0, n);
	return 0;
}