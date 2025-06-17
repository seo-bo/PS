#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n >> t;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.begin() + t);
	for (auto& i : v)
	{
		cout << i << ' ';
	}
	return 0;
}