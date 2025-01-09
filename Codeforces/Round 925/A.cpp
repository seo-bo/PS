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
		string ans;
		int n = 0;
		cin >> n;
		for (int i = 1; i <= 26; ++i)
		{
			if (n - i <= 52)
			{
				n -= i;
				ans += 'a' + i - 1;
				break;
			}
		}
		for (int i = 1; i <= 26; ++i)
		{
			if (n - i <= 26)
			{
				n -= i;
				ans += 'a' + i - 1;
				break;
			}
		}
		for (int i = 1; i <= 26; ++i)
		{
			if (n - i == 0)
			{
				n -= i;
				ans += 'a' + i - 1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
