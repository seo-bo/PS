#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ll pivot = v[i] + v[j];
			ll st = lower_bound(v.begin() + j + 1, v.end(), -pivot) - v.begin();
			ll ed = upper_bound(v.begin() + j + 1, v.end(), -pivot) - v.begin();
			ans += max(0LL, ed - st);
		}
	}
	cout << ans;
	return 0;
}