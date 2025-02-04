#include <bits/stdc++.h>
#define MOD 1440
using namespace std;
typedef long long ll;
typedef pair<int, int>pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(3);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	int time = v[0].second, idx = 1;
	for (int i = 1; i <= n; ++i)
	{
		int mul = (i - 1) * MOD;
		for (; idx < 3; ++idx)
		{
			int pivot = time + k;
			auto& [a, b] = v[idx];
			if (a + mul > pivot)
			{
				cout << "NO";
				return 0;
			}
			time = min(max(pivot, a + mul), b + mul);
		}
		idx = 0;
	}
	cout << "YES";
	return 0;
}