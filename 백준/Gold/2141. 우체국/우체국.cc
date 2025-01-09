#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n + 1);
	ll total = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
		total += v[i].second;
	}
	sort(v.begin() + 1, v.end());
	ll prefix = 0, pivot = (total + 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		prefix = prefix + v[i].second;
		if (prefix >= pivot)
		{
			cout << v[i].first;
			return 0;
		}
	}
	return 0;
}