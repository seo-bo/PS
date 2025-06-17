#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>v(n), mm((1 << 18), 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	int right = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		while (right - i <= m && right < n)
		{
			mm[v[right++]]++;
		}
		ll pivot = k ^ v[i];
		mm[v[i]]--;
		ans += mm[pivot];
	}
	cout << ans;
	return 0;
}