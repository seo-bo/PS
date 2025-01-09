#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_map<string, int>ss;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		for (int j = 0; j < b; ++j)
		{
			string str;
			cin >> str;
			ss[str]++;
		}
	}
	vector<pair<string, int>>v(ss.begin(), ss.end());
	sort(v.begin(), v.end(), [&](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.second > b.second;
		});
	if (v.size() > 1 && v[0].second == v[1].second)
	{
		cout << -1;
	}
	else
	{
		cout << v[0].first;
	}
	return 0;
}
