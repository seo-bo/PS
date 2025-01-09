#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v;
		for (int i = 1; i <= n; ++i)
		{
			v.push_back(2 * i - 1);
		}
		for (auto& i : v)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
