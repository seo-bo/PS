#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	int ans = a / b;
	if (2 * (a % b) < b)
	{
		cout << ans;
		return 0;
	}
	cout << ans + 1;
	return 0;
}
