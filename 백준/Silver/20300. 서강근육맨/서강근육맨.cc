#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	if (n % 2)
	{
		ans = v.back();
		n--;
	}
	for (int i = 0; i < n / 2; ++i)
	{
		ans = max(ans, v[i] + v[n - 1 - i]);
	}
	cout << ans;
	return 0;
}