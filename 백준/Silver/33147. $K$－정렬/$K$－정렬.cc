#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int g = gcd(n, k);
	vector<vector<int>>v(g);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[i % g].push_back(temp);
	}
	for (int i = 0; i < g; ++i)
	{
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < n; ++i)
	{
		if (!binary_search(v[i % g].begin(), v[i % g].end(), i))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}