#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class contest
{
public:
	string univer;
	string team;
	int score;
	int penalty;
	bool operator<(const contest& a) const
	{
		if (this->score == a.score)
		{
			return this->penalty < a.penalty;
		}
		return this->score > a.score;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, result = 0;
	cin >> num >> result;
	vector<contest>v(num);
	unordered_map<string, int>m;
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].univer >> v[i].team >> v[i].score >> v[i].penalty;
		m.insert({ v[i].univer,0 });
	}
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < num; ++i)
	{
		if (count == result)
		{
			return 0;
		}
		auto it = m.find(v[i].univer);
		if (it != m.end() && it->second == 0)
		{
			cout << v[i].team << "\n";
			it->second = 1;
			count++;
		}
	}
	return 0;
}