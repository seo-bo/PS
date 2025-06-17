#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<ll>pre(n + 1);
	pre[1] = v[1];
	for (int i = 2; i <= n; ++i)
	{
		pre[i] = max(pre[i - 1], v[i] - prefix[i - 1]);
	}
	ll ans = 1, now = v[1];
	while (now - prefix[n] < 0)
	{
		auto it = upper_bound(prefix.begin(), prefix.end(), now) - prefix.begin();
		ll diff = prefix[it] - now;
		ll a = (diff + pre[it] - 1) / pre[it];
		now += a * pre[it];
		ans += a;
	}
	cout << ans;
	return 0;
}