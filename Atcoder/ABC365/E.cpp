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
	int T = 1;
	while (T--)
	{
		ll n = 0, ans = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
			ans -= i;
		}
		for (ll i = 0; i < 30; ++i)
		{
			ll temp = 0;
			bool odd = false;
			for (auto& k : v)
			{
				if (k & (1LL << i))
				{
					odd = !odd;
				}
				if (odd)
				{
					temp++;
				}
			}
			for (ll j = 0; j < n; ++j)
			{
				ans += (1LL << i) * temp;
				if (v[j] & (1LL << i))
				{
					temp = (n - j - temp);
				}
			}
		}
		cout << ans;
	}
	return 0;
}
