#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0;
	cin >> n >> p;
	vector<int>v(100, 0);
	int x = n;
	while (v[x] != 2)
	{
		v[x]++;
		x = (x * n) % p;
	}
	int cnt = 0;
	for (auto& i : v)
	{
		if (i == 2)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}