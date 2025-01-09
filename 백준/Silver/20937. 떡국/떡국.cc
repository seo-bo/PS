#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<int, int>mm;
	int n = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		mm[temp]++;
	}
	for (auto& [a, b] : mm)
	{
		ans = max(ans, b);
	}
	cout << ans;
	return 0;
}