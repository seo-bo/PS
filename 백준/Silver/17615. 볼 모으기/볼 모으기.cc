#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = INT_MAX;
	cin >> n;
	cin.ignore();
	string str;
	cin >> str;
	auto check = [&](char A, char B)
		{
			int temp = 0;
			bool check = false;
			for (int i = 0; i < n; ++i)
			{
				if (str[i] == A)
				{
					check = true;
				}
				if (!i)
				{
					continue;
				}
				if (str[i] == B && check)
				{
					temp++;
				}
			}
			ans = min(ans, temp);
			temp = 0;
			check = false;
			for (int i = n - 1; i >= 0; --i)
			{
				if (str[i] == A)
				{
					check = true;
				}
				if (i == n - 1)
				{
					continue;
				}
				if (str[i] == B && check)
				{
					temp++;
				}
			}
			ans = min(ans, temp);
		};
	check('R','B');
	check('B','R');
	cout << ans;
	return 0;
}