#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0, pivot = 0;
	cin >> n;
	ll len = n;
	for (int i = 1; i <= n; ++i)
	{
		ld mid = (ld)i + 0.5;
		for (; len >= 1; len--)
		{
			ld temp = (ld)len + 0.5;
			if (mid * mid + temp * temp <= n * n)
			{
				break;
			}
		}
		pivot += max(len, 0LL);
	}
	ll p = max(0LL, (ll)(sqrt((ld)n * (ld)n - (ld)0.25) - (ld)0.5));
	cout << 4 * (p + pivot) + 1;
	return 0;
}
