#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string>s;
	int n = 0, m = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end())
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}