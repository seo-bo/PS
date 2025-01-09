#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string str;
	cin >> str;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = str[i] - '0';
	}
	for (int i = 0; i < n - 1 && m; ++i)
	{
		if (v[i])
		{
			int pivot = 10 - v[i];
			if (m < pivot)
			{
				continue;
			}
			m -= pivot;
			v[i] = 0;
		}
	}
	v[n - 1] = (v[n - 1] + m) % 10;
	for(auto & i : v)
	{
		cout << i;
	}
	return 0;
}