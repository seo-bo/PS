#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0, cnt = 0; i < len; ++i, ++cnt)
	{
		if (cnt && cnt % 10 == 0)
		{
			cout << '\n';
		}
		cout << str[i];
	}
	return 0;
}