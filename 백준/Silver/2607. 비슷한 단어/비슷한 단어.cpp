#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>Alpha(28, 0);
	int T = 0, ans = 0, sum = 0;
	string str;
	cin >> T >> str;
	int slen = str.length();
	T--;
	for (auto& i : str)
	{
		Alpha[i - 'A']++;
		sum++;
	}
	while (T--)
	{
		vector<int>a(28, 0);
		int s = 0;
		string temp;
		cin >> temp;
		int tlen = temp.length();
		for (auto& i : temp)
		{
			a[i - 'A']++;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (Alpha[i] != a[i])
			{
				s += abs(Alpha[i] - a[i]);
			}
		}
		if (abs(slen - tlen) <= 1 && s <= 2) // -1,0,1 / 같으면 0, 단어하나 바꾸면 2, 하나 늘리거나 줄이면 -1 , 1
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}