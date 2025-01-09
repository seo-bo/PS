#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0;
	cin >> a;
	if (a > 100000)
	{
		cout << "No";
		return 0;
	}
	cout << ((a % 2024) ? "No" : "Yes");
	return 0;
}
