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
		ll d = 0, n = 0;
		cin >> d >> n;
		unordered_map<ll, ll>mm;
		mm[0] = 1;
		ll cur = 0, ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			cur = (cur + temp) % d;
			ll pivot = cur % d;
			ans += mm[pivot];
			mm[cur]++;
		}
		cout << ans << '\n';
	}
	return 0;
}