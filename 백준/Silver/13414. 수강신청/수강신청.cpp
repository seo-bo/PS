#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k = 0, l = 0;
	cin >> k >> l;
	map<string, int>m;
	for (int i = 1; i <= l; ++i)
	{
		string str;
		cin >> str;
		m[str] = i;
	}
	vector<pair<string, int>>v(m.begin(), m.end());
	sort(v.begin(), v.end(), [&](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.second < b.second;
		});
	for (auto& i : v)
	{
		if (!k)
		{
			break;
		}
		cout << i.first << '\n';
		k--;
	}
	return 0;
}