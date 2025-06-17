#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 3, 1), prefix(n + 3);
	for (int i = 0; i < k && i <= n; ++i)
	{
		prefix[i + 1] = prefix[i] + v[i];
	}
	for (int i = k; i <= n; ++i)
	{
		v[i] = (prefix[i] - prefix[i - k] + MOD) % MOD;
		prefix[i + 1] = (prefix[i] + v[i] + MOD) % MOD;
	}
	cout << v[n];
	return 0;
}
