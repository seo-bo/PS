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
		ll n = 0, mina = INT_MAX, minb = INT_MAX;
		cin >> n;
		for (int i = 1; i * i <= n; ++i)
		{
			if (!(n % i))
			{
				int j = n / i;
				if (!((i + j) % 2) && !((j - i) % 2))
				{
					int a = (i + j) / 2;
					int b = (j - i) / 2;
					if (a > 0 && b >= 0)
					{
						if (a < mina || (a == mina && b < minb))
						{
							mina = a;
							minb = b;
						}
					}
				}
			}
		}
		if (mina == INT_MAX)
		{
			cout << "IMPOSSIBLE" << '\n';
		}
		else
		{
			cout << minb << ' ' << mina << '\n';
		}
	}
	return 0;
}