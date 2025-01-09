#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, m = 0, sum = 0, ans = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	if (sum <= m)
	{
		cout << "infinite";
		return 0;
	}
	ll left = 1, right = LLONG_MAX >> 1LL;
	while (left <= right)
	{
		ll mid = (left + right) / 2, s = 0;
		for (auto& i : v)
		{
			s += min(mid, i);
			if (s > m)
			{
				break;
			}
		}
		if (s <= m)
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
