#include <bits/stdc++.h>
using namespace std;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	lb ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += (lb)n / (lb)i;
	}
	cout << format("{:.13f}", ans);
	return 0;
}