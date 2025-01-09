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
		int one = 0, zero = 0, n = 0;
		string str;
		cin >> n >> str;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '1')
			{
				one++;
			}
			else
			{
				zero++;
				while (i < n && str[i] == '0')
				{
					i++;
				}
				if (i != n)
				{
					one++;
				}
			}
		}
		if (zero >= one)
		{
			cout << no << '\n';
		}
		else
		{
			cout << yes << '\n';
		}
	}
	return 0;
}
