#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) // [1 2 3 4][3 2 1 0] 1 2 3 ......... | [4 5 6 5 4 3] [2 1 0 1 2 3] 4 5 6 .......... 아니 개어렵네
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int w = 0, h = 0, p = 0, q = 0, t = 0;
	cin >> w >> h >> p >> q >> t; // p 주기 2*w , q 주기 2*h? , case #1 : up / case #2 : down?
	if (((p += t) %= (2 * w)) > w) // down
	{
		p = 2 * w - p; // 주기에서 제하기
	}
	if (((q += t) %= (2 * h)) > h) // down
	{
		q = 2 * h - q; // 주기에서 제하기
	}
	cout << p << ' ' << q;
	return 0;
}