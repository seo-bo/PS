#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	unordered_map<string, int>mm;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			string str;
			cin >> str;
			mm[str]++;
		}
	}
	int ans = 0;
	for (auto& [_, a] : mm)
	{
		if (a >= m)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
