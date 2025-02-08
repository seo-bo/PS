#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string a, b;
	for (int i = 0; i < n; ++i)
	{
		char p;
		cin >> p;
		a += p;
	}
	for (int i = 0; i < n; ++i)
	{
		char p;
		cin >> p;
		b += p;
	}
	a += a;
	int cnt = 0;
	vector<int>pattern(n, 0);
	auto fail = [&]
		{
			int left = 0;
			for (int right = 1; right < n; ++right)
			{
				while (left > 0 && b[left] != b[right])
				{
					left = pattern[left - 1];
				}
				if (b[left] == b[right])
				{
					pattern[right] = ++left;
				}
			}
		};
	auto kmp = [&]
		{
			int left = 0;
			for (int right = 0; right < 2 * n - 1; ++right)
			{
				while (left > 0 && b[left] != a[right])
				{
					left = pattern[left - 1];
				}
				if (b[left] == a[right])
				{
					left++;
					if (left == n)
					{
						cnt++;
						left = pattern[left - 1];
					}
				}
			}
		};
	fail();
	kmp();
	int div = gcd(cnt, n);
	cout << cnt / div << '/' << n / div;
	return 0;
}