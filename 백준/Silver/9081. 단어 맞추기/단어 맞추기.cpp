#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str, temp;
		cin >> str;
		temp = str;
		sort(temp.begin(), temp.end(), [&](const char& a, const char& b)
			{
				return a > b;
			});
		if (temp == str)
		{
			cout << str << '\n';
		}
		else
		{
			next_permutation(str.begin(), str.end());
			cout << str << '\n';
		}
	}
	return 0;
}