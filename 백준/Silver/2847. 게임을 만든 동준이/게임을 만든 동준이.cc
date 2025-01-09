#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = 0;
	for (int i = n - 1; i >= 1; --i)
	{
		if (v[i] <= v[i - 1])
		{
			ans += v[i - 1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}
	cout << ans;
	return 0;
}