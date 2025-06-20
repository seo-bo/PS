#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, maxi = 0;
	cin >> n;
	vector<int>v(5005, 0);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp]++;
	}
	int ans = 0;
	for (int i = 1; i <= 5000; ++i)
	{
		if (!v[i])
		{
			continue;
		}
		v[i]--;
		int b = 0;
		for (int j = 1; j <= 5000; ++j)
		{
			if (!v[j])
			{
				continue;
			}
			if (j % i == 0)
			{
				continue;
			}
			b = gcd(b, j);
		}
		if (!b)
		{
			for (int j = 5000; j >= 1; --j)
			{
				if (v[j])
				{
					b = j;
					break;
				}
			}
		}
		ans = max(ans, i + b);
		v[i]++;
	}
	cout << ans;
	return 0;
}