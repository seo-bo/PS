#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<char, char> m1 = { {'p', 'q'}, {'q', 'p'},{'b', 'd'}, {'d', 'b'},{'i', 'i'}, {'m', 'm'},{'v', 'v'}, {'w', 'w'},{'l', 'l'}, {'o', 'o'},{'x', 'x'}, {'?','?'} };
	unordered_map<char, char> m2 = { {'p', 'd'}, {'d', 'p'},{'b', 'q'}, {'q', 'b'},{'u', 'n'}, {'n', 'u'},{'s', 's'}, {'z', 'z'},{'l', 'l'}, {'o', 'o'},{'x', 'x'}, {'?','?'} };
	string _;
	cin >> _;
	string str = "?";
	for (auto& i : _)
	{
		str += i;
		str += '?';
	}
	int len = str.size();
	vector<int>prefix(len + 1, 0);
	for (int i = 1; i <= len; ++i)
	{
		prefix[i] = prefix[i - 1] + ((i - 1) % 2);
	}
	int ans = 0;
	auto manacher = [&](unordered_map<char, char> ok)
		{
			int r = 0, p = 0, len = str.size();
			vector<int>v(len, 0);
			for (int i = 0; i < len; ++i)
			{
				if (i <= r)
				{
					v[i] = min(v[2 * p - i], r - i);
				}
				if (i % 2)
				{
					if (ok.find(str[i]) == ok.end() || ok[str[i]] != str[i])
					{
						v[i] = -1;
						continue;
					}
				}
				while (0 <= i - v[i] - 1 && i + v[i] + 1 < len && ok.find(str[i + v[i] + 1]) != ok.end() && ok[str[i + v[i] + 1]] == str[i - v[i] - 1])
				{
					v[i]++;
				}
				if (r < i + v[i])
				{
					r = i + v[i];
					p = i;
				}
			}
			for (int i = 0; i < len; ++i)
			{
				if (v[i] >= 0)
				{
					ans = max(ans, prefix[i + v[i] + 1] - prefix[i - v[i]]);
				}
			}
		};
	manacher(m1);
	manacher(m2);
	if (!ans)
	{
		cout << "NOANSWER";
	}
	else
	{
		cout << ans;
	}
	return 0;
}