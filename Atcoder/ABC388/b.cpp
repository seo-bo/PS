#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	for (int i = 1; i <= m; ++i)
	{
		int pivot = INT_MIN;
		for (auto& [a, b] : v)
		{
			pivot = max(pivot, a * (b + i));
		}
		cout << pivot << '\n';
	}
	return 0;
}
