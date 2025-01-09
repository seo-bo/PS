#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>>v;
vector<pair<string, int>>copyv;

bool comp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.first + b.first < b.first + a.first;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string zero;
	int num = 0;
	cin >> num;
	v.resize(num);
	copyv.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].first;
		copyv[i].first = v[i].first;
		v[i].second = i;
		copyv[i].second = i;
	}
	sort(v.begin(), v.end(), comp);
	sort(copyv.begin(), copyv.end(), comp);
	auto it = copyv.begin();
	while (it != copyv.end() && (*it).first[0] == '0')
	{
		zero += (*it).first;
		it = copyv.erase(it);
	}
	if (copyv.empty())
	{
		cout << "INVALID";
		return 0;
	}
	auto minimum = min_element(copyv.begin(), copyv.end(), [&zero](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.first + zero + b.first < b.first + zero + a.first;
		});
	cout << (*minimum).first;
	for (const auto& i : v)
	{
		if (i.second != (*minimum).second)
		{
			cout << i.first;
		}
	}
}