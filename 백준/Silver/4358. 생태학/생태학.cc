#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<string, double>tree;
int main(void)
{
	double count = 0;
	string get;
	while (getline(cin, get))
	{
		if (tree.find(get) == tree.end())
		{
			tree.insert(make_pair(get, 1.0));
		}
		else
		{
			tree[get] += 1;
		}
		count++;
	}
	vector<pair<string, double>>result(tree.begin(), tree.end());
	sort(result.begin(), result.end(), [](const pair<string, double>& a, const pair<string, double>& b)
		{
			return a.first < b.first;
		});
	for (auto& i : result)
	{
		cout << i.first << " " << fixed << setprecision(4) << (i.second / count) * 100 << "\n";
	}
}