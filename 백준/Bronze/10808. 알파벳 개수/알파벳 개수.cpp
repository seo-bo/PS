#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(26, 0);
	string str;
	cin >> str;
	for (auto& i : str)
	{
		v[i - 'a']++;
	}
	for (auto& i : v)
	{
		cout << i << ' ';
	}
	return 0;
}