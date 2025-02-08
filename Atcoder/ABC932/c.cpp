#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>a(n + 1, 0), b(n + 1, 0), v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		v[b[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << b[a[v[i]]] << ' ';
	}
	return 0;
}
