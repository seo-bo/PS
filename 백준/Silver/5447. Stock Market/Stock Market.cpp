#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		ll left = 1, right = 1, res = v[1];
		ll pivot = v[1], l = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (pivot + v[i] < v[i])
			{
				pivot = v[i];
				l = i;
			}
			else
			{
				pivot += v[i];
			}
			if (pivot > res)
			{
				res = pivot;
				left = l, right = i;
			}
		}
		cout << left << ' ' << right << '\n';
	}
	return 0;
}