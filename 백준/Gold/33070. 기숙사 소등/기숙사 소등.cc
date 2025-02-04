#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, cnt = 0, p = 0, ans = 0;
	cin >> n >> k;
	vector<int>v(k);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (!temp)
		{
			cnt++;
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), cnt);
			if (it != v.end() && *it <= p + cnt)
			{
				p++;
			}
			else
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}