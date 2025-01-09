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
	int T = 1;
	while (T--)
	{
		int Y = 0;
		cin >> Y;
		if (Y % 400 == 0) 
		{
			cout << 366;
		}
		else if (Y % 100 == 0) 
		{
			cout << 365;
		}
		else if (Y % 4 == 0) 
		{
			cout << 366;
		}
		else 
		{
			cout << 365;
		}
	}
	return 0;
}
