#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	string str;
	cin >> str;
	while (str.length() > 1)
	{
		int sum = 0;
		for (auto& i : str)
		{
			sum += i - '0';
		}
		str = to_string(sum);
		ans++;
	}
	cout << ans << '\n';
	if (str[0] - '0' && !((str[0] - '0') % 3))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}