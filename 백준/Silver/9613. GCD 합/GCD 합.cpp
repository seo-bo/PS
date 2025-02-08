#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n);
		map<int, int>m;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				ans += gcd(v[i], v[j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}