#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_set<ll>ss;
	ll ans = 0;
	ll l = 0, r = 0, x = 0;
	cin >> l >> r >> x;
	for (ll i = l; i <= r; ++i)
	{
		ll temp = i | x;
		ss.insert(temp);
		while (ss.find(ans) != ss.end())
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}