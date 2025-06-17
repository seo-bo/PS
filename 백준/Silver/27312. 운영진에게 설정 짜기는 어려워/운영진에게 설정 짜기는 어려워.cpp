#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int m = 0, n = 0, q = 0;
	cin >> m >> n >> q;
	vector<int>ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> ans[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cout << format("? {} {}", i, i) << endl;
		int temp = 0;
		cin >> temp;
		if (ans[i] == temp)
		{
			ans[i]--;
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}