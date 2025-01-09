#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	auto c = [&](ll a, ll b)
		{
			ll cnt = 0;
			for (ll i = a; i <= b; i *= a)
			{
				cnt += b / i;
			}
			return cnt;
		};
	cout << min((c(5, n) - c(5, m) - c(5, n - m)), (c(2, n) - c(2, m) - c(2, n - m)));
	return 0;
}
