#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<int>s;
	for (int i = 3; i <= n; i += 2)
	{
		for (int j = 3; i * j <= n; j += 2)
		{
			if (s.find(i * j) == s.end())
			{
				s.insert(i * j);
			}
		}
	}
	cout << s.size() + n - 1 << '\n';
	for (auto& i : s)
	{
		cout << "2 " << i << '\n';
	}
	for (int i = 1; i <= n; i += 2)
	{
		cout << "1 " << i << '\n';
	}
	for (int i = 4; i <= n; i += 2)
	{
		cout << "2 " << i << '\n';
	}
	return 0;
}