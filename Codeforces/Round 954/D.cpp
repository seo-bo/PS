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
		if (n <= 2)
		{
			if (str[0] == '0')
			{
				cout << str[1] << "\n";
			}
			else
			{
				cout << str << "\n";
			}
			continue;
		}
		ll ans = LLONG_MAX;
		for (int i = 0; i < n - 1; ++i)
		{
			vector<ll>v;
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					v.push_back((str[j] - '0') * 10 + (str[j + 1] - '0'));
					j++;
				}
				else
				{
					v.push_back(str[j] - '0');
				}
			}
			ll temp = v[0];
			for (int j = 1; j < v.size(); ++j)
			{
				if (temp == 0 || temp == 1 || v[j] == 0 || v[j] == 1)
				{
					temp *= v[j];
				}
				else
				{
					temp += v[j];
				}
			}
			ans = min(ans, temp);
		}
		cout << ans << "\n";
	}
	return 0;
}
