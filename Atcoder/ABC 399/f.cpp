#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(void) // a~k,(kCa * (-1)^(k-a) * p[j]^a * p[i]^k-a) 
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = (prefix[i - 1] + v[i]) % MOD;
	}
	auto power = [&](ll base)
		{
			ll exp = MOD - 2, res = 1;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	vector<vector<ll>>temp(n + 1, vector<ll>(k + 1, 0));
	vector<vector<ll>>rev(k + 1, vector<ll>(n + 1, 0));
	vector<ll>ks(k + 1, 1);
	for (int i = 0; i <= n; ++i)
	{
		temp[i][0] = 1;
		for (int j = 1; j <= k; ++j)
		{
			temp[i][j] = (temp[i][j - 1] * prefix[i]) % MOD;
		}
	}
	for (int i = 0; i <= k; ++i)
	{
		rev[i][0] = temp[0][i];
		for (int j = 1; j <= n; ++j)
		{
			rev[i][j] = (rev[i][j - 1] + temp[j][i]) % MOD;
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		ks[i] = ks[i - 1] * (k - i + 1) % MOD * power(i) % MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			ll p = ks[j];
			if ((k - j) & 1)
			{
				p = (p * (MOD - 1)) % MOD;
			}
			p = (p * temp[i][j]) % MOD;
			p = (p * rev[k - j][i - 1]) % MOD;
			ans = (ans + p) % MOD;
		}
	}
	cout << ans;
	return 0;
}
