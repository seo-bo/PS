#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, d = 0, k = 0;
		cin >> n >> d >> k;
		ll end = n - d + 1;
		vector<pll>v(k);
		vector<ll>diff(end + 2, 0);
		for (auto& [i, j] : v)
		{
			cin >> i >> j;
			ll mini = max(1LL, i - d + 1LL);
			ll maxi = min(j, end);
			if (mini > maxi)
			{
				continue;
			}
			diff[mini]++;
			diff[maxi + 1]--;
		}
		ll ans1 = 1, ans2 = 1;
		ll ma = LLONG_MIN, mi = LLONG_MAX, now = 0;
		for (int i = 1; i <= end; ++i)
		{
			now += diff[i];
			if (now > ma)
			{
				ma = now;
				ans1 = i;
			}
			if (now < mi)
			{
				mi = now;
				ans2 = i;
			}
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}
