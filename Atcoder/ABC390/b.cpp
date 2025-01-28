#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 1; i < n - 1; ++i)
	{
		if (v[i] * v[i] != v[i - 1] * v[i + 1])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
