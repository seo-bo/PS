#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) // 홀수면 mex가 2 * n - 1 ? / 짝수면 mex가 2 * n ?
{
	cin.tie(0)->sync_with_stdio(0);
	int pivot = 0;
	cin >> pivot;
	int n = pivot;
	if (n % 2)
	{
		n--;
	}
	vector<int>R, C;
	int as = 2 * n;
	ll tot = (2 * n - 1) * 2 * n / 2;
	for (int i = 0; i < n / 2; ++i)
	{
		R.push_back(i);
	}
	for (int i = 0; i < n / 2; ++i)
	{
		R.push_back(2 * n - 1 - i);
	}
	for (int i = n / 2; i < 2 * n - n / 2; ++i)
	{
		C.push_back(i);
	}
	vector<pll>row, col;
	for (int i = 0; i < n; ++i)
	{
		row.push_back(make_pair(R[i], i));
		col.push_back(make_pair(C[i], i));
	}
	sort(row.begin(), row.end(), [&](const pll& a, const pll& b)
		{
			return a.first > b.first;
		});
	sort(col.begin(), col.end(), [&](const pll& a, const pll& b)
		{
			return a.first > b.first;
		});
	vector<vector<int>>v(pivot, vector<int>(pivot, 0));
	if (pivot % 2)
	{
		v[pivot - 1][pivot - 1] = as;
	}
	int i = 0, j = 0;
	while (i < n && j < n)
	{
		int temp = min(row[i].first, col[j].first);
		v[row[i].second][col[j].second] = temp;
		row[i].first -= temp;
		col[j].first -= temp;
		if (!row[i].first)
		{
			i++;
		}
		if (!col[j].first)
		{
			j++;
		}
	}
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}