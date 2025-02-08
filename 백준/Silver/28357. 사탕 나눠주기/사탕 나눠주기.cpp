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
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = 1e15, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2, cnt = 0;
		for (auto& i : v)
		{
			if (i > mid)
			{
				cnt += i - mid;
			}
		}
		if (cnt <= k) // cnt가 k보다 작다 -> mid가 크다
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