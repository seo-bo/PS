#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll ans = 0;
	vector<ll>prefix(n + 1, 0);
	vector<ll>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		ans += v[i] * (prefix[n] - prefix[i]);
	}
	cout << ans;
	return 0;
}