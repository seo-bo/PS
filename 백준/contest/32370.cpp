#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = 2;
	if (!x1)
	{
		if (x1 == x2)
		{
			if (y1 < y2)
			{
				ans = 1;
			}
			else
			{
				ans = 3;
			}
		}
		else
		{
			ans = 1;
		}
	}
	else if (!y1)
	{
		if (y1 == y2)
		{
			if (x1 < x2)
			{
				ans = 1;
			}
			else
			{
				ans = 3;
			}
		}
		else
		{
			ans = 1;
		}
	}
	cout << ans;
	return 0;
}
