#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a < b)
		{
			v[b]++;
		}
		else
		{
			v[a]++;
		}
	}
	string ans;
	for (int i = 2; i <= n; ++i)
	{
		if (v[i] == i - 1)
		{
			ans += 'E';
		}
		else if (!v[i])
		{
			ans += 'N';
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}