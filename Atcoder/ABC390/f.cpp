#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	vector<vector<ll>>pp(n + 1);
	ll siz = n * (n + 1) / 2;
	vector<ll>BIT(n + 1);
	auto update = [&](ll idx, ll delta)
		{
			while (idx <= n)
			{
				BIT[idx] += delta;
				idx += idx & -idx;
			}
		};
	auto query = [&](ll idx)
		{
			ll res = 0;
			while (idx > 0)
			{
				res += BIT[idx];
				idx -= idx & -idx;
			}
			return res;
		};
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		pp[v[i]].push_back(i);
		update(i, i);
	}
	auto cal = [&](ll a, ll b)
		{
			ll alen = pp[a].size(), blen = pp[b].size();
			vector<ll>temp;
			ll idx = 0, jdx = 0;
			while (idx < alen && jdx < blen)
			{
				if (pp[a][idx] <= pp[b][jdx])
				{
					temp.push_back(pp[a][idx++]);
				}
				else if (pp[a][idx] > pp[b][jdx])
				{
					temp.push_back(pp[b][jdx++]);
				}
				else
				{
					temp.push_back(pp[a][idx]);
					idx++;
					jdx++;
				}
			}
			while (idx < alen)
			{
				temp.push_back(pp[a][idx++]);
			}
			while (jdx < blen)
			{
				temp.push_back(pp[b][jdx++]);
			}
			temp.erase(unique(temp.begin(), temp.end()), temp.end());
			return temp;

		};
	auto sv = [&](vector<ll>& temp)
		{
			if (temp.empty())
			{
				return query(n);
			}
			ll pre = 0, sum = 0;
			for (auto& i : temp)
			{
				ll pivot = i - (pre + 1);
				if (pivot > 0)
				{
					sum += query(pivot);
				}
				pre = i;
			}
			ll _ = n - pre;
			if (_ > 0)
			{
				sum += query(_);
			}
			return sum;
		};
	vector<ll>s(n + 1), c(n + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
	{
		ll pivot = sv(pp[i]);
		s[i] = pivot;
		c[i] = siz - pivot;
		ans += c[i];
	}
	for (ll i = 1; i < n; ++i)
	{
		vector<ll>_ = cal(i, i + 1);
		ll pivot = sv(_);
		ans -= c[i] + c[i + 1] - siz + pivot;
	}
	cout << ans;
	return 0;
}
