#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, ans = 0, cost = INT_MAX;
	cin >> n >> m;
	vector<int>v(m);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		int idx = v.end() - lower_bound(v.begin(), v.end(), i);
		int sum = ((idx >= n) ? n : idx) * i;
		if (sum > ans || (sum == ans && i < cost))
		{
			ans = sum;
			cost = i;
		}
	}
	cout << cost << ' ' << ans;
	return 0;
}