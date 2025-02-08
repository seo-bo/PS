#include <bits/stdc++.h>
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
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll ans = 0;
	for (int i = 0; i < (n + 1) / 2; ++i)
	{
		ll left = v[i], right = v[n - i - 1];
		if (left != right)
		{
			ll dif = abs(left - right);
			ll pivot = dif / k, pp = dif % k;
			ll pivot2 = k * (pivot + 1) - dif;
			ans += min(pivot + pp, pivot + 1 + pivot2);
		}
	}
	cout << ans;
	return 0;
}