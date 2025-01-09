#include <bits/stdc++.h>
#include <unordered_set>
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
	ll a = 0, b = 0, n = 0;
	cin >> a >> b >> n;
	a %= b;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		a *= 10;
		ans = a / b;
		a %= b;
	}
	cout << ans;
	return 0;
}