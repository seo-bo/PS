#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<vector<pii>>checker(n + 1);
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			checker[j].push_back(make_pair(str[idx++], i));
		}
	}
	auto check = [&](char a, int num)
		{
			if (a == '+' && num > 0)
			{
				return true;
			}
			if (a == '-' && num < 0)
			{
				return true;
			}
			if (a == '0' && num == 0)
			{
				return true;
			}
			return false;
		};
	vector<int>temp(1, 0), prefix(1, 0);
	function<bool(int)> dfs = [&](int depth)
		{
			if (depth > n)
			{
				for (int i = 1; i <= n; ++i)
				{
					cout << temp[i] << ' ';
				}
				return true;
			}
			for (int i = -10; i <= 10; ++i)
			{
				bool flag = false;
				temp.push_back(i);
				prefix.push_back(prefix.back() + i);
				for (auto& [a, b] : checker[depth])
				{
					if (!check(a, prefix[depth] - prefix[b - 1]))
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					if (dfs(depth + 1))
					{
						return true;
					}
				}
				temp.pop_back();
				prefix.pop_back();
			}
			return false;
		};
	dfs(1);
	return 0;
}