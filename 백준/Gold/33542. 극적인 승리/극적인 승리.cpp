#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll A = 0, B = 0;
	cin >> A >> B;
	if (B > A)
	{
		cout << "-1 -1";
		return 0;
	}
	ll diff = A - B;
	int n = 0;
	cin >> n;
	vector<pll>l(n), r(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i].first >> r[i].first;
		l[i].second = r[i].second = i + 1;
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	vector<ll>cost(2, INT_MAX);
	vector<ll>ans(2, INT_MAX);
	auto sv = [&](vector<pll>& base, vector<pll>& per, bool check)
		{
			for (auto [a, b] : base)
			{
				if (a > diff)
				{
					if (cost[0] + cost[1] > a)
					{
						cost[0] = a, cost[1] = 0, ans[0] = b, ans[1] = -1;
						if (check)
						{
							swap(cost[0], cost[1]);
							swap(ans[0], ans[1]);
						}
					}
					continue;
				}
				auto it = lower_bound(per.begin(), per.end(), make_pair(diff - a + 1, INT_MIN), [&]
				(const pll& pa, const pll& pb)
					{
						return pa.first < pb.first;
					});
				if (it == per.end())
				{
					continue;
				}
				if (it->second == b)
				{
					if (next(it) == per.end())
					{
						continue;
					}
					++it;
					if (cost[0] + cost[1] > it->first + a)
					{
						cost[0] = a, cost[1] = it->first, ans[0] = b, ans[1] = it->second;
						if (check)
						{
							swap(cost[0], cost[1]);
							swap(ans[0], ans[1]);
						}
					}
				}
				else
				{
					if (cost[0] + cost[1] > it->first + a)
					{
						cost[0] = a, cost[1] = it->first, ans[0] = b, ans[1] = it->second;
						if (check)
						{
							swap(cost[0], cost[1]);
							swap(ans[0], ans[1]);
						}
					}
				}
			}
		};
	sv(l, r, false);
	sv(r, l, true);
	if (cost[0] == INT_MAX)
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < 2; ++i)
	{
		cout << ((ans[i] == 0) ? -1 : ans[i]) << ' ';
	}
	return 0;
}