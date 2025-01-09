#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, a = 0, pa = 0, b = 0, pb = 0;
	cin >> n >> a >> pa >> b >> pb;
	ll pivot = 0, x = 0, y = 0;
	for (ll i = 0; i <= n / pa; ++i)
	{
		ll cost = n - pa * i;
		ll yy = cost / pb;
		ll now = a * i + b * yy;
		if (now > pivot)
		{
			pivot = now;
			x = i;
			y = yy;
		}
	}
	cout << x << ' ' << y;
	return 0;
}