#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, g = 0, k = 0;
	cin >> n >> g >> k;
	vector<pll>A, B;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (c == 1)
		{
			B.push_back(make_pair(a, b));
		}
		else
		{
			A.push_back(make_pair(a, b));
		}
	}
	ll left = 0, right = INT_MAX, ans = 0;
	auto sv = [&](ll mid)
		{
			ll pivot = 0;
			priority_queue<ll>pq;
			for (auto& [a, b] : A)
			{
				pivot += a * max(1LL, mid - b);
				if (pivot > g)
				{
					return false;
				}
			}
			for (auto& [a, b] : B)
			{
				pq.push(a * max(1LL, mid - b));
			}
			for (int i = 0; i < k && !pq.empty(); ++i)
			{
				pq.pop();
			}
			while (!pq.empty())
			{
				pivot += pq.top();
				pq.pop();
				if (pivot > g)
				{
					return false;
				}
			}
			return pivot <= g;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (sv(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}