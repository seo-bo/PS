#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, l = 0, r = 0;
	cin >> n >> l >> r;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin() + l, v.begin() + r + 1);
	for (int i = 2; i <= n; ++i)
	{
		if (v[i] < v[i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}