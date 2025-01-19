#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll q = 0;
	cin >> q;
	vector<ll>prefix(q + 1, 0);
	ll a = 0, b = 0;
	while (q--)
	{
		ll p = 0;
		cin >> p;
		if (p == 1)
		{
			ll temp = 0;
			cin >> temp;
			a++;
			prefix[a] = prefix[a - 1] + temp;
		}
		else if (p == 2)
		{
			b++;
		}
		else
		{
			ll temp = 0;
			cin >> temp;
			cout << prefix[b + temp - 1] - prefix[b] << '\n';
		}
	}
	return 0;
}
