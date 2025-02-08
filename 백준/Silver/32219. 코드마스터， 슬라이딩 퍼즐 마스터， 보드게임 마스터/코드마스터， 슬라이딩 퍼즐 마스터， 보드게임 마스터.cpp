#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	while (n--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		ll pivot = (a ^ b);
		bool check = false;
		if (pivot)
		{
			cout << "jinseo" << '\n';
			ll x = a, y = b;
			for (int i = a - 1; i >= 1; --i)
			{
				if (!(i ^ b))
				{
					x = i;
					check = true;
					break;
				}
			}
			if (check)
			{
				cout << x << ' ' << y << '\n';
				continue;
			}
			for (int i = b - 1; i >= 1; --i)
			{
				if (!(i ^ a))
				{
					y = i;
					break;
				}
			}
			cout << x << ' ' << y << '\n';
		}
		else
		{
			cout << "dohoon" << '\n';
		}
	}
	return 0;
}