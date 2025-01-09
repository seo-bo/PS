#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string a;
	cin >> a;
	int left = 0, right = n - 1;
	int ans = 0;
	while (left < right)
	{
		if (a[left] == '?' && a[right] == '?')
		{
			ans += 26;
		}
		else if ((a[left] == '?' && a[right] != '?') || (a[right] == '?' && a[left] != '?'))
		{
			ans++;
		}
		else if (a[left] != a[right])
		{
			cout << 0;
			return 0;
		}
		left++;
		right--;
	}
	cout << ans;
	return 0;
}