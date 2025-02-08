#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 이거 뭔가 어디서 많이본 재귀?..
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		function<int(int, int, int)> dfs = [&](int left, int right, int check)->int
			{
				while (left < right)
				{
					if (str[left] != str[right])
					{
						if (!check)
						{
							if (!dfs(left + 1, right, 1) || !dfs(left, right - 1, 1))
							{
								return 1;
							}
						}
						return 2;
					}
					left++, right--;
				}
				return 0;
			};
		cout << dfs(0, str.length() - 1, 0) << '\n';
	}
	return 0;
}