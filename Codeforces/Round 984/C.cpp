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
		string s;
		cin >> s;
		int cnt = 0;
		auto check = [&](int a)
			{
				if (a + 3 >= s.size())
				{
					return false;
				}
				return s[a] == '1' && s[a + 1] == '1' && s[a + 2] == '0' && s[a + 3] == '0';
			};
		for (int i = 0; i <= (int)s.size() - 4; ++i)
		{
			if (check(i))
			{
				cnt++;
			}
		}
		int q = 0;
		cin >> q;
		while (q--)
		{
			int a = 0;
			char b;
			cin >> a >> b;
			int st = max(1, a - 3);
			int ed = min(a, (int)s.size() - 3);
			vector<bool>prev;
			vector<int>temp;
			for (int i = st; i <= ed; ++i)
			{
				int pi = i - 1;
				prev.push_back(check(pi));
				temp.push_back(pi);
			}
			s[a - 1] = b;
			for (int i = 0; i < temp.size(); ++i)
			{
				int pi = temp[i];
				bool flag = check(pi);
				if (!prev[i] && flag)
				{
					cnt++;
				}
				else if (prev[i] && !flag)
				{
					cnt--;
				}
			}
			cout << ((cnt > 0) ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}
