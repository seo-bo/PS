#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unordered_map<char, string>mm =
	{{'1',"one"},{'2',"two"},{'3',"three"}, {'4',"four"},{'5',"five"},{'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"},{'0',"zero"}};
	int m = 0, n = 0;
	cin >> m >> n;
	vector<pair<int, string>>v;
	for (int i = m; i <= n; ++i)
	{
		string num = to_string(i);
		string str;
		for (auto& k : num)
		{
			str += mm[k];
		}
		v.push_back(make_pair(i, str));
	}
	sort(v.begin(), v.end(), [&](const pair<int, string>& a, const pair<int, string>& b)
		{
			return a.second < b.second;
		});
	for (int i = 0; i < v.size(); ++i)
	{
		if (!(i % 10) && i)
		{
			cout << '\n';
		}
		cout << v[i].first << ' ';
	}
	return 0;
}