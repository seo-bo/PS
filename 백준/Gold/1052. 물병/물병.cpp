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
	ll n = 0, k = 0, ans = 0;
	cin >> n >> k;
	while (__builtin_popcountll(n) > k)
	{
		ll bits = n & -n;
		ans += bits;
		n += bits;
	}
	cout << ans;
	return 0;
}