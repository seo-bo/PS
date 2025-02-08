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
		int n = 0;
		cin >> n;
		cout << n << ' ';
		vector<int>v(12);
		for (auto& i : v)
		{
			cin >> i;
		}
		int ans = 0;
		for (int i = 1; i < 11; ++i) // 모든수 ㅅㅂ
		{
			if (v[i - 1] >= v[i])
			{
				continue;
			}
			int left = v[i - 1], right = i, mini = v[i];
			while (right + 1 < 12 && mini > left)
			{
				if (v[right + 1] < mini)
				{
					ans++;
				}
				right++;
				mini = min(v[right], mini);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
