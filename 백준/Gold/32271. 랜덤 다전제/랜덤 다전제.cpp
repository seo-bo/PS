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
		ll n = 0, q = 0;
		cin >> n >> q;
		vector<ll>a(2 * (n + 1));
		vector<ll>b(2 * (n + 1));
		string str;
		cin >> str;
		for (int i = 1; i <= n; ++i)
		{
			a[i] = a[i - 1] + (str[i - 1] == 'A');
			b[i] = b[i - 1] + (str[i - 1] == 'B');
		}
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			a[i] = a[i - 1] + (str[i - 1 - n] == 'A');
			b[i] = b[i - 1] + (str[i - 1 - n] == 'B');
		}
		ll ans = 0;
		while (q--)
		{
			ll s = 0, j = 0;
			cin >> s >> j;
			ll st = s - 1, ed = s + j - 1, pivot = (j + 1) / 2;
			if (a[ed] - a[st] >= pivot)
			{
				auto it = lower_bound(a.begin(), a.end(), a[st] + pivot) - a.begin();
				ans += it - st;
			}
			else
			{
				auto it = lower_bound(b.begin(), b.end(), b[st] + pivot) - b.begin();
				ans += it - st;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}