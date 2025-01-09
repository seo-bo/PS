#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	if (n == 1)
	{
		cout << "A";
		return 0;
	}
	else if (n == 2)
	{
		if (v[0] - v[1] == 0)
		{
			cout << v[0];
		}
		else
		{
			cout << "A";
		}
		return 0;
	}
	int a = 0, b = 0;
	vector<int>p = { v[0] - v[1],v[1] - v[2] };
	if (p[0] != 0)
	{
		a = p[1] / p[0];
	}
	b = v[1] - v[0] * a;
	bool check = true;
	for (int i = 1; i < n; ++i)
	{
		if (v[i] != v[i - 1] * a + b)
		{
			check = false;
		}
	}
	if (!check)
	{
		cout << "B";
		return 0;
	}
	cout << v[n - 1] * a + b;
	return 0;
}