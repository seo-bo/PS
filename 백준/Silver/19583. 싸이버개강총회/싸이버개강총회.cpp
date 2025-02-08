#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>time(3);
	unordered_map<string, pair<bool, bool>>log;
	for (int i = 0; i < 3; ++i)
	{
		string str;
		cin >> str;
		int h = stoi(str.substr(0, 2));
		int mi = stoi(str.substr(3));
		time[i] = h * 60 + mi;
	}
	cin.ignore();
	string str;
	while (getline(cin, str))
	{
		if (str.empty())
		{
			continue;
		}
		int pos = str.find(' ');
		string t = str.substr(0, pos);
		string name = str.substr(pos + 1);
		int h = stoi(t.substr(0, 2));
		int mi = stoi(t.substr(3));
		int tt = h * 60 + mi;
		if (tt <= time[0])
		{
			log[name].first = true;
		}
		else if (time[1] <= tt && tt <= time[2])
		{
			log[name].second = true;
		}
	}
	int ans = 0;
	for (auto& i : log)
	{
		if (i.second.first && i.second.second)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}