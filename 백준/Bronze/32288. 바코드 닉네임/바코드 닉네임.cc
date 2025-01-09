#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	for (auto& i : str)
	{
		if (i == 'I')
		{
			cout << 'i';
		}
		else
		{
			cout << 'L';
		}
	}
	return 0;
}