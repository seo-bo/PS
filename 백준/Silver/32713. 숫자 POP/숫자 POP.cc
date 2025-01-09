#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll sc = 1, cnt = k, right = i + 1;
		while (right <= n && cnt >= 0)
		{
			if (v[right] == v[i])
			{
				sc++;
			}
			else
			{
				cnt--;
			}
			right++;
		}
		ans = max(sc, ans);
	}
	cout << ans;
	return 0;
}