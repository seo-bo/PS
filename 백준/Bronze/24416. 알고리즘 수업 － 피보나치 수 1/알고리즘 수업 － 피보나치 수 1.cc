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
	int n = 0, a1 = 1, a2 = 1;
	cin >> n;
	for (int i = 3; i <= n; ++i)
	{
		int temp = a1 + a2;
		a1 = a2;
		a2 = temp;
	}
	cout << a2 << ' ' << n - 2;
	return 0;
}