#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int cnt = 0;
	for (auto& i : str)
	{
		if (i == 'a')
		{
			cnt++;
		}
	}
	str += str;
	int left = 0, no = 0, ans = INT_MAX;
	for (int i = 0; i < (int)str.size(); ++i)
	{
		if (i - left == cnt)
		{
			ans = min(ans, no);
			no -= (str[left++] == 'b');
		}
		no += (str[i] == 'b');
	}
	cout << ans;
	return 0;
}