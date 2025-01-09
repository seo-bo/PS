#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
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
	lb ans = 0;
	ll x = 0, y = 0;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		ans += sqrt((x - a) * (x - a) + (b - y) * (b - y));
		x = a, y = b;
	}
	ans += sqrt(x * x + y * y);
	cout << fixed << setprecision(15) << ans;
	return 0;
}
