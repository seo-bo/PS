#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int ans = INT_MAX;
	set<int>s;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		s.insert(temp);
	}
	for (auto& i : s)
	{
		int res = 5;
		for (int k = i; k < i + 5; ++k)
		{
			if (s.find(k) != s.end())
			{
				res--;
			}
		}
		ans = min(res, ans);
	}
	cout << ans;
	return 0;
}