#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
