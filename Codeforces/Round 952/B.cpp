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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, ans = 0, sum = 0;
		cin >> n;
		for (int i = 2; i <= n; ++i)
		{
			ll temp = 0;
			for (int j = i; j <= n; j += i)
			{
				temp += j;
			}
			if (temp > sum)
			{
				sum = temp;
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
