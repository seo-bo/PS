#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, cnt = 1;
	cin >> n;
	ll ans = 0;
	while (n > (9 * pow(10, cnt - 1)))
	{
		int target = cnt * (9 * pow(10, cnt - 1));
		ans += target;
		n -= (9 * pow(10, cnt - 1));
		cnt++;
	}
	cout << ans + cnt * n;
	return 0;
}