#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, k = 0;
	cin >> x >> k;
	ll pivot = x;
	vector<ll>left(k + 1, 0), right(k + 1, 0);
	for (int i = 0; i < x; ++i)
	{
		int temp = 0;
		cin >> temp;
		left[temp]++;
	}
	for (int i = 0; i < x; ++i)
	{
		int temp = 0;
		cin >> temp;
		right[temp]++;
	}
	ll ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ll a = left[i];
		ll b = pivot - right[i];
		ans += a * b;
	}
	cout << ans;
	return 0;
}