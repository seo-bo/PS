#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int  T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		map<int, pii>mm;
		for (int i = 1; i <= 2 * n; ++i)
		{
			int temp = 0;
			cin >> temp;
			if (mm[temp].first == 0)
			{
				mm[temp].first = i;
			}
			else
			{
				mm[temp].second = i;
				if (abs(mm[temp].first - mm[temp].second) == 1)
				{
					mm.erase(temp);
				}
			}
		}
		vector<tp>ok;
		for (auto& [a, b] : mm)
		{
			ok.push_back(make_tuple(b.first, b.second, a));
		}
		sort(ok.begin(), ok.end());
		int ans = 0;
		for (int i = 0; i + 1 < (int)ok.size(); ++i)
		{
			if (abs(get<0>(ok[i]) - get<0>(ok[i + 1])) == 1 && abs(get<1>(ok[i]) - get<1>(ok[i + 1])) == 1)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
