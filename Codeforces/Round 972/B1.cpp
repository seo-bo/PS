#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0, q = 0;
		cin >> n >> m >> q;
		vector<ll>b(m);
		for (auto& i : b)
		{
			cin >> i;
		}
		sort(b.begin(), b.end());
		while (q--)
		{
			ll ans = 0, temp = 0;
			cin >> temp;
			auto it = lower_bound(b.begin(), b.end(), temp);
			if (it == b.begin())
			{
				ans = *it - 1;
			}
			else if (it == b.end())
			{
				ans = n - *prev(it);
			}
			else
			{
				ans = (*it - *prev(it)) / 2;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
