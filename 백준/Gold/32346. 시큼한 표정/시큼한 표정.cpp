#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 역원???
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<ll>fact(4003, 0), inv(4003, 0);
	fact[0] = inv[0] = 1;
	auto power = [&](ll a)
		{
			ll ans = 1;
			a %= MOD;
			ll b = MOD - 2;
			while (b)
			{
				if (b & 1)
				{
					ans = (ans * a) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
			}
			return ans;
		};
	auto cal = [&](int a, int b)
		{
			if (a < 0 || b > a)
			{
				return 0LL;
			}
			return (((fact[a] * inv[b]) % MOD) * inv[a - b]) % MOD;
		};
	for (int i = 1; i <= 2 * n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = power(fact[i]);
	}
	vector<ll>prefix1(n + 1, 0), prefix2(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		prefix1[i] = prefix1[i - 1] + (str[i - 1] != '>');
		prefix2[i] = prefix2[i - 1] + (str[i - 1] != '<');
	}
	ll ans = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		ll temp = n - 2 * i;
		vector<ll>tt(temp + 1, 0);
		for (int j = 0; j <= temp; ++j)
		{
			tt[j] = cal(temp, j);
		}
		for (int j = 0; j <= temp; ++j)
		{
			int right = j + 2 * i - 1;
			if (right >= n)
			{
				break;
			}
			ll p1 = prefix1[j + i] - prefix1[j];
			ll p2 = prefix2[right + 1] - prefix2[j + i];
			if (!p1 && !p2)
			{
				ans = (ans + tt[j]) % MOD;
			}			
		}
	}
	cout << ans;
	return 0;
}