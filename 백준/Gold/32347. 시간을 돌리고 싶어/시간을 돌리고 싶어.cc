#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			v.push_back(i);
		}
	}
	auto check = [&](ll t)
		{
			ll now = n;
			int tempk = k;
			while (tempk--)
			{
				if (now - t <= 1)
				{
					return true;
				}
				auto it = lower_bound(v.begin(), v.end(), now - t);
				if (it == v.end() || *it >= now)
				{
					return false;
				}
				now = *it;
			}
			return now <= 1;
		};
	ll left = 1, right = n, ans = n;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (check(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}