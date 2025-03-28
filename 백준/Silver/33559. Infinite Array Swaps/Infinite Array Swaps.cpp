#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, res = 0;
	cin >> n;
	map<int, int>aa;
	map<int, int>bb;
	vector<int>a, b;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		aa[temp]++;
	}
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		bb[temp]++;
	}
	auto it = aa.begin();
	auto jt = bb.begin();
	while (it != aa.end() && jt != bb.end())
	{
		if (it->first == jt->first)
		{
			while (it->second > 0 && jt->second > 0)
			{
				res++;
				a.push_back(it->first);
				b.push_back(it->first);
				it->second--;
				jt->second--;
			}
			++it;
			++jt;
			continue;
		}
		if (it->first > jt->first)
		{
			++jt;
		}
		else
		{
			++it;
		}
	}
	it = aa.begin(), jt = bb.begin();
	while (it != aa.end())
	{
		while (it->second > 0)
		{
			a.push_back(it->first);
			it->second--;
		}
		++it;
	}
	while (jt != bb.end())
	{
		while (jt->second > 0)
		{
			b.push_back(jt->first);
			jt->second--;
		}
		++jt;
	}
	cout << res << '\n';
	for (auto& i : a)
	{
		cout << i << ' ';
	}
	cout << '\n';
	for (auto& i : b)
	{
		cout << i << ' ';
	}
	return 0;
}