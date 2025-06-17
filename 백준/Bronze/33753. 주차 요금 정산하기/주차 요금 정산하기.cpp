#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, t = 0;
	cin >> a >> b >> c >> t;
	int ans = a;
	t = max(0, t - 30);
	ans += (t + b - 1) / b * c;
	cout << ans;
	return 0;
}