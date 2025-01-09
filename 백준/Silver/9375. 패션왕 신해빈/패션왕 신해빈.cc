#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		ll ans = 1;
		map<string, int>m;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string str1, str2;
			cin >> str1 >> str2;
			m[str2]++;
		}
		for (auto& i : m)
		{
			ans *= i.second + 1;
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}