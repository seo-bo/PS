#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 1;
	cin >> n;
	vector<int>ok = { 1 };
	while (x < n)
	{
		x <<= 1;
		vector<int>temp;
		for (auto& j : ok)
		{
			temp.push_back(j * 2 - 1);
		}
		for (auto& j : ok)
		{
			temp.push_back(j * 2);
		}
		ok = move(temp);
	}
	if (x != n)
	{
		cout << 0;
		return 0;
	}
	cout << 1 << '\n';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ok[i ^ j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}