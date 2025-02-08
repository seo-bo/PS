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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	while (q--)
	{
		ll x = 0, y = 0;
		cin >> x >> y;
		if (v[--y] < x)
		{
			cout << 0 << '\n';
			continue;
		}
		ll it = upper_bound(v.begin(), v.end(), x, greater<ll>()) - v.begin();
		it = (it > 0) ? it - 1 : it;
		cout << v[y] - x + 1 + max(0LL, it - y) << '\n';
	}
	return 0;
}