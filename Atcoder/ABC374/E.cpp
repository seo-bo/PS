#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	vector<tl>v(n);
	for (auto& [a, b, c, d] : v)
	{
		cin >> a >> b >> c >> d;
	}
	auto cal = [&](tl A, ll mid)->ll
		{
			auto [a, b, c, d] = A;
			if (!a && !c)
			{
				return (mid > 0) ? LLONG_MAX : 0LL;
			}
			if (!a)
			{
				ll t = (mid + c - 1) / c;
				return (t >= 0) ? (d * t) : LLONG_MAX;
			}
			if (!c)
			{
				ll t = (mid + a - 1) / a;
				return (t >= 0) ? (b * t) : LLONG_MAX;
			}
			ll ans = LLONG_MAX;
			ll pivot = mid / a;
			for (int i = -100; i <= 100; ++i)
			{
				ll p = pivot + i;
				if (p < 0)
				{
					continue;
				}
				ll nokori = mid - a * p;
				ll tt = (nokori > 0) ? ((nokori + c - 1) / c) : 0LL;
				ll res = b * p + d * tt;
				ans = min(ans, res);
			}
			pivot = mid / c;
			for (int i = -100; i <= 100; ++i)
			{
				ll p = pivot + i;
				if (p < 0)
				{
					continue;
				}
				ll nokori = mid - c * p; 
				ll tt = (nokori > 0) ? ((nokori + a - 1) / a) : 0LL;
				ll res = d * p + b * tt;
				ans = min(ans, res);
			}
			return ans;
		};
	ll left = 0, right = INT_MAX;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll sum = 0;
		bool check = true;
		for (int i = 0; i < n; ++i)
		{
			ll temp = cal(v[i], mid);
			if (temp == LLONG_MAX)
			{
				check = false;
				break;
			}
			sum += temp;
			if (sum > x)
			{
				check = false;
				break;
			}
		}
		if (check && sum <= x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << right;
	return 0;
}
