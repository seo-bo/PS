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
	string s, t;
	cin >> s >> t;
	function<void(string)> dfs = [&](string str)
		{
			if (str.length() == s.length())
			{
				if (str == s)
				{
					cout << 1;
					exit(0);
				}
				return;
			}
			if (str.back() == 'A')
			{
				string temp = str;
				temp.pop_back();
				dfs(temp);
			}
			if (str.front() == 'B')
			{
				string temp = str;
				reverse(temp.begin(), temp.end());
				temp.pop_back();
				dfs(temp);
			}
		};
	dfs(t);
	cout << 0;
	return 0;
}