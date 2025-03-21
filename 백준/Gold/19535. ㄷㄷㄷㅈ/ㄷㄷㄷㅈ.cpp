#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>degree(n + 1, 0);
	vector<pii>v(n - 1);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
	}
	ll p1 = 0, p2 = 0;
	for (auto& [a, b] : v)
	{
		p1 += (degree[a] - 1) * (degree[b] - 1);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] >= 3)
		{
			p2 += degree[i] * (degree[i] - 1) * (degree[i] - 2) / 6;
		}
	}
	if (p1 > 3 * p2)
	{
		cout << 'D';
	}
	else if (p1 < 3 * p2)
	{
		cout << 'G';
	}
	else
	{
		cout << "DUDUDUNGA";
	}
	return 0;
}