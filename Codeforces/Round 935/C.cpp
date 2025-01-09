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
		string str;
		cin >> str;
		vector<int>suffix(n + 1, 0);
		for (int i = n - 1; i >= 0; --i)
		{
			suffix[i] = suffix[i + 1] + (str[i] == '1');
		}
		ll ans = -1;
		ll dis = (n * 2);
		ll lef = 0;
		for (int i = 0; i <= n; ++i)
		{
			if (lef >= (i + 1) / 2)	
			{
				if (suffix[i] >= (n - i + 1) / 2 && abs(n - 2 * i) < dis)
				{
					dis = abs(n - 2 * i);
					ans = i;
				}
			}
			if (i != n)
			{
				lef += (str[i] == '0');
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
