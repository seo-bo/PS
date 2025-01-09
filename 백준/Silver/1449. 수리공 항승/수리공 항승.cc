#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, l = 0;
	cin >> n >> l;
	vector<int>v(n);
	vector<bool>visited(1002, false);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& i : v)
	{
		if (!visited[i])
		{
			for (int j = 1; j < i + l; ++j)
			{
				visited[j] = true;
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}