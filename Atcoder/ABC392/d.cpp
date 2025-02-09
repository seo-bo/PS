#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pii>>v(n);
	vector<int>p(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		map<int, int>mm;
		for (int j = 0; j < p[i]; ++j)
		{
			int temp = 0;
			cin >> temp;
			mm[temp]++;
		}
		for (auto& [a, b] : mm)
		{
			v[i].push_back(make_pair(a, b));
		}
		cnt++;
	}
	ld ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ld pivot = 0;
			if (v[i].size() <= v[j].size())
			{
				map<int, int> ok;
				for (auto& [a, b] : v[j])
				{
					ok[a] = b;
				}
				for (auto& [a, b] : v[i])
				{
					if (ok.find(a) != ok.end())
					{
						pivot += (ld)b / (ld)p[i] * (ld)ok[a] / (ld)p[j];
					}
				}
			}
			else
			{
				map<int, int>ok;
				for (auto& [a, b] : v[i])
				{
					ok[a] = b;
				}
				for (auto& [a, b] : v[j])
				{
					if (ok.find(a) != ok.end())
					{
						pivot += (ld)ok[a] / (ld)p[i] * (ld)b / (ld)p[j];
					}
				}
			}
			ans = max(ans, pivot);
		}
	}
	cout << fixed << setprecision(12) << ans;
	return 0;
}
