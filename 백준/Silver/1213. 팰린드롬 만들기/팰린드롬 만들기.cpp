#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, ans;
	bool check = false;
	cin >> str;
	int siz = str.length();
	ans.resize(siz);
	map<char, int>m;
	sort(str.begin(), str.end());
	for (auto& i : str)
	{
		m[i]++;
	}
	int idx = 0;
	for (auto& i : m)
	{
		if (i.second % 2)
		{
			if (!(siz % 2) || check)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			while (i.second != 1)
			{
				ans[idx] = i.first;
				ans[siz - idx - 1] = i.first;
				i.second -= 2;
				idx++;
			}
			ans[siz / 2] = i.first;
			check = true;
		}
		else
		{
			while (i.second > 0)
			{
				ans[idx] = i.first;
				ans[siz - idx - 1] = i.first;
				i.second -= 2;
				idx++;
			}
		}
	}
	cout << ans;
	return 0;
}