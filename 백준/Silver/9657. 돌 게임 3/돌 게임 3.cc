#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<bool>v(1005, false);
	v[1] = v[3] = v[4] = true;
	for (int i = 5; i <= n; ++i)
	{
		if (!v[i - 1] || !v[i - 3] || !v[i - 4])
		{
			v[i] = true;
		}
	}
	v[n] ? cout << "SK" : cout << "CY";
	return 0;
}