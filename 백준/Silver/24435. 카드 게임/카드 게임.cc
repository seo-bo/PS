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
		string s1, s2;
		cin >> s1 >> s2;
		string temp = s1;
		reverse(temp.begin(), temp.end());
		ll pivot = min(stoll(s1), stoll(temp));
		vector<int>v;
		for (auto& i : s2)
		{
			v.push_back(i - '0');
		}
		sort(v.rbegin(), v.rend());
		function<bool(ll, int, int, int)> dfs = [&](ll sum, int depth, int mask, int ed)
			{
				if (depth == ed)
				{
					if (pivot > sum)
					{
						cout << sum << '\n';
						return true;
					}
					return false;
				}
				for (int i = 0; i < n; ++i)
				{
					if ((mask & (1 << i)) == 0)
					{
						if (dfs(sum * 10 + v[i], depth + 1, mask | (1 << i), ed))
						{
							return true;
						}
					}
				}
				return false;
			};
		for (int i = n; i >= 1; --i)
		{
			if (dfs(0, 0, 0, i))
			{
				break;
			}
		}
	}
	return 0;
}