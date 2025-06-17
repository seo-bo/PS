#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, C = 0, maxi = 0;
	cin >> n >> C;
	vector<tp>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> b >> a >> c;
		maxi += b;
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for (int i = 0; i <= maxi; ++i)
	{
		int temp = -i * C, now = i;
		for (auto& [_, a, b] : v)
		{
			if (now < a)
			{
				continue;
			}
			now -= a;
			temp += b;
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}