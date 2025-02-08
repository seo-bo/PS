#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, c = 0, g = 0;
		cin >> n;
		vector<int>v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		c = g = v[0];
		for (int i = 1; i < n; ++i)
		{
			c = max(v[i], c + v[i]);
			g = max(g, c);
		}
		cout << g << '\n';
	}
	return 0;
}