#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	function<void(string)> dfs = [&](string str)
		{
			if (str.size() == n)
			{
				cout << str;
				exit(0);
			}
			for (int i = 1; i <= 3; ++i)
			{
				string p = str;
				p += (i + '0');
				bool check = true;
				int len = p.size();
				for (int i = 1; i <= len / 2; ++i)
				{
					if (p.substr(len - i * 2, i) == p.substr(len - i, i))
					{
						check = false;
						break;
					}
				}
				if (!check)
				{
					continue;
				}
				dfs(p);
			}
		};
	dfs("1");
	return 0;
}