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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		ll ans = 0, temp = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			if (v[i] > temp)
			{
				temp = v[i];
			}
			ans += temp - v[i];
		}
		cout << ans << '\n';
	}
	return 0;
}