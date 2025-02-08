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
	int left = 0, right = 0, ans = 1;
	vector<int>f(11, 0);
	auto check = [&]
		{
			int cnt = 0;
			for (auto& i : f)
			{
				if (i)
				{
					cnt++;
				}
			}
			return cnt;
		};
	while (right < n)
	{
		f[v[right]]++;
		while (check() > 2)
		{
			f[v[left]]--;
			left++;
		}
		ans = max(ans, right - left + 1);
		right++;
	}
	cout << ans;
	return 0;
}