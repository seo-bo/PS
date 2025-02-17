#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n), cnt(MAX + 1), divisor(MAX + 1);
	for (auto& i : v)
	{
		cin >> i;
		cnt[i]++;
	}
	for (ll i = 1; i <= MAX; ++i)
	{
		for (ll j = i; j <= MAX; j += i)
		{
			divisor[i] += cnt[j];
		}
	}
	vector<vector<ll>>factor(MAX + 1);
	for (ll i = 1; i <= MAX; ++i)
	{
		for (ll j = i; j <= MAX; j += i)
		{
			factor[j].push_back(i);
		}
	}
	for (ll i = 1; i <= MAX; ++i)
	{
		sort(factor[i].rbegin(), factor[i].rend());
	}
	for (auto& i : v)
	{
		ll ans = 0;
		for (auto& j : factor[i])
		{
			if (divisor[j] >= k)
			{
				ans = j;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
