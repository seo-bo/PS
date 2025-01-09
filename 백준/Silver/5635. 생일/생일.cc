#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Sort
{
	string name;
	int day, month, year;
};
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<Sort>v(n);
	for (auto& i : v)
	{
		cin >> i.name >> i.day >> i.month >> i.year;
	}
	sort(v.begin(), v.end(), [&](const Sort& a, const Sort& b)
		{
			if (a.year == b.year)
			{
				if (a.month == b.month)
				{
					return a.day > b.day;
				}
				return a.month > b.month;
			}
			return a.year > b.year;
		});
	cout << v[0].name << '\n';
	cout << v[n - 1].name;
	return 0;
}