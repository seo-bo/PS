#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		map<ll, vector<ll>>mm;
		for (int i = 0; i < k; ++i)
		{
			ll a = 0, b = 0;
			cin >> a >> b;
			mm[a].push_back(b);
		}
		vector<ll>v;
		for (auto& [a, b] : mm)
		{
			sort(b.rbegin(), b.rend());
			ll sum = 0;
			for (auto& i : b)
			{
				sum += i;
			}
			v.push_back(sum);
		}
		sort(v.rbegin(), v.rend());
		ll ans = 0;
		for (int i = 0; i < min(n, (ll)v.size()); ++i)
		{
			ans += v[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
