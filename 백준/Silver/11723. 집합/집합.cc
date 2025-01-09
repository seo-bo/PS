#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	int T = 0;
	cin >> T;
	while (T--)
	{
		string temp;
		int x = 0;
		cin >> temp;
		if (temp == "add")
		{
			cin >> x;
			num |= (1 << x);
		}
		else if (temp == "remove")
		{
			cin >> x;
			num &= ~(1 << x);
		}
		else if (temp == "check")
		{
			cin >> x;
			if (num & (1 << x))
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (temp == "toggle")
		{
			cin >> x;
			num ^= (1 << x);
		}
		else if (temp == "all")
		{
			num = (1 << 21) - 1;
		}
		else
		{
			num = 0;
		}
	}
	return 0;
}