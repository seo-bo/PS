#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>v(3);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	int h = 0;
	cin >> h;
	int ans = 0;
	for (; ; ++ans)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (ans % v[j].first == 0)
			{
				h -= v[j].second;
			}
		}
		if (h <= 0)
		{
			cout << ans;
			return 0;
		}
	}
	return 0;
}