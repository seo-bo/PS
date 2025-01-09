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
		ll n = 0;
		cin >> n;
		ll pivot = n - 2;
		map<ll, ll>mm;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			mm[temp]++;
		}
		for (auto& [a, b] : mm)
		{
			if (pivot % a)
			{
				continue;
			}
			ll div = pivot / a;
			if (div == a && b > 1)
			{
				cout << a << ' ' << a << '\n';
				break;
			}
			else if (mm.find(div) != mm.end())
			{
				cout << a << ' ' << div << '\n';
				break;
			}
		}
	}
	return 0;
}
