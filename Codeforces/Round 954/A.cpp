#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		vector<int>v(3);
		for (int i = 0; i < 3; ++i)
		{
			cin >> v[i];
		}
		int sum = INT_MAX;
		for (int i = 0; i < 3; ++i)
		{
			int temp = abs(v[0] - v[i]) + abs(v[1] - v[i]) + abs(v[2] - v[i]);
			sum = min(sum, temp);
		}
		cout << sum << '\n';
	}
	return 0;
}
