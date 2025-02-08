#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pii>v(n + 1);
	v[1] = make_pair(1, 0), v[2] = make_pair(0, 1);
	for (int i = 3; i <= n; ++i)
	{
		v[i] = make_pair(v[i - 2].first + v[i - 1].first, v[i - 2].second + v[i - 1].second);
	}
	int cnt = 1;
	while (1)
	{
		int temp = k;
		temp -= cnt * v[n].first;
		if (!(temp % v[n].second))
		{
			cout << cnt << '\n';
			cout << temp / v[n].second;
			return 0;
		}
		cnt++;
	}
	return 0;
}