#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ll>suffix(n + 2);
	suffix[n] = v[n];
	for (int i = n - 1; i >= 1; --i)
	{
		suffix[i] = max(v[i], suffix[i + 1]);
	}
	ll ans = LLONG_MIN;
	for (int i = 0; i <= m; ++i)
	{
		int left = i + 1, right = n - m + i;
		ans = max(ans, suffix[right] - v[left]);
	}
	cout << ans;
	return 0;
}