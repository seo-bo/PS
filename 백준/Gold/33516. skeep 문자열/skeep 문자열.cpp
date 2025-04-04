#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<char>v1 = { 's','k','e','e','p' };
	vector<char>v2 = { '?','?','?','?','?' };
	vector<char>s;
	auto check = [&]
		{
			if (s.size() < 5)
			{
				return false;
			}
			int len = s.size() - 1;
			for (int i = len, c = 4; i >= len - 4; --i, --c)
			{
				if (s[i] == '?' && c == 0)
				{
					return false;
				}
				if (s[i] == v1[c] || s[i] == v2[c])
				{
					continue;
				}
				return false;
			}
			return true;
		};
	for (auto& i : str)
	{
		while (check())
		{
			ans++;
			for (int j = 0; j < 5; ++j)
			{
				s.pop_back();
			}
			s.push_back('?');
		}
		s.push_back(i);
	}
	while (check())
	{
		ans++;
		for (int j = 0; j < 5; ++j)
		{
			s.pop_back();
		}
		s.push_back('?');
	}
	cout << ans;
	return 0;
}