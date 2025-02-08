#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 0, b = 0, c = 0, d = 0;
	cin >> n >> a >> b >> c >> d;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	vector<ll>x(n), y(n), prex(1, 0), prey(1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n; ++i)
	{
		prex.push_back(prex.back() + x[i]);
		prey.push_back(prey.back() + y[i]);
	}
	auto cal = [&](vector<ll>v, vector<ll>pre, ll p, ll A, ll B)
		{
			auto it = lower_bound(v.begin(), v.end(), p) - v.begin();
			ll lc = it, ls = pre[it];
			ll rc = n - it, rs = pre[n] - ls;
			ll sum = B * (p * lc - ls);
			sum += A * (rs - p * rc);
			return sum;
		};
	ll ans1 = 0, ans2 = 0;
	if (a + b)
	{
		ll pivot = max(0LL, (n * a) / (a + b));
		pivot = min(pivot, n - 1);
		vector<ll>temp = { x[pivot] };
		if (pivot + 1 < n)
		{
			temp.push_back(x[pivot + 1]);
		}
		ll res = LLONG_MAX;
		for (auto& i : temp)
		{
			res = min(res, cal(x, prex, i, a, b));
		}
		ans1 = res;
	}
	if (c + d)
	{
		ll pivot = max(0LL, (n * c) / (c + d));
		pivot = min(pivot, n - 1);
		vector<ll>temp = { y[pivot] };
		if (pivot + 1 < n)
		{
			temp.push_back(y[pivot + 1]);
		}
		ll res = LLONG_MAX;
		for (auto& i : temp)
		{
			res = min(res, cal(y, prey, i, c, d));
		}
		ans2 = res;
	}
	cout << ans1 + ans2;
	return 0;
}