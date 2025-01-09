#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>m;
	for(int i =0; i<4;++i)
	{
		int temp = 0;
		cin >> temp;
		m[temp]++;
	}
	int ans = 0;
	for (auto& [a, b] : m)
	{
		ans += b / 2;
	}
	cout << ans;
	return 0;
}
