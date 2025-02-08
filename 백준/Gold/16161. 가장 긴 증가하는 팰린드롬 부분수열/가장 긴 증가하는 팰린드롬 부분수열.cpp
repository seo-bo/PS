#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 3, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int left = 1, right = 1;
	auto check = [&](int l, int a, int b, int r)
		{
			int cnt = 2;
			if (a == b)
			{
				cnt--;
			}
			int i = a - 1, j = b + 1;
			while (i >= l && j <= r)
			{
				if (v[i] == v[j])
				{
					cnt += 2;
				}
				else
				{
					break;
				}
				i--;
				j++;
			}
			return cnt;
		};
	int ans = 1;
	while (right <= n)
	{
		if (v[right] < v[right + 1])
		{
			right++;
			continue;
		}
		if (v[right] > v[right + 1])
		{
			int len = right - left;
			int l = left, r = right + len;
			ans = max(ans, check(max(1, l), right, right, min(r, n)));
		}
		else if (v[right] == v[right + 1])
		{
			int len = right - left + 1;
			int l = left, r = right + len;
			ans = max(ans, check(max(1, l), right, right + 1, min(r, n)));
		}
		left = right = right + 1;
	}
	cout << ans;
	return 0;
}