#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		n -= a;
		n += b;
		ans = max(ans, n);
	}
	cout << ans;
	return 0;
}