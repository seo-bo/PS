#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	lb n = 0, x = 0;
	cin >> n >> x;
	lb p = (n * (100.0 - x) / 100);
	lb ans = (100.0 * n / p - 100.0);
	cout << format("{:.10f}", ans);
	return 0;
}