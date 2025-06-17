#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	bool in = false;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (str == "login")
		{
			in = true;
		}
		if (str == "logout")
		{
			in = false;
		}
		if (str == "private" && !in)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
