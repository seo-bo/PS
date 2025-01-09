#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";
#define MOD 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a1 = 0, a2 = 0, b1 = 0, b2 = 0, ans = 0;
		cin >> a1 >> a2 >> b1 >> b2;
		ll suwin = 0, slwin = 0;
		if (a1 > b1)
		{
			suwin++;
		}
		else if (b1 > a1)
		{
			slwin++;
		}
		if (a2 > b2)
		{
			suwin++;
		}
		else if (b2 > a2)
		{
			slwin++;
		}
		if (suwin > slwin)
		{
			ans++;
		}

		suwin = 0, slwin = 0;
		if (a1 > b2)
		{
			suwin++;
		}
		else if (b2 > a1)
		{
			slwin++;
		}
		if (a2 > b1)
		{
			suwin++;
		}
		else if (b1 > a2)
		{
			slwin++;
		}
		if (suwin > slwin)
		{
			ans++;
		}

		suwin = 0, slwin = 0;
		if (a2 > b1)
		{
			suwin++;
		}
		else if (b1 > a2)
		{
			slwin++;
		}
		if (a1 > b2)
		{
			suwin++;
		}
		else if (b2 > a1)
		{
			slwin++;
		}
		if (suwin > slwin)
		{
			ans++;
		}

		suwin = 0, slwin = 0;
		if (a2 > b2)
		{
			suwin++;
		}
		else if (b2 > a2)
		{
			slwin++;
		}
		if (a1 > b1)
		{
			suwin++;
		}
		else if (b1 > a1)
		{
			slwin++;
		}
		if (suwin > slwin)
		{
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
