#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string pivot;
	cin >> pivot;
	int plen = pivot.size();
	int ans = 0;
	auto fail = [&](string str, int len)
		{
			int left = 0;
			vector<int>pattern(len, 0);
			for (int right = 1; right < len; ++right)
			{
				while (left > 0 && str[left] != str[right])
				{
					left = pattern[left - 1];
				}
				if (str[left] == str[right])
				{
					pattern[right] = ++left;
					ans = max(ans, pattern[right]);
				}
			}
			return pattern;
		};

	for (int i = 0; i < plen; ++i)
	{
		string a = pivot.substr(i);
		fail(a, a.size());
	}
	cout << ans;
	return 0;
}