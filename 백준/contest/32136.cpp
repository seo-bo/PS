#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = 1e12, ans = right;
	auto h = [&](ll t)
		{
			ll left = LLONG_MIN;
			ll right = LLONG_MAX;
			for (int i = 0; i < n; ++i)
			{
				ll lb = i - t / v[i];
				ll rb = i + t / v[i];
				left = max(left, lb);
				right = min(right, rb);
				if (left > right)
				{
					return false;
				}
			}
			return true;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		bool check = false;
		if (h(mid))
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
