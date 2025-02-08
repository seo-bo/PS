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
	ll n = 0, k = 0;
	cin >> n >> k;
	string str;
	for (ll i = 1; i <= n; ++i)
	{
		str += to_string(i);
		ll temp = stoll(str);
		temp %= k;
		str = to_string(temp);
	}
	cout << str;
	return 0;
}