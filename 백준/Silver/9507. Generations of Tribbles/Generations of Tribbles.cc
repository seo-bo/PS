#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>v(68);
	v[0] = v[1] = 1, v[2] = 2, v[3] = 4;
	for (int i = 4; i <= 67; ++i)
	{
		v[i] = v[i - 1] + v[i - 2] + v[i - 3] + v[i - 4];
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << v[n] << '\n';
	}
	return 0;
}