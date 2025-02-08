#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, l = 0;
	cin >> n >> l;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	ll pre = -1, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto [x, y] = v[i];
		if (pre >= y)
		{
			continue;
		}
		if (pre <= x) // 안겹치면?
		{
			ll pivot = (y - x + l - 1) / l; // ceil
			ans += pivot;
			pre = x + pivot * l;
		}
		else // 겹치면
		{
			ll pivot = (y - pre + l - 1) / l;
			ans += pivot;
			pre = pre + pivot * l;
		}
	}
	cout << ans;
	return 0;
}