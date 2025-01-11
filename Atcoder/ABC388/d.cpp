#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	vector<ll>diff(5000000, 0);
	ll cur = 0;
	for (int i = 1; i <= n; ++i)
	{
		cur += diff[i];
		b[i] = cur;
		ll pivot = min(a[i] + b[i], n - i);
		if (pivot > 0)
		{
			ll left = i + 1, right = i + pivot;
			diff[left]++;
			diff[right + 1]--;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << max(0LL, a[i] + b[i] - n + i) << ' ';
	}
	return 0;
}
