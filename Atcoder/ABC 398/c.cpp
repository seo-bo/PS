#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, int>mm, rev;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		mm[temp]++;
		rev[temp] = i;
	}
	int pa = -1, pb = -1;
	for (auto& [a, b] : mm)
	{
		if (b == 1 && a > pa)
		{
			pa = a;
			pb = rev[a];
		}
	}
	cout << pb;
	return 0;
}
