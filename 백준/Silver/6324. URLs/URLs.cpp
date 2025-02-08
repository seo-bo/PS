#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		string str;
		cin >> str;
		vector<string>ans(4);
		vector<string>temp = { "Protocol = ","Host     = ","Port     = ", "Path     = " };
		int idx = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			if (idx == 0 && str[i] == ':')
			{
				i = i + 2;
				idx = 1;
				continue;
			}
			else if (idx == 1)
			{
				if (i == str.length() - 1)
				{
					ans[idx].push_back(str[i]);
					break;
				}
				else if (str[i] == ':')
				{
					idx = 2;
					continue;
				}
				else if (str[i] == '/')
				{
					idx = 3;
					continue;
				}
			}
			else if (idx == 2)
			{
				if (i == str.length() - 1)
				{
					ans[idx].push_back(str[i]);
					break;
				}
				else if (str[i] == '/')
				{
					idx = 3;
					continue;
				}
			}
			ans[idx].push_back(str[i]);
		}
		cout << "URL #" << _ << '\n';
		for (int k = 0; k < 4; ++k)
		{
			cout << temp[k];
			if (ans[k].empty())
			{
				cout << "<default>" << '\n';
			}
			else
			{
				cout << ans[k] << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}