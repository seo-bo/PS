#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int start = 0;
	vector<pair<int, string>>v;
	for (int i = 0; i < n + 1; ++i)
	{
		string a, b;
		cin >> a >> b;
		string temp;
		for (auto& i : a)
		{
			if (i == ':')
			{
				continue;
			}
			temp += i;
		}
		v.push_back(make_pair(stoi(temp), b));
	}
	string st, ttt;
	cin >> st;
	for (auto& i : st)
	{
		if (i == ':')
		{
			continue;
		}
		ttt += i;
	}
	start = stoi(ttt);
	sort(v.begin(), v.end(), [&](const pair<int, string>& a, const pair<int, string>& b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	bool flag = false;
	int cnt = 0;
	for (auto& i : v)
	{
		if (i.second == "teacher")
		{
			flag = true;
			continue;
		}
		if (i.first < start)
		{
			continue;
		}
		if(i.first >= start && flag)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}