#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	if (n < 100)
	{
		cout << 100 - n;
	}
	else if (n < 200)
	{
		cout << 200 - n;
	}
	else if (n < 300)
	{
		cout << 300 - n;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
