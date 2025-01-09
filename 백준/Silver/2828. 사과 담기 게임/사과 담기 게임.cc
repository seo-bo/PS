#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	int J = 0;
	cin >> J;
	vector<int>v(J);
	for (auto& i : v)
	{
		cin >> i;
	}
	int left = 1, right = 1 + m - 1;
	for (auto& i : v)
	{
		if (i < left)
		{
			while (left != i)
			{
				left--;
				right--;
				ans++;
			}
		}
		else if (i > right)
		{
			while (right != i)
			{
				left++;
				right++;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}