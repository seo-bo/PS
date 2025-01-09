#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unordered_map<string, vector<string>>mm;
	int n = 0, m = 0, t = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string team, mem;
		cin >> team >> t;
		for (int j = 0; j < t; ++j)
		{
			cin >> mem;
			mm[mem].push_back(team);
			mm[team].push_back(mem);
		}
	}
	for (auto& i : mm)
	{
		if (!i.second.empty())
		{
			sort(i.second.begin(), i.second.end());
		}
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		int temp = 0;
		cin >> str >> temp;
		for (auto& k : mm[str])
		{
			cout << k << '\n';
		}
	}
	return 0;
}