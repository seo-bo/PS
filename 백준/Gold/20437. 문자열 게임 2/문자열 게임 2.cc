#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		vector<vector<int>>v(26);
		int ans1 = INT_MAX, ans2 = INT_MIN, k = 0;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); ++i)
		{
			v[str[i] - 'a'].push_back(i);
		}
		cin >> k;
		for (int i = 0; i < 26; ++i)
		{
			char p = 'a' + i;
			if (v[i].size() < k)
			{
				continue;
			}
			int left = 0, right = k - 1;
			while (right < v[i].size())
			{
				ans1 = min(ans1, v[i][right] - v[i][left] + 1);
				ans2 = max(ans2, v[i][right++] - v[i][left++] + 1);
			}
		}
		if (ans1 == INT_MAX || ans2 == INT_MIN)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << ans1 << ' ' << ans2 << '\n';
		}
	}
}