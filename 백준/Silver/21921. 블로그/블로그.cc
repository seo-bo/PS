#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, x = 0;
	cin >> n >> x;
	vector<int>prefix(n + 1, 0);
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	for (int i = 0; i + x <= n; ++i)
	{
		ans.push_back(prefix[i + x] - prefix[i]);
	}
	sort(ans.begin(), ans.end(), [&](const int& a, const int& b)
		{
			return a > b;
		});
	if (!ans[0])
	{
		cout << "SAD";
	}
	else
	{
		int cnt = 1;
		cout << ans[0] << '\n';
		for (int i = 1; i < ans.size(); ++i)
		{
			if (ans[0] != ans[i])
			{
				break;
			}
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}