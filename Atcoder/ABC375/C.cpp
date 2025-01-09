#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int k = 0; k < n / 2; ++k)
	{
		int p = (k + 1) % 4;
		for (int j = 0; j < p; ++j)
		{
			int a = k, b = n - 1 - k;
			for (int i = 0; i < b - a; ++i)
			{
				char pivot = v[a][a + i];
				v[a][a + i] = v[b - i][a];
				v[b - i][a] = v[b][b - i];
				v[b][b - i] = v[a + i][b];
				v[a + i][b] = pivot;
			}
		}
	}
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}
