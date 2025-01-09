#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<int>prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	for (int i = n; i >= 0; --i)
	{
		int target = prefix[i] - m;
		if (target < 0)
		{
			break;
		}
		if (binary_search(prefix.begin(), prefix.end(), target))
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}