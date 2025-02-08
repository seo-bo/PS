#include <bits/stdc++.h>
using namespace std;

int main(void) // 오..? 개신기..
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	vector<int>pattern(n, 0);
	auto fail = [&]
		{
			int left = 0;
			for (int right = 1; right < n; ++right)
			{
				while (left > 0 && str[left] != str[right])
				{
					left = pattern[left - 1];
				}
				if (str[left] == str[right])
				{
					pattern[right] = ++left;
				}
			}
		};
	fail();
	cout << n - pattern[n - 1];
	return 0;
}