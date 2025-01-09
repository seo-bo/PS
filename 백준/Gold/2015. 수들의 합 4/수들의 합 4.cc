#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, k = 0, ans = 0;
	cin >> n >> k;
	ll prefix = 0;
	unordered_map<ll, ll>mm;
	mm[0] = 1;
	for (int i = 0; i < n; ++i) // prefix(j) - prefix(i) = k 가 되는 구간갯수?
	{
		ll a = 0;
		cin >> a;
		prefix = prefix + a;
		ans += mm[prefix - k];
		mm[prefix]++;
	}
	cout << ans;
	return 0;
}