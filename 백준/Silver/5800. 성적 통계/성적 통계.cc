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
	for (int z = 1; z <= n; ++z)
	{
		cout << "Class " << z << '\n';
		int k = 0;
		cin >> k;
		vector<int>v(k);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 1; i < k; ++i)
		{
			ans = max(ans, v[i] - v[i - 1]);
		}
		cout << "Max " << v[k - 1] << ", Min " << v[0] << ", Largest gap " << ans << '\n';
	}
	return 0;
}