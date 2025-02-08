#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	vector<int>s;
	int cnt = 0, ve = 0;
	vector<int>d(len, -1);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '(')
		{
			s.push_back(i);
		}
		else if (str[i] == ')')
		{
			d[s.back()] = d[i] = ve++;
			cnt++;
			s.pop_back();
		}
	}
	set<string>ans;
	for (int i = 1; i < (1 << cnt); ++i)
	{
		string pivot = "";
		for (int j = 0; j < len; ++j)
		{
			if (d[j] == -1 || !(i & (1 << d[j])))
			{
				pivot += str[j];
			}
		}
		ans.insert(pivot);
	}
	for (auto& i : ans)
	{
		if (i.empty())
		{
			continue;
		}
		cout << i << '\n';
	}
	return 0;
}