#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		do
		{
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}
	return 0;
}
