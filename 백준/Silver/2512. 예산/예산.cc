#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	int ans = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> m;
	int left = 0, right = *max_element(v.begin(), v.end());
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		for (auto& i : v)
		{
			if (i >= mid)
			{
				sum += mid;
			}
			else
			{
				sum += i;
			}
		}
		if (sum <= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}