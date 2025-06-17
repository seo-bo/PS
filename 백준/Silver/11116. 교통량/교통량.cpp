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
		set<int>l, r;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			l.insert(temp);
		}
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			r.insert(temp);
		}
		int ans = 0;
		for (auto& i : l)
		{
			if (l.find(i + 500) != l.end() && r.find(i + 1000) != r.end() && r.find(i + 1500) != r.end())
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}