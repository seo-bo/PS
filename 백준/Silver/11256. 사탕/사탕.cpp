#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int j = 0, n = 0, ans = 0;
		cin >> j >> n;
		vector<int>v;
		for (int i = 0; i < n; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			v.push_back(a * b);
		}
		sort(v.rbegin(), v.rend());
		for (auto& i : v)
		{
			ans++;
			j -= i;
			if (j <= 0)
			{
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}