#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<int>cnt(3, 0);
	map<char, int>m1 = { {'K',0},{'S',1},{'A',2} };
	map<int, char>m2 = { {0,'K'},{1,'S'},{2,'A'} };
	for (auto& i : str)
	{
		cnt[m1[i]]++;
	}
	int len = 0, idx = 0;
	while (1)
	{
		if (!cnt[idx])
		{
			idx = (idx + 2) % 3;
			break;
		}
		len++;
		cnt[idx]--;
		idx = (idx + 1) % 3;
	}
	int ans = str.size();
	for (int i = ans - 1; i >= 0 && len; --i)
	{
		if (m2[idx] == str[i])
		{
			ans--;
			idx = (idx + 2) % 3;
			len--;
		}
	}
	cout << ans;
	return 0;
}