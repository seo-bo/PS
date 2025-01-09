#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, ans = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	ll cur = 0, cnt = 0;
	for (int i = 0; i < n && cnt < k; ++i)
	{
		ll p = (k - i);
		ans = max(ans, cur + p * v[i]);
		cur += v[i];
		cnt++;
	}
	cur = 0, cnt = 0;
	for (int i = n - 1; i >= 0 && cnt < k; --i)
	{
		ll c = (n - 1 - i);
		ll p = (k - c);
		ans = max(ans, cur + p * v[i]);
		cur += v[i];
		cnt++;
	}
	cout << ans;
	return 0;
}