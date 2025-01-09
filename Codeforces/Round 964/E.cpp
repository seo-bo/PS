#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";
#define MOD 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--) // 너무 어렵게 접근했었나??
	{
		ll l = 0, r = 0, ans = 0;
		cin >> l >> r;
		auto g = [&](ll x)->ll
			{
				return log2(l) / log2(3);
			};
		ll temp = g(l);
		ans = (2 * (temp + 1));
		while (l < r)
		{
			ll exp = log2(r) / log2(3);
			ll p3 = pow(3, exp);
			ll cnt = r - max(p3, l + 1);
			ans += (cnt + 1) * (exp + 1);
			r = p3 - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
