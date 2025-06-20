#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	unordered_set<string>ss;
	unordered_map<string, string>mm;
	for (int i = 0; i < n; ++i)
	{
		string str, temp;
		cin >> str;
		temp = str;
		sort(str.begin(), str.end());
		ss.insert(str);
		if (mm.find(str) == mm.end())
		{
			mm[str] = temp;
		}
		else
		{
			mm[str] = min(mm[str], temp);
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		string str, ans = "";
		cin >> str;
		int len = str.size();
		sort(str.begin(), str.end());
		for (int i = 0; i < (1 << len); ++i)
		{
			string temp;
			for (int j = 0; j < len; ++j)
			{
				if (i & (1 << j))
				{
					temp += str[j];
				}
			}
			if (ss.find(temp) != ss.end())
			{
				if ((int)ans.size() < (int)temp.size())
				{
					ans = mm[temp];
				}
				else if ((int)ans.size() == (int)temp.size())
				{
					ans = min(ans, mm[temp]);
				}
			}
		}
		cout << ((ans.empty()) ? "IMPOSSIBLE" : ans) << '\n';
	}
	return 0;
}