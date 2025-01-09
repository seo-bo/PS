#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 어쩌피, 최단경로는 최소 1(직접), 최대 2(간접) 아님? 1을 무조건 거쳐갈 수 있는걸?
{
	cin.tie(0)->sync_with_stdio(0);
	ll k = 0, n = 0;
	cin >> k >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == k) // 0
		{
			continue;
		}
		ll pivot = gcd(i, k);
		if (pivot == 1 || pivot == 2)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}