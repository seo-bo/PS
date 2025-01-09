#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int>ans;
	int tlen = t.size(), plen = p.size();
	vector<int>pattern(plen, 0);
	auto fail = [&]
		{
			int left = 0;
			for (int right = 1; right < plen; ++right)
			{
				while (left > 0 && p[left] != p[right])
				{
					left = pattern[left - 1];
				}
				if (p[left] == p[right])
				{
					pattern[right] = ++left;
				}
			}
		};
	auto kmp = [&]
		{
			int left = 0;
			for (int right = 0; right < tlen; ++right)
			{
				while (left > 0 && t[right] != p[left])
				{
					left = pattern[left - 1];
				}
				if (t[right] == p[left])
				{
					left++;
					if (left == plen)
					{
						ans.push_back(right - plen + 2);
						left = pattern[left - 1];
					}
				}
			}
		};
	fail();
	kmp();
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}