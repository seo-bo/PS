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
	int n = 0;
	ll a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll j = 0, k = 0;
		cin >> j >> k;
		a += j, b += k;
		cout << a - b << '\n';
	}
	return 0;
}
