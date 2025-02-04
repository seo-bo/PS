#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0, cnt = 0;
	cin >> n;
	string str;
	cin >> str;
	auto sv = [&](char a)
		{
			return (int)(a - 'a');
		};
	int len = str.size();
	vector<int>pivot(30, 0);
	int left = 0, right = 0;
	while (right < len)
	{
		if (pivot[sv(str[right])] == 0)
		{
			cnt++;
		}
		pivot[sv(str[right])]++;
		while (cnt > n && left < right)
		{
			if (--pivot[sv(str[left++])] == 0)
			{
				cnt--;
			}
		}
		if (cnt <= n)
		{
			ans = max(ans, right - left + 1);
		}
		right++;
	}
	cout << ans;
	return 0;
}