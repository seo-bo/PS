#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m;
	vector<vector<ll>>A(n, vector<ll>(m, 0));
	for (auto& i : A)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	cin >> m >> k;
	vector<vector<ll>>B(m, vector<ll>(k, 0));
	for (auto& i : B)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			ll sum = 0;
			for (int z = 0; z < m; ++z)
			{
				sum += A[i][z] * B[z][j];
			}
			cout << sum << " ";
		}
		cout << '\n';
	}
	return 0;
}