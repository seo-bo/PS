#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	vector<string>print = { ", ", "]\n" };
	for (int _ = 1; _ <= T; ++_)
	{
		vector<char>ans;
		map<pair<char, char>, char>cb;
		int a = 0;
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			string temp;
			cin >> temp;
			cb[make_pair(temp[0], temp[1])] = temp[2];
			cb[make_pair(temp[1], temp[0])] = temp[2];
		}
		set<pair<char, char>>ban;
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			string temp;
			cin >> temp;
			ban.insert(make_pair(temp[0], temp[1]));
			ban.insert(make_pair(temp[1], temp[0]));
		}
		cin >> a;
		string str;
		cin >> str;
		for (auto& i : str)
		{
			ans.push_back(i);
			while (ans.size() > 1)
			{
				char aa = ans[ans.size() - 1], bb = ans[ans.size() - 2];
				char pivot;
				if (cb.find(make_pair(aa, bb)) != cb.end())
				{
					pivot = cb[make_pair(aa, bb)];
					ans.pop_back();
					ans.pop_back();
					ans.push_back(pivot);
				}
				else
				{
					break;
				}
			}
			int len = ans.size();
			bool flag = false;
			for (int i = 0; i < len; ++i)
			{
				if (flag)
				{
					ans.clear();
					break;
				}
				for (int j = i + 1; j < len; ++j)
				{
					if (ban.find(make_pair(ans[i], ans[j])) != ban.end())
					{
						flag = true;
						break;
					}
				}
			}
		}
		cout << "Case #" << _ << ": [";
		int len = ans.size();
		for (int i = 0; i < len; ++i)
		{
			cout << ans[i];
			if (i != len - 1)
			{
				cout << print[0];
			}
		}
		cout << print[1];
	}
	return 0;
}