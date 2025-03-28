#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll dp[5002][5002][2];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v = { {LLONG_MIN,LLONG_MIN},{0LL,0LL},{LLONG_MAX,LLONG_MAX} };
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	n++;
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			return a.first < b.first;
		});
	int idx = lower_bound(v.begin(), v.end(), make_pair(0LL, 0LL)) - v.begin();
	ll ans = m;
	// 0은 왼쪽, 1는 오른쪽
	if (idx + 1 <= n && m - llabs(v[idx + 1].first - v[idx].first) > 0)
	{
		ll pp = m - llabs(v[idx + 1].first - v[idx].first) + v[idx + 1].second;
		dp[idx][idx + 1][1] = make_pair(m + v[idx + 1].second, pp);
		ans = max(ans, m + v[idx + 1].second);
	}
	if (idx - 1 >= 1 && m - llabs(v[idx - 1].first - v[idx].first) > 0)
	{
		ll pp = m - llabs(v[idx - 1].first - v[idx].first) + v[idx - 1].second;
		dp[idx - 1][idx][0] = make_pair(m + v[idx - 1].second, pp);
		ans = max(ans, m + v[idx - 1].second);
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			int l = j, r = i - l;
			int left = idx - j, right = idx + r;
			if (left < 1 || right > n)
			{
				continue;
			}
			if (left + 1 <= idx)
			{
				auto& A = dp[left + 1][right][0];
				auto& B = dp[left + 1][right][1];
				ll a = A.second - llabs(v[left + 1].first - v[left].first);
				ll b = B.second - llabs(v[right].first - v[left].first);
				if (a > 0) // left로 가려고함, 현재 왼쪽.
				{
					a += v[left].second;
					ll temp = A.first + v[left].second;
					ans = max(ans, temp);
					if (dp[left][right][0].second < a)
					{
						dp[left][right][0] = make_pair(temp, a);
					}
					else if (dp[left][right][0].second == a)
					{
						dp[left][right][0].first = max(dp[left][right][0].first, temp);
					}
				}
				if (b > 0) // left로 가려고함
				{
					b += v[left].second;
					ll temp = B.first + v[left].second;
					ans = max(ans, temp);
					if (dp[left][right][0].second < b)
					{
						dp[left][right][0] = make_pair(temp, b);
					}
					else if (dp[left][right][0].second == b)
					{
						dp[left][right][0].first = max(dp[left][right][0].first, temp);
					}
				}
			}
			if (right - 1 >= idx)
			{
				auto& A = dp[left][right - 1][0];
				auto& B = dp[left][right - 1][1];
				ll a = A.second - llabs(v[right].first - v[left].first);
				ll b = B.second - llabs(v[right].first - v[right - 1].first);
				if (a > 0) // right로 가려고함
				{
					a += v[right].second;
					ll temp = A.first + v[right].second;
					ans = max(ans, temp);
					if (dp[left][right][1].second < a)
					{
						dp[left][right][1] = make_pair(temp, a);
					}
					else if (dp[left][right][1].second == a)
					{
						dp[left][right][1].first = max(dp[left][right][1].first, temp);
					}
				}
				if (b > 0) // right로 가려고함
				{
					b += v[right].second;
					ll temp = B.first + v[right].second;
					ans = max(ans, temp);
					if (dp[left][right][1].second < b)
					{
						dp[left][right][1] = make_pair(temp, b);
					}
					else if (dp[left][right][1].second == b)
					{
						dp[left][right][1].first = max(dp[left][right][1].first, temp);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}