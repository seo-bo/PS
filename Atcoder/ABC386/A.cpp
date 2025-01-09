#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	for (int i = 0; i < 4; ++i)
	{
		int temp = 0;
		cin >> temp;
		mm[temp]++;
	}
	if (mm.size() == 2)
	{
		vector<int>v;
		for (auto& i : mm)
		{
			v.push_back(i.second);
		}
		sort(v.begin(), v.end());
		if ((v[0] == 2 && v[1] == 2) || (v[0] == 1 && v[1] == 3))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else
	{
		cout << "No";
		return 0;
	}
	return 0;
}
