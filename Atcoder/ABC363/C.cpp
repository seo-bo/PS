#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n = 0, k = 0;

set<string>ss;
set<string>ans;

bool check(string str)
{
	int siz = str.length();
	for (int i = 0; i < siz / 2; ++i)
	{
		if (str[i] != str[siz - i - 1])
		{
			return false;
		}
	}
	return true;
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n >> k >> s;
	sort(s.begin(), s.end());
	do
	{
		ss.insert(s);
	} while (next_permutation(s.begin(), s.end()));
	int res = 0;
	for (auto str : ss)
	{
		bool flag = true;
		for (int j = 0; j <= str.size() - k; ++j)
		{
			if (check(str.substr(j, k)))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			res++;
		}
	}
	cout << res;
	return 0;
}
