#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, cnt = 0;
	cin >> n;
	string p, s;
	unordered_map<string, vector<string>>m;
	vector<string>ans;
	for (int i = 0; i < n; ++i)
	{
		cin >> p >> s;
		if (s == "-")
		{
			continue;
		}
		m[s].push_back(p);
	}
	for (auto& i : m)
	{
		if (i.second.size() == 2)
		{
			cnt++;
			for (auto& k : i.second)
			{
				ans.push_back(k);
				ans.push_back(" ");
			}
			ans.push_back("\n");
		}
	}
	cout << cnt << "\n";
	for (auto& i : ans)
	{
		cout << i;
	}
	return 0;
}