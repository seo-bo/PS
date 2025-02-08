#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str, temp;
	getline(cin, str);
	stringstream ss(str);
	vector<string>v;
	while (ss >> temp)
	{
		v.push_back(temp);
	}
	int now = 0;
	bool repeat = false;
	int ans = 0, lead = 0;
	vector<vector<string>>sett = { {}, {"no", "hai-", "hai-", "hai", "hai","hai", "hai", "u-", "hai"},
		{"kawaii!"}, {"you", "ready", "antena", "senku", "high!"} };
	vector<string>o_o = { {"u-"}, {"hai"} };
	int idx = 0, sidx = 0, len = v.size(), cycle = 0;
	while (idx < len)
	{
		string pivot = v[idx];
		if (repeat)
		{
			if (pivot == o_o[cycle])
			{
				idx++;
				cycle = (cycle + 1) % 2;
				continue;
			}
			else if (pivot == "se" || pivot == "mik-jjang" || pivot == "Are" || (pivot == "hai" && cycle == 0))
			{
				now = 0;
				cycle = 0;
				repeat = false;
			}
			else
			{
				idx++;
				continue;
			}
		}
		if (now == 1)
		{
			string ab = sett[now][sidx];
			if (pivot == ab) // 같으면 일단 넘겨야함
			{
				if (sidx + 1 == sett[now].size())
				{
					ans++;
					repeat = true;
					sidx = 0;
					idx++;
					continue;
				}
				else
				{
					sidx++;
				}
			}
		}
		if (now == 2)
		{
			string ab = sett[now][sidx];
			if (pivot == ab)
			{
				if (sidx + 1 == sett[now].size())
				{
					ans++;
					now = sidx = 0;
					idx++;
					continue;
				}
				else
				{
					sidx++;
				}
			}
		}
		if (now == 3)
		{
			string ab = sett[now][sidx];
			if (pivot == ab)
			{
				if (sidx + 1 == sett[now].size())
				{
					ans++;
					now = sidx = 0;
					idx++;
					continue;
				}
				else
				{
					sidx++;
				}
			}
		}
		if (now == 0) // 운용중이 아닐때
		{
			if (pivot == "se") // c # 1
			{
				lead++;
				now = 1;
			}
			else if (pivot == "mik-jjang") // c # 2
			{
				lead++;
				now = 2;
			}
			else if (pivot == "Are") // c # 3
			{
				lead++;
				now = 3;
			}
			else if (pivot == "hai") // c # 5
			{
				ans++;
			}
			else if (idx + 1 < len && pivot == "-u" && v[idx + 1] == "hai") // c # 4
			{
				ans++;
				idx += 2;
				continue;
			}
		}
		idx++;
	}
	cout << lead << ' ' << ans;
	return 0;
}