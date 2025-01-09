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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			cout << ' ';
		}
		for (int j = 1; j <= i; ++j)
		{
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = i; j < n; ++j)
		{
			cout << ' ';
		}
		for (int j = 1; j <= i; ++j)
		{
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}