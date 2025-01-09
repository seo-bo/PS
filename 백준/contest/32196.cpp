#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	ll k = 0, x = 0, y = 0;
	cin >> n >> m >> k >> x >> y;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		v[i] = x * a - y * b;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < m; ++i)
	{
		ans += v[i];
	}
	cout << ans + k * (x + y);
	return 0;
}
