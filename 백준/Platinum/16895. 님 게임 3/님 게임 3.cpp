#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll pivot = 0;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
		pivot ^= i;
	}
	int ans = 0;
	if (!pivot)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		ll np = pivot;
		np ^= v[i];
		for (int j = v[i] - 1; j >= 0; --j)
		{
			if (!(np ^ j))
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}