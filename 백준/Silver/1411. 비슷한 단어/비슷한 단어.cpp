#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 순서 그대로?
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	map<string, int>mm;
	for (auto& i : v)
	{
		vector<int>ok(30, -1);
		int cnt = 0;
		string tt;
		for (auto& j : i)
		{
			if (ok[j - 'a'] == -1)
			{
				ok[j - 'a'] = cnt++;
			}
			tt += (char)(ok[j - 'a'] + '0');
		}
		mm[tt]++;
	}
	int ans = 0;
	for (auto& [a, b] : mm)
	{
		ans += b * (b - 1) / 2;
	}
	cout << ans;
	return 0;
}