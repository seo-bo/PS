#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dddcccbbbaaa

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	map<char, vector<int>>mm;
	for (int i = 0; i < n; ++i)
	{
		mm[str[i]].push_back(i);
	}
	string A, B;
	int idx = n - 1;
	for (int i = 0; i < n / 2; ++i)
	{
		while (idx >= 0 && str[idx] == '-')
		{
			idx--;
		}
		B += str[idx--];
		mm[B.back()].pop_back();
		if (mm[B.back()].empty())
		{
			mm.erase(B.back());
		}
		auto it = mm.begin();
		int pivot = it->second.back();
		A += it->first;
		str[pivot] = '-';
		it->second.pop_back();
		if (it->second.empty())
		{
			mm.erase(it->first);
		}
	}
	cout << ((A < B) ? "DA" : "NE") << '\n';
	cout << A;
	return 0;
}