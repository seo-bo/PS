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
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while (q--)
	{
		ll b = 0, k = 0;
		cin >> b >> k;
		vector<ll>dis;
		ll left = 0, right = 1e10;
		auto ca = [&](ll mid)
			{
				return lower_bound(v.begin(), v.end(), b + mid + 1) - lower_bound(v.begin(), v.end(), b - mid);
			};
		while (left < right)
		{
			ll mid = (left + right) / 2;
			if (ca(mid) >= k)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << left << '\n';
	}
	return 0;
}
