#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, a = 0, b = 0;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
		}
		cout << n - 1 << '\n';
	}
	return 0;
}