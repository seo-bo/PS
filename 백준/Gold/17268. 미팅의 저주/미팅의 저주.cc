#include <bits/stdc++.h>
#define MOD 987654321
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n / 2 + 1, 0);
	v[0] = 1;
	for (int i = 1; i <= n / 2; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			v[i] = (v[i] + (v[j] * v[i - j - 1]) % MOD) % MOD;
		}
	}
	cout << v[n / 2];
	return 0;
}