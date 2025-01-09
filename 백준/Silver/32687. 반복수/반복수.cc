#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, k = 0, m = 0;
	cin >> a >> b >> k >> m;
	int ans = 0;
	ll start = pow(10, k - 1), end = pow(10, k);
	for (ll i = start; i < end; ++i)
	{
		string pivot = to_string(i);
		ll temp = i;
		int idx = 0;
		while (temp <= b)
		{
			if (temp >= a && temp <= b && !(temp % m))
			{
				ans++;
			}
			temp = temp * 10 + pivot[idx] - '0';
			idx = (idx + 1) % k;
		}
	}
	cout << ans;
	return 0;
}