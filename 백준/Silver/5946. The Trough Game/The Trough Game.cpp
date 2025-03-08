#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>v;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		int a = 0;
		cin >> a;
		int temp = 0, cnt = n - 1;
		for (int j = 0; j < n; ++j, --cnt)
		{
			if (str[j] == '1')
			{
				temp += (1 << cnt);
			}
		}
		v.push_back(make_pair(temp, a));
	}
	int ans = -1;
	for (int i = 0; i < (1 << n); ++i)
	{
		bool f = true;
		for (auto& [a, b] : v)
		{
			int t = i & a;
			if (__builtin_popcount(t) != b)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			if (ans == -1)
			{
				ans = i;
			}
			else
			{
				cout << "NOT UNIQUE";
				return 0;
			}
		}
	}
	if (ans == -1)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if ((1 << i) & ans)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
	}
	return 0;
}