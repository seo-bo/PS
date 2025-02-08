#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	int cnt = 1;
	while (T--)
	{
		string str, ans;
		cin >> str;
		int len = str.size();
		vector<string>v = { "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE" };
		unordered_map<char, int>mm;
		for (auto& i : str)
		{
			mm[i]++;
		}
		function<bool(int, string)> dfs = [&](int depth, string res)
			{
				if (depth == 0)
				{
					ans = res;
					return true;
				}
				for (int i = 0; i <= 9; ++i)
				{
					bool flag = true;
					vector<char>temp;
					for (auto& j : v[i])
					{
						if (mm[j])
						{
							temp.push_back(j);
							mm[j]--;
						}
						else
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						if (dfs(depth - v[i].size(), res + to_string(i)))
						{
							return true;
						}
					}
					for (auto& j : temp)
					{
						mm[j]++;
					}
				}
				return false;
			};
		dfs(len, "");
		sort(ans.begin(), ans.end());
		cout << format("Case #{}: {}\n", cnt++, ans);
	}
	return 0;
}