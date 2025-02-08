#include <bits/stdc++.h>
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
	ll a = 0;
	cin >> a;
	if (-32768 <= a && a <= 32767)
	{
		cout << "short";
	}
	else if (INT_MIN <= a && a <= INT_MAX)
	{
		cout << "int";
	}
	else
	{
		cout << "long long";
	}
	return 0;
}