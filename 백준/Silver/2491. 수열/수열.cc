#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int left = 0, right = 0, prev = -1;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] >= prev)
		{
			right++;
			prev = v[i];
		}
		else
		{
			ans = max(ans, right - left);
			left = right;
			right++;
			prev = v[i];
		}
	}
	ans = max(ans, right - left);
	left = 0, right = 0, prev = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] <= prev)
		{
			right++;
			prev = v[i];
		}
		else
		{
			ans = max(ans, right - left);
			left = right;
			right++;
			prev = v[i];
		}
	}
	ans = max(ans, right - left);
	cout << ans;
	return 0;
}