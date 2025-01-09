#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		int a = 1, p = 0;
		while (1)
		{
			if (a % 2)
			{
				p += (2 * a - 1);
				if (p > n)
				{
					cout << "Sakurako" << '\n';
					break;
				}
			}
			else
			{
				p -= (2 * a - 1);
				if (p < -n)
				{
					cout << "Kosuke" << '\n';
					break;
				}
			}
			a++;
		}
	}
	return 0;
}
