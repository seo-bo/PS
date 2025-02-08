#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a]++, v[b]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == n - 1)
		{
			cout << n - 1;
			return 0;
		}
	}
	cout << n;
	return 0;
}