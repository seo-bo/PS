#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (i > 0)
		{
			if (v[i] <= v[i - 1])
			{
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
