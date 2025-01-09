#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0, res = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		int sum = max(0,v[i].first - v[i].second);
		for (int j = i + 1; j < n; ++j)
		{
			sum += max(0, v[i].first - v[j].second);
		}
		if (sum > ans)
		{
			res = v[i].first;
			ans = sum;
		}
	}
	cout << res;
	return 0;
}