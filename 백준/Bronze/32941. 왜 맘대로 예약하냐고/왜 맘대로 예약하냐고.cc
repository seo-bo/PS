#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int t = 0, x = 0, n = 0;
	cin >> t >> x >> n;
	vector<int>v(1005);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int temp = 0;
			cin >> temp;
			v[temp]++;
		}
	}
	if (v[x] == n)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}