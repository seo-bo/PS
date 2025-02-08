#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll N = 0, r = 0, c = 0;
	cin >> N >> r >> c;
	N = 1LL << N;
	ll ans = 0;
	function<void(ll, ll, ll)> solve = [&](ll x, ll y, ll n) ->void
		{
			if (n == 1)
			{
				if (x == r && y == c)
				{
					cout << ans;
					exit(0);
				}
				ans++;
				return;
			}
			ll mid = n / 2;
			if (r < x + mid && c < y + mid)
			{
				solve(x, y, mid);
			}
			else
			{
				ans += mid * mid;
			}
			if (r < x + mid && c >= y + mid)
			{
				solve(x, y + mid, mid);
			}
			else
			{
				ans += mid * mid;
			}
			if (r >= x + mid && c < y + mid)
			{
				solve(x + mid, y, mid);
			}
			else
			{
				ans += mid * mid;
			}
			if (r >= x + mid && c >= y + mid)
			{
				solve(x + mid, y + mid, mid);
			}
			else
			{
				ans += mid * mid;
			}
		};
	solve(0, 0, N);
	return 0;
}