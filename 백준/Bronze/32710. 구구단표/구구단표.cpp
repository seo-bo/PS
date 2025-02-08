#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<int>s;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			s.insert(i);
			s.insert(j);
			s.insert(i * j);
		}
	}
	int n = 0;
	cin >> n;
	cout << (s.find(n) != s.end());
	return 0;
}