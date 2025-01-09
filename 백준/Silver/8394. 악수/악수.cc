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
	int n = 0, pre0 = 1, pre1 = 0, now0 = 0, now1 = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		now1 = (now1 + pre0) % 10;
		now0 = (now0 + pre0 + pre1) % 10;
		pre0 = now0,pre1 = now1,now0 = now1 = 0;
	}
	cout << (pre0 + pre1) % 10;
	return 0;
}