#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	map<int, int>mm;
	int ans = INT_MAX, left = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mm.find(v[i]) != mm.end() && mm[v[i]] >= left)
		{
			ans = min(ans, i - mm[v[i]] + 1);
			left = mm[v[i]] + 1;
		}
		mm[v[i]] = i;
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
