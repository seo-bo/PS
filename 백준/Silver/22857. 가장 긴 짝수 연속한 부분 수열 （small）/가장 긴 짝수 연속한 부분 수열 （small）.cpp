#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int ans = 0;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int cnt = 0, left = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] % 2)
		{
			cnt++;
		}
		while (cnt > k)
		{
			if (v[left] % 2)
			{
				cnt--;
			}
			left++;
		}
		ans = max(ans, i - left + 1 - cnt);
	}
	cout << ans;
	return 0;
}