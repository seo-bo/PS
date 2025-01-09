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
	ll n = 0;
	cin >> n;
	vector<ll>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	map<ll, ll>p;
	ll ans = 0;
	/* 1 2 2일때 생각
		v1 = 1, pre = 0
		기여도 -> (1 - 0) * (3 - 1 + 1) = 3
		v2 = 2, pre = 0
		기여도 -> (2 - 0) * (3 - 2 + 1) = 4
		v3 = 2, pre = 2
		기여도 -> (3 - 2) * (3 - 3 + 1) = 1
	*/
	for (int i = 1; i <= n; ++i)
	{
		ll pre = p[v[i]];
		ll sum = ((ll)i - pre) * (n - (ll)i + 1LL);
		ans += sum;
		p[v[i]] = i;
	}
	cout << ans;
	return 0;
}
