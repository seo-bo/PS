#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	ll ans = 0;
	auto cal = [&](ll pivot)
		{
			ll res = 1;
			pivot %= MOD;
			ll mod = MOD - 2;
			while (mod)
			{
				if (mod & 1)
				{
					res = (res * pivot) % MOD;
				}
				pivot = (pivot * pivot) % MOD;
				mod >>= 1;
			}
			return res;
		};
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		if (a == 1)
		{
			ans = (ans + b) % MOD;
		}
		else
		{
			ll p = (b * cal(a)) % MOD;
			ans = (ans + p) % MOD;
		}
	}
	cout << ans;
	return 0;
}