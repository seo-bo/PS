#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>v = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	vector<int>temp;
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); ++i)
	{
		temp.push_back(v[str1[i] - 'A']);
		temp.push_back(v[str2[i] - 'A']);
	}
	while (temp.size() > 2)
	{
		int idx = 0, siz = temp.size();
		vector<int>tt;
		for (int i = 0; i < siz - 1; ++i)
		{
			tt.push_back((temp[i] + temp[i + 1]) % 10);
		}
		temp = tt;
	}
	if (temp.size() == 1)
	{
		cout << 0 << temp[0];
	}
	else
	{
		cout << temp[0] << temp[1];
	}
	return 0;
}